#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <memory>

namespace GameEngine
{
    extern std::string resPath;
    class System
    {
    public:
        System();
        ~System();

        SDL_Renderer *getRen() const;
        void setTitle(std::string *title);
        void setWindowSize(int &, int &);
        int getWidth() const;
        int getHeight() const;
        TTF_Font* getFont() const;

    private:
        SDL_Window *win;
        SDL_Renderer *ren;
        TTF_Font *font;
        void initSDL();
        void createWindow();
        void createRenderer();
        void initTTF();
        void openFont();
        std::string fontPath = "../../resources/fonts/Spartan-Medium.ttf";
    };

    extern System sys;

}

#endif