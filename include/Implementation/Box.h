#ifndef BOX_H
#define BOX_H
#include "Sprites/MovableSprite.h"
#include "GameLoop.h"
#include "Implementation/Bullet.h"

extern std::string resPath;


class Box : public GameEngine::MovableSprite
{
 

public:
    ~Box();
    void draw() const;
    void tick(GameEngine::GameLoop *);
    static Box *getInstance(int speed, int x, int y, int w, int h);

private:
    Box(int speed, int x, int y, int w, int h);
    
    int yVelocity, xVelocity;
    void handleWallCollision();
    void handleSpriteCollision(Sprite *other, GameEngine::GameLoop *loop);
    void invertY();
    void invertX();
    const std::string imgPath = resPath + "images/Box.png";
    bool isRemoved;
    SDL_Texture *texture;
    
};

#endif