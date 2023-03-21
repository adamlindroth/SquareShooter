#include "Implementation/ScoreBoard.h"
#include <iostream>

ScoreBoard::ScoreBoard(int x, int y, int w, int h) : ImmovableSprite(x, y, w, h)
{
    score = 0;
    text = "Score " + std::to_string(score);
    updateSurface();
    
    updateTexture();
    
    SDL_FreeSurface(surface);
    
}

ScoreBoard::~ScoreBoard()
{
    SDL_DestroyTexture(texture);
}

void ScoreBoard::tick(GameEngine::GameLoop *loop)
{
}

void ScoreBoard::draw() const
{

    const SDL_Rect &rect = getRect();
    SDL_RenderCopy(GameEngine::sys.getRen(), texture, NULL, &rect);
}

void ScoreBoard::increaseScore()
{
    score += 10;
    updateText();
    updateSurface();
    updateTexture();
    SDL_FreeSurface(surface);
}

void ScoreBoard::decreaseScore()
{
    if (score > 0)
    {
        score -= 1;
        updateText();
        updateSurface();
        updateTexture();
        SDL_FreeSurface(surface);
    }
}

// Updates the texture to display the new score
void ScoreBoard::updateTexture()
{
    
    
    texture = SDL_CreateTextureFromSurface(GameEngine::sys.getRen(), surface);
}

//Create surface with the new score
void ScoreBoard::updateSurface()
{
    surface = TTF_RenderText_Solid(GameEngine::sys.getFont(), text.c_str(), {0, 0, 0});
}

// sets text according to the new score
void ScoreBoard::updateText()
{
    text = "Score " + std::to_string(score);
}

int ScoreBoard::getScore()
{
    return score;
}

ScoreBoard *ScoreBoard::getInstance(int x, int y, int w, int h)
{
    return new ScoreBoard(x, y, w, h);
}
