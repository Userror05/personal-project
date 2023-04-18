#ifndef _JEUSDL
#define _JEUSDL
#include "../core/jeu.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include<iostream>



//! \brief Pour gérer une image avec SDL2
class Image {

private:

    SDL_Surface * m_surface;
    SDL_Texture * m_texture;
    bool m_hasChanged;
    TTF_Font * police;
    SDL_Color couleur;

public:
    Image () ;
    ~Image();
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void loadFromCurrentSurface (SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    SDL_Texture * getTexture() const;
    void setSurface(SDL_Surface * surf);
    void afficherMenu(SDL_Renderer * renderer);
    void SetPolice(TTF_Font * police);
    void SetColeurPolice(SDL_Color couleur);
};

inline void Image :: SetPolice(TTF_Font * pol){police =pol;}
inline void Image :: SetColeurPolice(SDL_Color coul){couleur = coul;}
class JeuSDL2
{
    private :
    Jeu gami;
    
    SDL_Window * window;
    SDL_Renderer * renderer;

    TTF_Font * font;
    Image font_im;
    SDL_Color font_color;

    Mix_Chunk * sound;
    bool withSound; 
    Image im_balle;
    Image im_mur;


    public:

    JeuSDL2();
    ~JeuSDL2();

    //void BoucleChoixPUI();


    //void BoucleChoixANG();

    void Bouclejeu();
    void BouclejeuV2();
    void TestAffichageBalleContinue(Balle& b);

    void sdlaff();
    Jeu& GetJeu();
    void TestAll();

    





};

inline Jeu& JeuSDL2 :: GetJeu(){return gami;}

#endif