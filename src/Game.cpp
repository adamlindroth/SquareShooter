#include "Game.h"
#include "System.h"




namespace GameEngine

{
    
    Game::Game(std:: string t, int width, int height){
        title = t;
        sys.setTitle(&title);
        sys.setWindowSize(width, height);
        loop = GameLoop();
        
    }


    Game::~Game(){

    }

    void Game::addSprite(Sprite* s){
        loop.add(s);
    }

    void Game::addManipulator(WorldManipulator* m){
        loop.addManipulator(m);
    }


    void Game::run(){
        loop.run();
    }

    void Game::setFps(int i){
        loop.setFPS(i);
    }

    void Game::addBackground(std::string path){
        loop.addBackground(path);
    }





}