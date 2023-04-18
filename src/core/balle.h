/**
 * @file balle.h
 * @brief Déclaration de la classe Balle
 */

#ifndef _BALLE_H
#define _BALLE_H

#include "vecteur.h"

/**
 * @class Balle
 * @brief Classe représentant une balle
 */
class Balle 
{
private:
    double pos_x; /**< La position en x de la balle */
    double pos_y; /**< La position en y de la balle */
    double decalage_x;
    double decalage_y;
public:
    Vecteur Sauvegarde; /**< Le vecteur de sauvegarde de la position de la balle */
    Vecteur mouvement; /**< Le vecteur de mouvement de la balle */
    Vecteur vitesse; /**< Le vecteur de vitesse de la balle */
    Vecteur gravite; /**< Le vecteur de gravité de la balle */

    /**
     * @brief Constructeur par défaut de la classe Balle
     */
    Balle();

    /**
     * @brief Retourne la position en x de la balle
     * @return La position en x de la balle
     */
    double GetX() const;

    /**
     * @brief Retourne la position en y de la balle
     * @return La position en y de la balle
     */
    double GetY() const;

    /**
     * @brief Modifie la position en x de la balle
     * @param x La nouvelle position en x de la balle
     */
    void SetX(double x);

    /**
     * @brief Modifie la position en y de la balle
     * @param y La nouvelle position en y de la balle
     */
    void SetY(double y);

    /**
     * @brief Affiche la position actuelle de la balle
     */
    void AffPosition();

    /**
     * @brief Initialise le vecteur de mouvement de la balle
     */
    void InitMouvement();

    /**
     * @brief Affiche la vitesse actuelle de la balle
     */
    void AffVitesse();

    /**
     * @brief Affiche le vecteur de mouvement initial de la balle
     */
    void AffInitMouvement();


    void TestRegression();
};

#endif
