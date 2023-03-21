
#include "Implementation/Box.h"

Box::Box(int speed, int x, int y, int w, int h) : MovableSprite(speed, x, y, w, h)
{
    
    moveSpeed = speed;
    xVelocity = speed;
    yVelocity = speed;
    texture = IMG_LoadTexture(GameEngine::sys.getRen(), imgPath.c_str());
    isRemoved = false;
    
}
Box::~Box()
{
    SDL_DestroyTexture(texture);
   
}

Box *Box::getInstance(int s, int x, int y, int w, int h)
{
    return new Box(s, x, y, w, h);
}

//Handles collision with other sprites
void Box::handleSpriteCollision(Sprite *other, GameEngine::GameLoop *loop)
{
    if (other != NULL)
    {
        // Removes Box from game if collided with bullet.
        if (Bullet *bullet = dynamic_cast<Bullet *>(other))
        {
            (void)bullet;
            loop->queueForRemoval(this);
            isRemoved = true;
        }

        if (GameEngine::PlayableSprite *player = dynamic_cast<GameEngine::PlayableSprite *>(other))
        {
            (void)player;
            loop->queueForRemoval(this);
            
        }

        // If two boxes collide their x- and y-velocities will be inverted in order to simulate a "bounce" effect.
        if (Box *box = dynamic_cast<Box *>(other))
        {

            //Boxes collide top-bottom
            if (this->YPos() < box->YPos())
            {
                this->YPos() = this->YPos() - 2;
                this->invertY();
                return;
            }

            else if (this->YPos() > box->YPos())
            {
                this->YPos() = this->YPos() + 2;
                this->invertY();
                return;
            }

            //Side-side
            else if (this->XPos() < box->XPos())
            {
                this->XPos() = this->XPos() - 2;
                this->invertX();
                return;
            }
            else if (this->XPos() > box->XPos())
            {
                this->XPos() = this->XPos() + 2;
                this->invertX();
                return;
            }
        }
    }
}

void Box::tick(GameEngine::GameLoop *loop)
{

    XPos() += xVelocity;
    YPos() += yVelocity;
    handleWallCollision();
    handleSpriteCollision(loop->collision(this), loop);

    // Increases score if box has been removed
    if(isRemoved){
        for(Sprite* s : loop->getSprites()){
            if(ScoreBoard* sb = dynamic_cast<ScoreBoard*>(s)){
                sb->increaseScore();
            }
        }
    }
   
}

//Draws box to screen
void Box::draw() const
{
    const SDL_Rect &rect = getRect();
    SDL_RenderCopy(GameEngine::sys.getRen(), texture, NULL, &rect);
}

// Checks if Box has hit wall and inverts velocity if it has.
void Box::handleWallCollision()
{
    // left wall
    if (XPos() <= 0)
    {
        XPos()++;
        invertX();
    }
    //right wall
    if (XPos() + getWidth() >= GameEngine::sys.getWidth())
    {
        XPos()--;
        invertX();
    }
    //roof
    if (YPos() <= 0)
    {
        YPos()++;
        invertY();
    }
    //floor
    if (YPos() + getHeight() >= GameEngine::sys.getHeight())
    {
        YPos()--;
        invertY();
    }
}

void Box::invertX()
{
    xVelocity = -1 * xVelocity;
}

void Box::invertY()
{
    yVelocity = -1 * yVelocity;
}
