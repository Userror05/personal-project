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
    int Largeur_fenetre;
    int Hauteur_fenetre;


    Image font_im;

    bool withSound; 
    Image im_balle;
    Image im_mur;
    Image im_font;
    Image im_trou;
    Image fond_menu;
    Image titre_menu;
    int Raf;
    ///////////////////////// associé au menu
    SDL_Rect jouerButton;
    SDL_Surface* jouerTextSurface;
    SDL_Texture* jouerTextTexture;
    SDL_Rect jouerText;

    SDL_Rect quitterButton;
    SDL_Surface* quitterTextSurface;
    SDL_Texture* quitterTextTexture;
    SDL_Rect quitterText;

     /**
     * @brief Surface de la fenêtre.
     */
    SDL_Surface * Image_Fenetre;

    /**
     * @brief Texture de la fenêtre.
     */
    SDL_Texture * Texture_Fenetre;

    /**
     * @brief Rectangle pour la fenêtre.
     */
    SDL_Rect rect_fenetre;
    /**
     * @brief Variable pour determiner la police des ecritures.
     */

    SDL_Rect menu,rejouer,quitter;
    SDL_Surface * quitter_surface;
    SDL_Surface * rejouer_surface;
    SDL_Texture * quitter_texture;
    SDL_Texture * rejouer_texture;
    


    public:

    JeuSDL2();
    ~JeuSDL2();
    void BoucleJeu();
    void SDL_Aff();
    Jeu& GetJeu();
    void SDL_Aff_Tab();
    void Replacer(const char touche);

    void afficherMenu();

    void Menu();

    void destructionFenetre_m();
    void InitJeu();
    void Lancement();
    void affiche_game_over();

    void tab_de_score();
 
 

    





};

inline Jeu& JeuSDL2 :: GetJeu(){return gami;}
//inline int JeuSDL2 :: SetRaf(float x){Raf=x;};


#endif
//******************************************BackUP*****************************************************
/*  
    void Rafraichissement(const char touche);

void TestAffichageBalleContinueV2(Balle& b);
//void BoucleChoixPUI();
//void BoucleChoixANG();
//void Bouclejeu();
//void TestAffichageBalleContinue(Balle& b);
//void SdlAffContour();
//void AffichageBalle();
//void TestAll();
*/