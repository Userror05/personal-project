/**
 * @file jeu.h
 * @brief Déclaration de la classe Jeu et de ses fonctions membres
 */

#ifndef _JEU
#define _JEU

#include "terrain.h"
#include <vector>
#include<iostream>
#include<math.h>

/**
 * @class Jeu
 * @brief Classe représentant le jeu et ses fonctionnalités
 */
class Jeu
{

    private:
    Terrain ter;///Tableau représentant le terrain utilisé pour stocker les diiférents types d'obstacles présent sur le terrain
    Balle jp;///Balle qui représente le joueur sur le terrain 
    int Raf; ///  Rafraîchissement de l'affichage en millisecondes
    unsigned int score = 1000;/// représente le score initialisé a 1000 qui se décrémente
    unsigned int nbCoups=0;/// représente le nombre de coups effectué par le joueur

public:
    std::vector<float> tabPosX; ///< Vecteur de positions X utilisé pour stocker les positions de la balle lorsqu'elle est jouée
    std::vector<float> tabPosY; ///< Vecteur de positions Y utilisé pour stocker les positions de la balle lorsqu'elle est jouée

    /**
     * @brief Fonction qui permet de rejouer la balle avec une nouvelle direction donnée par un vecteur donné
     * @param v Vecteur représentant la nouvelle direction de la balle
     * @return Retourne vrai si la balle a pu être rejouée, faux sinon
     */
    bool Rejouer(Vecteur v);

    /**
     * @brief Fonction qui renvoie une référence à l'objet Terrain utilisé pour représenter le terrain de jeu
     * @return Retourne une référence à l'objet Terrain
     */
    Terrain& GetTerrain();

    /**
     * @brief Fonction qui renvoie une référence constante à l'objet Terrain utilisé pour représenter le terrain de jeu
     * @return Retourne une référence constante à l'objet Terrain
     */
    const Terrain& GetConstTerrain() const;

    /**
     * @brief Fonction qui permet de choisir l'angle de frappe de la balle en fonction de la touche pressée
     * @param touche Touche pressée pour choisir l'angle de frappe de la balle
     */
    void AngleChoisis(const char touche);
    void ChangerRafraichissement(const char touche);
    void BackMouvBalle(Balle& b);

    /**
     * @brief Fonction qui permet de choisir la puissance de frappe de la balle en fonction de la touche pressée
     * @param touche Touche pressée pour choisir la puissance de frappe de la balle
     */
    void GetPuis(const char touche);

    /**
     * @brief Fonction qui permet de jouer un tour de jeu en fonction de la touche pressée
     * @param jouer Touche pressée pour jouer un tour de jeu
     * @return Retourne vrai si le tour de jeu a pu être joué, faux sinon
     */
    bool Jouer(const char jouer);

    /**
     * @brief Fonction qui permet de tester la régression de la balle
     */
    void TestRegression();

    /**
     * @brief Fonction qui permet de répartir la position de la balle dans les vecteurs de positions X et Y
     * @param b Objet Balle à répartir
     */
    void RepartirPosition(Balle& b);

    /**
     * @brief Fonction qui permet de vider les vecteurs de positions X et Y
     */
    void ClearRepartition();
    /**
     * @brief Fonction qui permet de changer le rafraichissement en fonction de l'appareil
     * @return renvoie le rafaichissement choisis
     */
    int GetRaf()const;
    /**
     * @brief Procédure qui permet de changer le rafraichissement en fonction de l'appareil
     * 
     */
    void SetRaf(int raf);
    /**
     * @brief Renvoie l'objet Balle utilisé par le joueur.
     *
     * @return L'objet Balle utilisé sur le terrain en mode const.
     */

    const Balle& GetConstBalle()const ;
    /**
     * @brief Renvoie l'objet Balle utilisé par le joueur.
     *
     * @return L'objet Balle utilisé sur le terrain.
     */
     Balle& GetBalle() ;
    /**
     * @brief Incrémente le score ainsi que le nombre de coups si le joueur à joué.
     *
     */
     void SScore(const char touche);
      /**
     * @brief Renvoie le score gagné par le joueur.
     *
     * @return un entier.
     */
     int Getscore() const;
    /**
     * @brief Réinitialise le score à 0 quand le maximum de coup à été tiré.
     *
     */
     void resetScore();
     /**
     * @brief Renvoie le nombre de coups réalisés.
     *
     * @return un entier.
     */
     int GetCoups()const ;

};
inline void Jeu :: resetScore(){score=0;}
inline int Jeu :: GetCoups()const{return nbCoups;}
inline int Jeu :: Getscore()const {return score; std::cout<<score;}
inline void Jeu :: SScore(const char touche ){ if(Jouer(touche)&& nbCoups<20) {nbCoups++;score=score-sqrt(score)/2;}}
inline  Terrain& Jeu :: GetTerrain() {return ter;}
inline  const Terrain& Jeu :: GetConstTerrain() const {return ter;}
inline Balle& Jeu :: GetBalle() { return jp;}
inline int Jeu :: GetRaf() const {return Raf;}
inline void Jeu :: SetRaf(int raf)
{   Raf = raf;}
inline const Balle& Jeu :: GetConstBalle() const { return jp;}



#endif
//********************************BackUp************************************************************************
/*

    void ActionJoueur(Balle& b);
    void ActionJoueurVisuelTest45(Balle& b);
    float GetTabX() const;
    float GetTabY() const;
*/