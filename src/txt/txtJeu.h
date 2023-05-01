/**
 * @file txtJeu.h
 * @brief Définition de la classe txtJeu pour réaliser un affichage en mode txt du terrain
 */

#ifndef _TXTJEU_H
#define _TXTJEU_H

#include "../core/jeu.h"
/**
 *
 * @brief procédure qui permet de charger les affichages en fonction de ce qui se trouve dans le terrain
 *
 * 
 */
void TxtAff (WinTXT & win,Jeu & jeu);
/**
 *
 * @brief procédure qui affiche en continue l'affichage du jeu
 *
 * 
 */
void TxtBoucle (Jeu & j);

#endif
