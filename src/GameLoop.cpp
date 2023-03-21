#include "GameLoop.h"
#include "Implementation/BoxSpawner.h"

namespace GameEngine
{

    GameLoop::GameLoop()
    {
        //Default fps
        fps = 60;
    };

    GameLoop::~GameLoop(){

    };

    void GameLoop::addBackground(std::string path)
    {
        SDL_Surface *surf = IMG_Load((path).c_str());
        background = SDL_CreateTextureFromSurface(sys.getRen(), surf);
        SDL_FreeSurface(surf);
    }

    void GameLoop::drawBackground()
    {
        SDL_RenderCopy(sys.getRen(), background, NULL, NULL);
    }

    void GameLoop::add(Sprite *s)
    {
        added.push_back(s);
        if (PlayableSprite *p = dynamic_cast<PlayableSprite *>(s))
        {
            players.push_back(p);
        }
    }

    void GameLoop::addManipulator(WorldManipulator *m)
    {
        manipulators.push_back(m);
    }

    void GameLoop::setFPS(int i)
    {
        fps = i;
    }

    void GameLoop::queueForRemoval(Sprite *s)
    {
        removed.push_back(s);
    }

    void GameLoop::remove()
    {

        //Removes the sprites that exists in both removed<> and sprites<>.
        for (Sprite *s : removed)
        {

            // Removes deleted sprites from general sprite-collection
            for (std::vector<Sprite *>::iterator i = sprites.begin(); i != sprites.end();)
            {
                if (*i == s)
                {
                    i = sprites.erase(i);
                }
                else
                {
                    i++;
                }
            }

            // Removes deleted playerSprites from  players-collection
            for (std::vector<PlayableSprite *>::iterator i = players.begin(); i != players.end();)
            {

                if (*i == s)
                {
                    i = players.erase(i);
                }
                else
                {
                    i++;
                }
            }
        }

        //Removes the sprites from heap
        for (Sprite *s : removed)
        {
            delete s;
        }
        removed.clear();
    }

    /*
    Checks if the sprites has collided. Takes a sprite as parameter and returns the sprite it has collided with.
    Returns null if no collision has occured.
    */
    Sprite *GameLoop::collision(Sprite *sprite)
    {
        Sprite *collider = NULL;
        for (Sprite *other : sprites)
        {

            if (sprite != other &&
                sprite->XPos() < other->XPos() + other->getWidth() &&
                sprite->XPos() + sprite->getWidth() > other->XPos() &&
                sprite->YPos() < other->YPos() + other->getHeight() &&
                sprite->YPos() + sprite->getHeight() > other->YPos())
            {
                collider = other;

                break;
            }
        }
        return collider;
    }

    // Runs the game-loop
    void GameLoop::run()
    {

        quit = false;

        const int tickInterval = 1000 / fps;
        Uint32 nextTick;
        int delay;

        while (!quit)
        {

            nextTick = SDL_GetTicks() + tickInterval;

            handleEvents();
            update();
            draw();

            delay = nextTick - SDL_GetTicks();
            if (delay > 0)
            {
                SDL_Delay(delay);
            }

            //spawner.checkTime(SDL_GetTicks(), sprites);

        } //Outer while

        sys.~System();
    }

    // Handles user input
    void GameLoop::handleEvents()
    {
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        SDL_Event event;
        //Event-loop
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;

            case SDL_MOUSEBUTTONDOWN:

                int mouseX;
                int mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);

                for (PlayableSprite *p : players)
                {
                    p->handleMouseDownEvent(mouseX, mouseY, event.button.button, this);
                }

                break;

            case SDL_KEYDOWN: // You can further implement this case for as many keys as you would like.

                if (state[SDL_SCANCODE_D])
                {
                    for (PlayableSprite *p : players)
                    {
                        p->handleKeyDownEvent(SDL_SCANCODE_D);
                    }
                    break;
                }

                if (state[SDL_SCANCODE_A])
                {
                    for (PlayableSprite *p : players)
                    {
                        p->handleKeyDownEvent(SDL_SCANCODE_A);
                    }
                    break;
                }

                if (state[SDL_SCANCODE_W])
                {
                    for (PlayableSprite *p : players)
                    {
                        p->handleKeyDownEvent(SDL_SCANCODE_W);
                    }
                }

                if (state[SDL_SCANCODE_S])
                {
                    for (PlayableSprite *p : players)
                    {
                        p->handleKeyDownEvent(SDL_SCANCODE_S);
                    }
                }

                break;

            } //Switch
        }     //Inner while
    }

    // Updates the state of the game-objects
    void GameLoop::update()
    {

        for (Sprite *s : sprites)
        {
            s->tick(this);
        }

        for (PlayableSprite *p : players)
        {
            p->tick(this);
        }

        for (Sprite *s : added)
        {
            sprites.push_back(s);
        }

        if (!manipulators.empty())
        {
            for (WorldManipulator *m : manipulators)
            {
                m->manipulate(this);
            }
        }

        added.clear();
        remove();
    }

    // Renders the objects
    void GameLoop::draw()
    {
        SDL_SetRenderDrawColor(sys.getRen(), 255, 255, 255, 255);
        SDL_RenderClear(sys.getRen());
        drawBackground();
        for (Sprite *s : sprites)
        {
            s->draw();
        }

        SDL_RenderPresent(sys.getRen());
    }

    std::vector<Sprite *> &GameLoop::getSprites()
    {
        return sprites;
    }

}
