#ifndef PLAYER_H
#define PLAYER_H
#include "Sprites/PlayableSprite.h"
extern std::string resPath;
class Player : public GameEngine::PlayableSprite
{
public:
    ~Player();
    void draw() const;
    void tick(GameEngine::GameLoop *);
    void moveRight();
    void moveLeft();
    static Player *getInstance(int distance, int x, int y, int w, int h);
    void handleKeyDownEvent(int key);
    void handleMouseDownEvent(int x, int y, int button, GameEngine::GameLoop *loop);

private:
    Player(int d, int x, int y, int w, int h);
    void handleSpriteCollision(Sprite *other, GameEngine::GameLoop *loop);
    const std::string imgPath = resPath + "images/Player.png";
    SDL_Texture *texture;
};

#endif