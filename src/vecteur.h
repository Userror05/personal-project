#ifndef _VECTEUR
#define _VECTEUR

class Vecteur
{

    private :


    public: 
    int x;
    int y;
     /// @brief constructeur par défaut
     Vecteur();
     /// @brief constructeur par copie 
     Vecteur(int x,int y);
   
   
    /// @brief operateur pour ajouter deeux vecteur
    ///@param v1 vecteur
    
    Vecteur& operator + (const Vecteur &v1);
    
    /// @brief fonction fait la différence entre deux vecteur
    /// @param v1 vecteur
    
    Vecteur& operator - (const Vecteur &v1);

    ///@brief recupere et retourne les données x et y 

    int GetX()const;

    int GetY()const;





};





#endif