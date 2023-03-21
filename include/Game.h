#ifndef GAME_H
#define GAME_H
#include "GameLoop.h"
#include "Sprites/Sprite.h"
#include <string>
#include <memory>
#include <iostream>
#include <WorldManipulator.h>


namespace GameEngine
{
    

    class Game
    {
    public:
        Game(std::string, int, int);
        ~Game();
        void addSprite(Sprite *);
        void addBackground(std::string path);
        void run();
        void setFps(int i);
        void addManipulator(WorldManipulator* m);
        


    private:
        std::string title;
        GameLoop loop;
    };

 
}

#endif