#include "Game.h"
#include "Implementation/Player.h"
#include "Implementation/Bullet.h"
#include "Implementation/Box.h"
#include "Implementation/ScoreBoard.h"
#include "SDL2/SDL.h"
#include "Implementation/BoxSpawner.h"


std::string resPath = "../../resources/";

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800
#define PLAYER_MOVESPEED 6
#define PLAYER_XPOS 10
#define PLAYER_YPOS 625
#define PLAYER_HEIGHT 175
#define PLAYER_WIDTH 50
#define SPAWN_INTERVAL_IN_SECONDS 10
#define SCOREBOARD_XPOS 0
#define SCOREBOARD_YPOS 0
#define SCOREBOARD_WIDTH 100
#define SCOREBOARD_HEIGHT 50




using namespace GameEngine;
int main(int argc, char **argv)
{   
    Game game = Game("Box Shooter", SCREEN_WIDTH, SCREEN_HEIGHT);
    std::cerr << "Game initialized" << std::endl;
    ScoreBoard* scoreboard = ScoreBoard::getInstance(SCOREBOARD_XPOS, SCOREBOARD_YPOS, 
                                                       SCOREBOARD_WIDTH, SCOREBOARD_HEIGHT);
    

    Player* player = Player::getInstance(PLAYER_MOVESPEED, PLAYER_XPOS, PLAYER_YPOS,
                                                         PLAYER_WIDTH, PLAYER_HEIGHT);
                                                         
    BoxSpawner* spawner = new BoxSpawner(SPAWN_INTERVAL_IN_SECONDS);
    std::string backgroundPath = "../../resources/images/Background.png";

    game.setFps(120);
    
    
    
    // Adds Player to game
    game.addBackground(backgroundPath);

    

    //Adds Scoreboard to game
    game.addSprite(player);
    //Adds boxspawner to game
    game.addManipulator(spawner);
    game.addSprite(scoreboard);


    //Starts gameloop

    game.run();
    
    delete spawner;
    return 0;
};