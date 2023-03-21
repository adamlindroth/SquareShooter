#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include "Sprites/ImmovableSprite.h"
extern std::string resPath;
class ScoreBoard : public GameEngine::ImmovableSprite
{
    public:
    
    static ScoreBoard* getInstance(int x, int y, int w, int h);
    ~ScoreBoard();
    void draw() const;
    void tick(GameEngine::GameLoop* loop);
    void setText(std::string txt);
    void increaseScore();
    void decreaseScore();
    int getScore();
    void updateText();
    void updateTexture();
    void updateSurface();
    
    

    protected:
    ScoreBoard(int x, int y, int w, int h);
    private:
    std::string text;
    int score;
    SDL_Texture* texture;
    SDL_Texture* scoreTexture;
    SDL_Surface* surface;
    SDL_Surface* scoreSurface;
    
    


    private:

};



#endif