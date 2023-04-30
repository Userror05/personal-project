#ifndef _JEUSDL
#define _JEUSDL
#include "../core/jeu.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include<iostream>
#include<vector>




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
    void LoadFromFile (const char* filename, SDL_Renderer * renderer);
    void LoadFromCurrentSurface (SDL_Renderer * renderer);
    void Draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    SDL_Texture * GetTexture() const;
    void SetSurface(SDL_Surface * surf);
    void AfficherMenu(SDL_Renderer * renderer);
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

    Image font_im;

    bool withSound; 
    Image im_balle;
    Image im_mur;
    Image im_font;
    int Raf;
    


    public:

    JeuSDL2();
    ~JeuSDL2();
    void BoucleJeu();
    void TestAffichageBalleContinueV2(Balle& b);
    void SDL_Aff();
    Jeu& GetJeu();
    void SDL_Aff_Tab();
    void Replacer(const char touche);
    void Rafraichissement(const char touche);
 

    





};

inline Jeu& JeuSDL2 :: GetJeu(){return gami;}
//inline int JeuSDL2 :: SetRaf(float x){Raf=x;};


#endif
//******************************************BackUP*****************************************************
/*  
//void BoucleChoixPUI();
//void BoucleChoixANG();
//void Bouclejeu();
//void TestAffichageBalleContinue(Balle& b);
//void SdlAffContour();
//void AffichageBalle();
//void TestAll();
*/