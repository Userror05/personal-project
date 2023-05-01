/**

    @file Gravite.h
    @brief Déclaration de la classe Gravite pour gérer la gravité appliquée à une balle.
    */

#ifndef _GRAVITE
#define _GRAVITE

#include"balle.h"

/**

    @class Gravite

    @brief Classe pour gérer la gravité appliquée à une balle.

    La classe Gravite permet de gérer l'effet de la gravité sur une balle en mouvement.

    Elle contient différentes méthodes pour actualiser la position et les paramètres de la balle.
    */
    class Gravite
    {

    private:

    float Power; /*< Force de la gravité. */
    int Angle; /*< Angle de la direction de la gravité. */

    public:

    /**
        @brief Constructeur par défaut de la classe Gravite.
        Initialise la force et l'angle de la gravité à zéro.
        */
        Gravite();

    /**
        @brief Actualise la position de la balle via la division des forces appliquées.
        @param b Balle à actualiser.
        */
        void ActualiseBalleViaDiv(Balle& b) const;

    /**
        @brief Actualise le mouvement de la balle en fonction de la gravité.
        @param b Balle à actualiser.
        */
        void ActualiseMouv(Balle& b) const;

    /**
        @brief Actualise la direction de la balle en fonction de l'angle de la gravité.
        @param b Balle à actualiser.
        @param n Numéro de la balle.
        */
        void ActualiseAdri(Balle& b, int n) const;

    /**
        @brief Actualise les directions de la balle.
        @param b Balle à actualiser.
        */
        void ActualiseDirections(Balle& b) const;

    /**
        @brief Efface les directions de la balle.
        @param b Balle à actualiser.
        */
        void ClearDirections(Balle& b) const;

    /**
        @brief Modifie la force de la gravité.
        @param pow réel qui défini la Nouvelle force appliqué a la balle.
        */
        void SetPow(float pow);

    /**
        @brief Modifie l'angle de la gravité.
        @param ang Nouvel angle de la gravité.
        */
        void SetAng(int ang);

    /**
        @brief Retourne l'angle de la gravité.
        @return L'angle de la gravité.
        */
        int GetAngle() const;

    /**
        @brief Retourne la force de la gravité.
        @return La force de la gravité.
        */
        float GetPow() const;

    /**
        @brief Calcule la valeur de A pour la conversion d'angle.
        @return La valeur de A pour la conversion d'angle.
        */
        double RecupA();

    /**
        @brief Calcule la valeur de B pour la conversion d'angle.
        @return La valeur de B pour la conversion d'angle.
        */
        double RecupB();

    /**
        @brief Convertit l'angle de la gravité en radians.
        @return L'angle * converti en radians.
 */
double ConversionAng();

/**
 * @brief Convertit la composante X de la gravité en fonction de l'angle.
 * 
 * @return La composante X de la gravité convertie.
 */
double ConversionX();

/**
 * @brief Convertit la composante Y de la gravité en fonction de l'angle.
 * 
 * @return La composante Y de la gravité convertie.
 */
double ConversionY();

/**
 * @brief Retourne la vitesse de la balle.
 * 
 * @param b Balle à utiliser pour le calcul de la vitesse.
 * @return La vitesse de la balle.
 */
Vecteur& Vitesse(Balle& b);

/**
 * @brief Affiche l'angle de la gravité.
 */
void AffAng();

/**
 * @brief Affiche la force et l'angle de la gravité.
 */
void AffPR();

/**
 * @brief Effectue un test de régression.
 */
void TestRegression();

};

/**

    @brief Modifie la force de la gravité.
    @param pow Nouvelle force de la gravité.
    */
    inline void Gravite::SetPow(float pow)
    {
    Power = pow;
    }

/**

    @brief Modifie l'angle de la gravité.
    @param ang Nouvel angle de la gravité.
    */
    inline void Gravite::SetAng(int ang)
    {
    Angle = ang;
    }

/**

    @brief Retourne la force de la gravité.
    @return La force de la gravité.
    */
    inline float Gravite::GetPow() const
    {
    return Power;
    }

/**

    @brief Retourne l'angle de la gravité.
    @return L'angle de la gravité.
    */
    inline int Gravite::GetAngle() const
    {
    return Angle;
    }

#endif
//********************************BackUp************************************************************************
/*
    void ActualiseDivise(Balle& b) const;
    void ActualiseVecteur(Balle& b) const;
void accelerationBalle();
*/