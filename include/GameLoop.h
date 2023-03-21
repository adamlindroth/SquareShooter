#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <vector>
#include <SDL2/SDL.h>
#include "System.h"
#include "Sprites/PlayableSprite.h"
#include "WorldManipulator.h"





namespace GameEngine
{
    
    // Forward declaration of sprite-class
    class Sprite;
    class GameLoop
    {

    public:
        GameLoop();
        void add(Sprite *s);
        void addManipulator(WorldManipulator* m);
        void remove();
        void run();
        ~GameLoop();
        void setFPS(int i);
        void queueForRemoval(Sprite *s);
        Sprite *collision(Sprite *sprite);
        std::vector<Sprite*>& getSprites();
        void addBackground(std::string path);
       


       

        



    private:
        SDL_Texture* background;
        bool quit;
        int fps;
        std::vector<Sprite *> sprites;
        std::vector<Sprite *> added;
        std::vector<Sprite *> removed;
        std::vector<PlayableSprite*> players;
        std::vector<WorldManipulator*> manipulators;
        
        
        
        
       
    

        void handleEvents();
        void update();
        void draw();
        void drawBackground();
        void delay(float);
    };
}

#endif