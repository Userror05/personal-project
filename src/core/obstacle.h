/**

    @file obstacle.h
    @brief Définition de la classe Obstacle
    */

#ifndef _OBSTACLE_H
#define _OBSTACLE_H

#include "cellule.h"
#include <cassert>

/**

    @class Obstacle
    @brief Classe représentant un obstacle dans la grille
    Cette classe représente un obstacle dans la grille, qui est une cellule qui ne peut pas être occupée par un robot.
    */
    class Obstacle
    {
    private:
    Cellule Obstacle; /**< La cellule qui représente l'obstacle */

public:
/**
* @enum typeOBS
* @brief Enumération représentant le type d'obstacle
*
* Cette énumération représente les différents types d'obstacle possibles :
* - R : un obstacle rond
* - F : un obstacle carré
*/
enum typeOBS{ R=2, F=1 };



typeOBS obs; /**< Le type d'obstacle */

/**
 * @brief Sélectionne le type d'obstacle
 *
 * Cette méthode permet de sélectionner le type d'obstacle en fonction d'un choix donné.
 *
 * @param choix Le choix du type d'obstacle (0 pour F et 1 pour R)
 */
void SelectType(unsigned int choix);

/**
 * @brief Définit la position de l'obstacle dans la grille
 *
 * Cette méthode permet de définir la position de l'obstacle dans la grille en fonction de ses coordonnées.
 *
 * @param x La coordonnée x de la cellule représentant l'obstacle
 * @param y La coordonnée y de la cellule représentant l'obstacle
 */
void SetObstacle(unsigned int x, unsigned int y);

};

/**

    @brief Sélectionne le type d'obstacle
    Cette méthode permet de sélectionner le type d'obstacle en fonction d'un choix donné.
    @param choix Le choix du type d'obstacle (0 pour F et 1 pour R)
    */
    inline void Obstacle::SelectType(unsigned int choix)
    {
    assert(choix == 1 || choix == 0);
    if (choix == 1)
    obs = R;
    else
    obs = F;
    }

#endif