#ifndef BOXSPAWNER_H
#define BOXSPAWNER_H
#include "Implementation/Box.h"
#include "WorldManipulator.h"
#include <ctime>
#include <vector>

    class Sprite;
    class BoxSpawner : public GameEngine::WorldManipulator
    {
        public:
        BoxSpawner(int interval);
        ~BoxSpawner();
        //Spawns boxes every 10 seconds
        void manipulate(GameEngine::GameLoop* loop);
        

        

        private:
        int spawnInterval;
        int adjustedInterval;
        int spawnCount;
        void initializeRandom();
        // Adds a box with a random x.position to GameLoops sprite-collection
        void spawnBox(std::vector<GameEngine::Sprite*>& sprites);
        void decreaseSpawnInterval(int i);
    };
    
    
#endif