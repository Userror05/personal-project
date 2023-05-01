/**
 * @file jeusdl2.h
 * @brief Déclaration de la classe Jeusdl2 et de ses fonctions membres qui permet un affichage du jeu avec la librairie SDL2
 */
#ifndef _JEUSDL
#define _JEUSDL
#include "../core/jeu.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include<iostream>
#include<vector>



/**

    @class Image
    @brief Cette classe représente une image qui peut être chargée à partir d'un fichier ou d'une surface, puis dessinée sur un renderer SDL.
    */
    class Image {

private:



SDL_Surface * m_surface; /**< Pointeur vers la surface SDL représentant l'image. */
SDL_Texture * m_texture; /**< Pointeur vers la texture SDL représentant l'image. */
bool m_hasChanged; /**< Drapeau indiquant si l'image a été modifiée depuis la dernière fois qu'elle a été chargée à partir d'un fichier ou d'une surface. */
TTF_Font * police; /**< Pointeur vers la police TTF utilisée pour dessiner du texte sur l'image. */
SDL_Color couleur; /**< Couleur utilisée pour dessiner du texte sur l'image. */

public:
/**
* @brief Constructeur de la classe Image.
*/
Image();



/**
 * @brief Destructeur de la classe Image.
 */
~Image();

/**
 * @brief Charge l'image à partir d'un fichier et crée une texture à partir de celle-ci.
 * @param filename Le chemin d'accès au fichier image.
 * @param renderer Pointeur vers le renderer SDL sur lequel la texture sera créée.
 */
void LoadFromFile(const char* filename, SDL_Renderer * renderer);

/**
 * @brief Crée une texture à partir de la surface courante de l'image.
 * @param renderer Pointeur vers le renderer SDL sur lequel la texture sera créée.
 */
void LoadFromCurrentSurface(SDL_Renderer * renderer);

/**
 * @brief Dessine l'image sur le renderer donné.
 * @param renderer Pointeur vers le renderer SDL sur lequel l'image sera dessinée.
 * @param x La coordonnée x du coin supérieur gauche du rectangle de destination.
 * @param y La coordonnée y du coin supérieur gauche du rectangle de destination.
 * @param w La largeur du rectangle de destination. Si -1, la largeur de la texture sera utilisée.
 * @param h La hauteur du rectangle de destination. Si -1, la hauteur de la texture sera utilisée.
 */
void Draw(SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);

/**
 * @brief Renvoie un pointeur vers la texture SDL représentant l'image.
 * @return Un pointeur vers la texture SDL.
 */
SDL_Texture * GetTexture() const;

/**
 * @brief Définit la surface représentant l'image.
 * @param surf Pointeur vers la surface SDL représentant l'image.
 */
void SetSurface(SDL_Surface * surf);

/**
 * @brief Affiche un menu sur le renderer donné, en utilisant l'image comme arrière-plan.
 * @param renderer Pointeur vers le renderer SDL sur lequel le menu sera dessiné.
 */
void AfficherMenu(SDL_Renderer * renderer);

/**
 * @brief Définit la police TTF utilisée pour dessiner du texte sur l'image.
 * @param pol Pointeur vers la police TTF à utiliser.
 */
inline void SetPolice(TTF_Font * pol);

/**
 * @brief Définit la couleur utilisée pour dessiner du texte sur l'image.
 * @param coul La couleur à utiliser.
 */
inline void SetColeurPolice(SDL_Color coul);

};

/**

    @brief Définit la police TTF utilisée pour dessiner du texte sur l'image.
    @param pol Pointeur vers la police TTF à utiliser.
    */
    inline void Image::SetPolice(TTF_Font * pol) { police = pol; }

/**

    @brief Définit la couleur utilisée pour dessiner du texte sur l'image.
    @param coul La couleur à utiliser.
    */
    inline void Image::SetColeurPolice(SDL_Color coul) { couleur = coul; }

// IMAGE_H

/**

    @brief La classe JeuSDL2 est responsable de l'affichage graphique du jeu, en utilisant la bibliothèque SDL2.
    */
    class JeuSDL2 {
         private:
        Jeu gami; /// Instance de la classe Jeu

            
        int PasDeTemps;
        SDL_Window * window; /// Fenêtre d'affichage
        SDL_Renderer* renderer; /// Rendu d'affichage
        int Largeur_fenetre; /// Largeur de la fenêtre
        int Hauteur_fenetre; /// Hauteur de la fenêtre

        Image font_im; /// Image pour le texte
        bool withSound; /// Booléen indiquant si le son est activé
        Image im_balle; /// Image de la balle
       
        Image im_font; /// Image pour le texte
        Image im_trou; /// Image du trou
        Image im_case;
        Image im_case_cote;
        Image im_case_cote2;
        Image im_herbe;
        Image im_pic;
        Image im_sonic1;
        Image im_sonic2;
        Image fond_menu; /// Image pour le fond du menu
        Image titre_menu; /// Image pour le titre du menu


     /**
     * @brief Tout les variables associées aux boutons du menu et du tableau des scores.
     */
     /**
     * @brief rectangle du bouton jouer.
     */
    SDL_Rect jouerButton;
     /**
     * @brief Surface du bouton jouer
     */
    SDL_Surface* jouerTextSurface;
     /**
     * @brief Texture du bouton jouer
     */
    SDL_Texture* jouerTextTexture;
     /**
     * @brief Rectangle pour afficher le texte "jouer".
     */
    SDL_Rect jouerText;
    /**
     * @brief Rectangle SDL du bouton quitter.
     */
    SDL_Rect quitterButton;
     /**
     * @brief Surface du bouton quitter
     */
    SDL_Surface* quitterTextSurface;
    /**
     * @brief Texture du bouton quitter
     */
    SDL_Texture* quitterTextTexture;
    /**
     * @brief Rectangle SDL pour afficher le texte "quitter".
     */
    SDL_Rect quitterText;
    /**
     * @brief Rectangles SDL pour le tableau des scores pour afficher l'icone pour retourner au menu,rejouer une partie,quitter le jeu.
     */
    SDL_Rect menu,rejouer,quitter;
    /**
     * @brief Surface SDL  pour le bouton "quitter".
     */
    SDL_Surface * quitter_surface;
    /**
     * @brief Surface SDL  pour le bouton "rejouer".
     */
    SDL_Surface * rejouer_surface;
    /**
     * @brief Texture SDL  pour le bouton "quitter".
     */
    SDL_Texture * quitter_texture;
    /**
     * @brief Texture SDL  pour le bouton "rejouer".
     */
    SDL_Texture * rejouer_texture;
    


    public:
    /**
     * @brief constructeur par défaut de la classe.
     *
     * 
     */
    JeuSDL2();
    /**
     * @brief destructeur par defaut de la classe 
     *
     * 
     */
    ~JeuSDL2();
    /**
     * @brief boucle qui permet l'affichage continue ainsi que la recupération des actions du joueur
     *
     * 
     */
    void BoucleJeu();

    /**
     * @brief fait l'affichage en recupérant des données statiques grâce a la librairie SDL.
     *
     * 
     */
    void SDL_Aff();

    /**
     * @brief fait l'affichage de manière plus précise en recupérant des données statiques grâce a la librairie SDL.
     *
     */
    void SDL_Aff_cote();
    /**
     * @brief fait l'affichage en recupérant les positions stockés précédement dans un tableau dynamique de type entier;utilise la librairie SDL
     *
     * 
     */
    void SDL_Aff_Tab();
    /**
     * @brief Replace la balle selon des coordonnées définies a l'intérieur de la la fonction
     *  @param touche qui est un paramètre de type char
     * 
     */
    void Replacer(const char touche);
    void ReplacerSansTouche();
    
    /**
     * @brief Cette fonction gère les différents rectangles constituant le menu
     *
     * 
     */
    void afficherMenu();

    /**
     * @brief affiche et défini a quelle fonction accéder en fonction de l'emplacement cliqué par le joueur
     *
     * 
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
     /**
     * @brief affiche les différents obstacle élémentaire, notamment ceux lors de la création du niveau
     * 
     */
    void SDL_Aff_Creation_Niveau();

    void affiche_info_pui();
    void affiche_infos_ang();
    void SDL_Animation();
    
  
 

    





};




#endif
