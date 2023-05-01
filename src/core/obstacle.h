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
* - R : un obstacle normal
* - F : un obstacle qui designer la ligne d'arrivée
* - M : un obstacle qui designe un obstacle qui fait echouer directement le joueur
*/
   public:
    enum typeOBS{M=3, R=2, F=1 };

typeOBS obs; /**< Le type d'obstacle > */

/**
 * @brief Sélectionne le type d'obstacle
 *
 * Cette méthode permet de sélectionner le type d'obstacle en fonction d'un choix donné.
 *
 * @param choix Le choix du type d'obstacle (0 pour F , 1 pour R et 2 pour M)
 */
void SelectType(unsigned int choix);



};
/*
 *  @brief Sélectionne le type d'obstacle
 *   Cette méthode permet de sélectionner le type d'obstacle en fonction d'un choix donné.
 *  @param choix Le choix du type d'obstacle (0 pour F , 1 pour R et 2 pour M)
 */
inline void Obstacle :: SelectType(unsigned int choix){ assert(choix==1 ||choix==2 || choix==0);if(choix==1){obs=R;}else {if(choix== 2){obs=M;}else{obs=F;}}}


#endif