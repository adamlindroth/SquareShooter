#ifndef PLAYABLESPRITE_H
#define PLAYABLESPRITE_H
#include "Sprites/MovableSprite.h"

namespace GameEngine
{
    class PlayableSprite : public MovableSprite
    {
        public:
        virtual ~PlayableSprite(){};

        enum keys{
            KEY_A = SDL_SCANCODE_A,
            KEY_S = SDL_SCANCODE_S,
            KEY_D = SDL_SCANCODE_D,
            KEY_W = SDL_SCANCODE_W,
            
        };

        virtual void handleKeyDownEvent(int){};
        virtual void handleMouseDownEvent(int x, int y, int button, GameLoop* loop){};
        
        protected:
        PlayableSprite(int speed, int x, int y, int w, int h) : MovableSprite(speed, x, y, w, h){};

        private:
        PlayableSprite(const PlayableSprite&) = delete;
        const PlayableSprite& operator=(const PlayableSprite&) = delete;



    };

} // namespace GameEngine

#endif