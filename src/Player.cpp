#include "Implementation/Player.h"
#include "GameLoop.h"
#include "Implementation/Box.h"

    

    Player::Player(int speed, int x, int y, int w, int h) : PlayableSprite(speed, x, y, w, h)
    {
        moveSpeed = speed;
        texture = IMG_LoadTexture(GameEngine::sys.getRen(), imgPath.c_str());
        
    }

    Player::~Player()
    {
        SDL_DestroyTexture(texture);
       
    }

    void Player::draw() const
    {
        const SDL_Rect &rect = getRect();
        SDL_RenderCopy(GameEngine::sys.getRen(), texture, NULL, &rect);
    }

    //To add a new keydown-event: Create a new method and call it under a case for the key to be handled
    void Player::handleKeyDownEvent(int i)
    {
        switch (i)
        {

        case KEY_D:
            moveRight();
            break;
        case KEY_A:
            moveLeft();
            break;
        }
    }

    void Player::handleMouseDownEvent(int x, int y, int button, GameEngine::GameLoop* loop){
        // Spawns a bullet on players head
        switch(button){
            case 1: loop->add(Bullet::getInstance(8, (XPos() + getWidth() / 2), YPos(), 15, 15, x, y));
            break;
        }
        
    }



    void Player::moveRight()
    {
        // Checks for collision with walls
        if (XPos() + getWidth() >= GameEngine::sys.getWidth())
        {
            XPos() = GameEngine::sys.getWidth() - this->getWidth();
        }

        else
        {
            XPos() = XPos() + moveSpeed;
        }
    }

    void Player::moveLeft()
    {

        if (XPos() <= 0)
        {
            XPos() = 0;
        }
        else
        {
            XPos() = XPos() - moveSpeed;
        }
    }

    void Player::tick(GameEngine::GameLoop *loop)
    {
        handleSpriteCollision(loop->collision(this), loop);
    }

    void Player::handleSpriteCollision(GameEngine::Sprite* other, GameEngine::GameLoop* loop){
        if(other != NULL)
        {
            if(Box* box = dynamic_cast<Box*>(other)){
               (void)box;
               loop->queueForRemoval(this);
            }
        }
    }

    // Returns a pointer to a PlayerClass-object. Takes position, dimensions and path to texture as args;
    Player *Player::getInstance(int d, int x, int y, int w, int h)
    {
        return new Player(d, x, y, w, h);
    }


