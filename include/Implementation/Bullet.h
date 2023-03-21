#ifndef BULLET_H
#define BULLET_H
#include "Sprites/MovableSprite.h"
#include "Implementation/ScoreBoard.h"
#include <math.h>

extern std::string resPath;

class Bullet : public GameEngine::MovableSprite
{
public:
    ~Bullet();
    static Bullet *getInstance(int d, int x, int y, int w, int h, int mouseX, int mouseY);
    void tick(GameEngine::GameLoop *);
    void draw() const;
    
    int getMouseX() const;
    int getMouseY() const;
    void handleSpriteCollision(Sprite *other, GameEngine::GameLoop *loop);

    struct Vector2
    {
    private:
        float x;
        float y;

    public:
        Vector2(float xPos, float yPos) : x(xPos), y(yPos){};

        float length()
        {
            return sqrt(pow(this->x, 2)) + sqrt(pow(this->y, 2));
        }

        float normalizeX()
        {
            return (this->x / length());
        }

        float normalizeY()
        {
            return (this->y / length());
        }
    };

private:
    Bullet(int d, int x, int y, int w, int h, int mouseX, int mouseY);
    int mouseXPos;
    int mouseYPos;
    int startXPos;
    int startYPos;
    bool hasMissed;
    Vector2 vec;
    const std::string imgPath = resPath + "images/Bullet.png";

    SDL_Texture *texture;
};

#endif
