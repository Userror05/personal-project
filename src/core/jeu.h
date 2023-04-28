/**
 * @file jeu.h
 * @brief Déclaration de la classe Jeu et de ses fonctions membres
 */

#ifndef _JEU
#define _JEU

#include "terrain.h"
#include <vector>

/**
 * @class Jeu
 * @brief Classe représentant le jeu et ses fonctionnalités
 */
class Jeu
{

private:
    Terrain ter; ///< Objet Terrain utilisé pour représenter le terrain de jeu
    Balle jp; ///< Objet Balle utilisé pour représenter la balle du jeu

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

    /**
     * @brief Fonction qui permet de déplacer la balle dans la direction opposée à sa dernière direction
     * @param b Objet Balle à déplacer
     */
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
     * @brief Fonction qui renvoie la position X stockée dans le premier élément du vecteur de positions X
     * @return Retourne la position X stockée dans le premier élément du vecteur de positions X
    */
    float GetTabX() const;

    /**
     * @brief Fonction qui renvoie la position Y stockée dans le premier élément du vecteur de positions Y
     * @return Retourne la position Y stockée dans le premier élément du vecteur de positions Y
     */
    float GetTabY() const;

    /**
     * @brief Renvoie l'objet Balle utilisé par le joueur.
     *
     * @return L'objet Balle utilisé sur le terrain. (mode const)
     */

    const Balle& GetConstBalle()const ;
    /**
     * @brief Renvoie l'objet Balle utilisé par le joueur.
     *
     * @return L'objet Balle utilisé sur le terrain.
     */

     Balle& GetBalle() ;

};

inline  Terrain& Jeu :: GetTerrain() {return ter;}
inline  const Terrain& Jeu :: GetConstTerrain() const {return ter;}
inline Balle& Jeu :: GetBalle() { return jp;}

inline const Balle& Jeu :: GetConstBalle() const { return jp;}



#endif
//********************************BackUp************************************************************************
/*

    void ActionJoueur(Balle& b);
    void ActionJoueurVisuelTest45(Balle& b);
*/