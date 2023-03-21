#ifndef MOVABLESPRITE_H
#define MOVABLESPRITE_H
#include "Sprites/Sprite.h"
#include <iostream>

#include <string>

namespace GameEngine
{
    class MovableSprite : public Sprite
    {

    public:
        virtual ~MovableSprite(){};

        int &getMoveSpeed()
        {
            return moveSpeed;
        }




    protected:
        int moveSpeed;
        MovableSprite(int speed, int x, int y, int w, int h) : Sprite(x, y, w, h){};

    private:
    MovableSprite(const MovableSprite&) = delete;
    const MovableSprite& operator=(const MovableSprite&) = delete;
    
    };

} // namespace GameEngine

#endif