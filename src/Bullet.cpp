#include "Implementation/Bullet.h"
#include "GameLoop.h"
#include "Implementation/Box.h"

Bullet::~Bullet()
{
    SDL_DestroyTexture(texture);
}

Bullet::Bullet(int speed, int x, int y, int w, int h, int mouseX, int mouseY) : MovableSprite(speed, x, y, w, h),
                                                                                vec(mouseX - x, mouseY - y) //vector between Bullet and mouse
{
    moveSpeed = speed;
    texture = IMG_LoadTexture(GameEngine::sys.getRen(), imgPath.c_str());
    hasMissed = false;
}

Bullet *Bullet::getInstance(int d, int x, int y, int w, int h, int mouseX, int mouseY)
{
    return new Bullet(d, x, y, w, h, mouseX, mouseY);
}

void Bullet::tick(GameEngine::GameLoop *loop)
{
    handleSpriteCollision(loop->collision(this), loop);
    //Removes bullet if its position is outside of window boundaries
    if (XPos() < 0 || XPos() > GameEngine::sys.getWidth() || YPos() - getHeight() < 0 || YPos() + getHeight() > GameEngine::sys.getHeight())
    {
        loop->queueForRemoval(this);
        //Marks bullet as missed
        hasMissed = true;
    }

    else
    {
        XPos() += vec.normalizeX() * moveSpeed;
        YPos() += vec.normalizeY() * moveSpeed;
    }

    //Decreases score by one if bullet didnt hit any box.
    if (hasMissed)
    {
        for (Sprite *s : loop->getSprites())
        {
            if (ScoreBoard *sb = dynamic_cast<ScoreBoard *>(s))
            {
                sb->decreaseScore();
            }
        }
    }
}
void Bullet::handleSpriteCollision(Sprite *other, GameEngine::GameLoop *loop)
{

    if (Box *box = dynamic_cast<Box *>(other))
    {
        (void)box;
        loop->queueForRemoval(this);
    }
}

void Bullet::draw() const
{
    const SDL_Rect &rect = getRect();
    SDL_RenderCopy(GameEngine::sys.getRen(), texture, NULL, &rect);
}

int Bullet::getMouseX() const
{
    return mouseXPos;
}
int Bullet::getMouseY() const
{
    return mouseYPos;
}
