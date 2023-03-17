#ifndef _VECTEUR
#define _VECTEUR

class Vecteur
{

    private :


    public: 
    double x;
    double y;
     /// @brief constructeur par défaut
     Vecteur();
     /// @brief constructeur par copie 
     Vecteur(double x,double y);
   
   
    /// @brief operateur pour ajouter deeux vecteur
    ///@param v1 vecteur
    
    Vecteur& operator + (const Vecteur &v1);
    
    /// @brief fonction fait la différence entre deux vecteur
    /// @param v1 vecteur
    
    Vecteur& operator - (const Vecteur &v1);

    Vecteur operator / (double scalar)const;

    Vecteur operator * (double scalar)const ;

    ///@brief recupere et retourne les données x et y 

    int GetX()const;

    int GetY()const;

    double magnitude()const;

    Vecteur normalized() const;

    double Recupangle()const;
    
    



};





#endif