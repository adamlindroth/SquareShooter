#include "System.h"
#include <iostream>

namespace GameEngine
{

    System::System()
    {
        initSDL();
        createWindow();
        createRenderer();
        initTTF();
        openFont();
    };

    System::~System()
    {
        TTF_CloseFont(font);
        TTF_Quit();
        SDL_DestroyWindow(win);
        SDL_DestroyRenderer(ren);
        SDL_Quit();
    }

    void System::initSDL()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
        {
            std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
            exit(-1);
        }
    }

    void System::createWindow()
    {
        win = SDL_CreateWindow(nullptr, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
        if (!win)
        {
            std::cerr << "Window could not be created: " << SDL_GetError() << std::endl;
        }
    }

    void System::createRenderer()
    {
        ren = SDL_CreateRenderer(win, -1, 0);

        if (!ren)
        {
            std::cerr << "Renderer could not be created" << SDL_GetError() << std::endl;
        }
    }

    void System::initTTF()
    {
        if (TTF_Init() == -1)
        {
            std::cerr << "Failed to initialize TTF: " << TTF_GetError() << std::endl;
        }
    }

    void System::openFont()
    {
        std::cout << "Opening Font" << std::endl;
        font = TTF_OpenFont(fontPath.c_str(), 36);
        if (!font)
        {
            std::cerr << "Failed to open font: " << SDL_GetError();

            exit(-1);
        }
    }

    SDL_Renderer *System::getRen() const
    {
        return ren;
    }

    void System::setTitle(std::string *title)
    {
        SDL_SetWindowTitle(win, title->c_str());
    }

    void System::setWindowSize(int &w, int &h)
    {
        SDL_SetWindowSize(win, w, h);
    }

    int System::getWidth() const
    {
        return SDL_GetWindowSurface(win)->w;
    }

    int System::getHeight() const
    {
        return SDL_GetWindowSurface(win)->h;
    }

    TTF_Font* System::getFont() const{
        return font;
    }

    System sys;
};