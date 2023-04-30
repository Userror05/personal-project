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
    /**
     * @brief constructeur par défaut de la classe.
     *
     * @return True si la balle entre en collision avec un obstacle, False sinon.
     */

    JeuSDL2();
    /**
     * @brief destructeur par defaut de la classe 
     *
     * @return True si la balle entre en collision avec un obstacle, False sinon.
     */
    ~JeuSDL2();
    /**
     * @brief boucle qui permet l'affichage continue ainsi que la recupération des actions du joueur
     *
     * @return True si la balle entre en collision avec un obstacle, False sinon.
     */
    void BoucleJeu();

    /**
     * @brief fait l'affichage en recupérant des données statiques grâce a la librairie SDL.
     *
     * @return True si la balle entre en collision avec un obstacle, False sinon.
     */
    void SDL_Aff();
    Jeu& GetJeu();
    /**
     * @brief fait l'affichage en recupérant les positions stockés précédement dans un tableau dynamique de type entier;utilise la librairie SDL
     *
     * @return True si la balle entre en collision avec un obstacle, False sinon.
     */
    void SDL_Aff_Tab();
    /**
     * @brief Replace la balle selon des coordonnées définies a l'intérieur de la la fonction
     *  @param touche qui est un paramètre de type char
     * @return True si la balle entre en collision avec un obstacle, False sinon.
     */
    void Replacer(const char touche);
    
    /**
     * @brief Cette fonction gère les différents rectangles constituant le menu
     *
     * @return True si la balle entre en collision avec un obstacle, False sinon.
     */
    void afficherMenu();

    /**
     * @brief affiche et défini a quelle fonction accéder en fonction de l'emplacement cliqué par le joueur
     *
     * @return True si la balle entre en collision avec un obstacle, False sinon.
     */
    void Menu();

    /**
     * @brief detruit les différents composants permettant de réaliser l'affichage des différents menus
     *
     */
    void destructionFenetre_m();
    /**
     * @brief affiche le menu et le score après le game over
     *
     */
    void affiche_game_over();
    /**
     * @brief affiche le menu et le score après le game over en plus de gérer les différents choix tels que rjouer,retourner au menu ou bien quitter
     *
     */
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