#include "Implementation/BoxSpawner.h"

BoxSpawner::BoxSpawner(int interval) : spawnInterval(interval)
{
    spawnCount = 0;
    adjustedInterval = spawnInterval;
    initializeRandom();
}

BoxSpawner::~BoxSpawner(){};

void BoxSpawner::spawnBox(std::vector<GameEngine::Sprite *> &sprites)
{
    if (spawnCount == 0)
    {

        sprites.push_back(Box::getInstance(2, rand() % GameEngine::sys.getWidth(), 10, 40, 40));
    }
    else
    {

        for (int i = 0; i <= spawnCount + 1; i++)
        {

            sprites.push_back(Box::getInstance(2, rand() % GameEngine::sys.getWidth(), 1, 40, 40));
        }
    }

    spawnCount++;
}

void BoxSpawner::decreaseSpawnInterval(int i)
{
    spawnInterval -= i;
}


void BoxSpawner::initializeRandom(){
    srand(time(NULL));
}

void BoxSpawner::manipulate(GameEngine::GameLoop* loop){
    if((int)SDL_GetTicks() / 1000 == adjustedInterval){
        spawnBox(loop->getSprites());
        adjustedInterval += spawnInterval;
    }
}
