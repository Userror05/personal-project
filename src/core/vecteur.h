/**
 * @file vecteur.h
 * @brief Déclaration de la classe Vecteur
 */

#ifndef _VECTEUR
#define _VECTEUR

/**
 * @class Vecteur
 * @brief Représente un vecteur à deux dimensions
 */
class Vecteur
{
    private :
    float x; ///< Coordonnée X du vecteur
    float y; ///< Coordonnée Y du vecteur

    public: 
     /**
      * @brief Constructeur par défaut
      * Initialise un vecteur nul.
      */
     Vecteur();

     /**
      * @brief Constructeur par copie 
      * @param x Coordonnée X du vecteur
      * @param y Coordonnée Y du vecteur
      */
     Vecteur(float x,float y);
   
    /**
     * @brief Additionne deux vecteurs
     * @param v1 Le vecteur à ajouter
     * @return Une référence au vecteur résultant
     */
    Vecteur& operator + (const Vecteur &v1);
    
    /**
     * @brief Soustrait deux vecteurs
     * @param v1 Le vecteur à soustraire
     * @return Une référence au vecteur résultant
     */
    Vecteur& operator - (const Vecteur &v1);

    /**
     * @brief Divise un vecteur par un scalaire
     * @param scalar Le scalaire à diviser
     * @return Le vecteur résultant
     */
    Vecteur operator / (float scalar)const;

    /**
     * @brief Multiplie un vecteur par un scalaire
     * @param scalar Le scalaire à multiplier
     * @return Le vecteur résultant
     */
    Vecteur operator * (float scalar)const ;

    /**
     * @brief Affecte un vecteur à un autre
     * @param v Le vecteur à copier
     * @return Une référence au vecteur affecté
     */
    Vecteur& operator = (const Vecteur& v);

    /**
     * @brief Récupère la coordonnée X du vecteur
     * @return La coordonnée X
     */
    float GetX()const;

    /**
     * @brief Récupère la coordonnée Y du vecteur
     * @return La coordonnée Y
     */
    float GetY()const;

    /**
     * @brief Définit la coordonnée X du vecteur
     * @param e La nouvelle coordonnée X
     */
    void SetX(float e);

    /**
     * @brief Définit la coordonnée Y du vecteur
     * @param f La nouvelle coordonnée Y
     */
    void SetY(float f);

    /**
     * @brief Calcule la magnitude du vecteur
     * @return La magnitude
     */
    double Magnitude()const;

    /**
     * @brief Normalise le vecteur
     * @return Le vecteur normalisé
     */
    Vecteur Normalized() const;

    
};
//********************************BackUp************************************************************************
/*

      @brief Récupère l'angle du vecteur
      @return L'angle en radians
     
    double Recupangle()const;
*/
#endif
