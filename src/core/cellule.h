/**

    @file Cellule.h
    @brief Fichier d'en-tête pour la classe Cellule
    */

#ifndef _CELLULE
#define _CELLULE

/**

    @class Cellule
    @brief Représente une cellule unique dans une grille de terrain
    */

class Cellule
{


private:
unsigned int pos_x; /**< La coordonnée x de la cellule */
unsigned int pos_y; /**< La coordonnée y de la cellule */

public:

/**
 * @brief Constructeur par défaut pour Cellule
 */
Cellule();

/**
 * @brief Définit la coordonnée x de la cellule
 * @param x La nouvelle coordonnée x
 */
void SetX (unsigned int x);

/**
 * @brief Définit la coordonnée y de la cellule
 * @param y La nouvelle coordonnée y
 */
void SetY(unsigned int y);

/**
 * @brief Retourne la coordonnée x de la cellule
 * @return La coordonnée x
 */
unsigned int GetX() const;

/**
 * @brief Retourne la coordonnée y de la cellule
 * @return La coordonnée y
 */
unsigned int GetY() const;

/**
 * @brief Opérateur d'affectation pour Cellule
 * @param c La Cellule à affecter à cette Cellule
 * @return Une référence à cette Cellule
 */
Cellule& operator = (const Cellule& c);

};

#endif