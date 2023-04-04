#ifndef _JEUSDL
#define _JEUSDL
#include "core/jeu.h"
#include <SDL2/SDL.h>>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include<iostream>


class JeuSDL2
{
    private :
    Jeu Jeu;
    
    SDL_Window * window;
    SDL_Renderer * renderer;

    TTF_Font * font;
    //Image font_im;
    SDL_Color font_color;

    Mix_Chunk * sound;
    bool withSound;


    public:

    

    void BoucleChoixPUI();


    void BoucleChoixANG();

    void SDLinit();

    void Bouclejeu();
    





};



#endif