#ifndef IMMOVABLESPRITE_H
#define IMMOVABLESPRITE_H
#include <string>
#include "Sprites/Sprite.h"


namespace GameEngine
{
    class ImmovableSprite : public Sprite
    {
        public:
        virtual ~ImmovableSprite(){};



        protected:
        ImmovableSprite(int x, int y, int w, int h) :
            Sprite(x, y, w, h){}

        private:
        ImmovableSprite(const ImmovableSprite&) = delete;
        const ImmovableSprite& operator=(const ImmovableSprite&) = delete;
        


    };
}



#endif
