#ifndef WORLDMANIPULATOR_H
#define WORLDMANIPULATOR_H
#include <vector>

/* Base class for objects that arent sprites but are intended to manipulate the game-world in some way.
    For example spawning enemies.
*/
namespace GameEngine
{
    class GameLoop;
    class WorldManipulator
    {
    public:
        virtual ~WorldManipulator(){};
        virtual void manipulate(GameLoop* loop) = 0;
    protected: 
    WorldManipulator(){};
    private:
        const WorldManipulator& operator=(const WorldManipulator&) = delete;
        WorldManipulator(const WorldManipulator&) = delete;
    };
}

#endif