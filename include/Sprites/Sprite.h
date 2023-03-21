#ifndef SPRITE_H
#define SPRITE_H
#include <SDL2/SDL.h> 
#include "System.h"

#include <vector>





namespace GameEngine
{
    class GameLoop;
    
    class Sprite{


        public:
  
        virtual ~Sprite(){};
        virtual void draw() const = 0;
        virtual void tick(GameLoop*) = 0;
        SDL_Rect getRect() const {return rect;}
        int& XPos() {return rect.x;};
        int& YPos() {return rect.y;};
        int& getWidth() {return rect.w;};
        int& getHeight() {return rect.h;};
        


        



        protected:
        Sprite(int x, int y , int w, int h) : rect{x,y,w,h,} {}


        private:

        std::string imgPath;
        SDL_Rect rect;
        Sprite(const Sprite&) = delete;
        const Sprite& operator=(const Sprite&) = delete;


    };
}


#endif 