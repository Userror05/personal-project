#ifndef _GRAVITE
#define _GRAVITE

#include"balle.h"

class Gravite
{

    private:
    Balle jp;
    

    public:
    
    float g = -9.81;

    double Power; 

    double Angle;

    

    void actualiseVecteur(Balle& b);

    

    double RecupA();

    double RecupB();
    double ConversionAng();

    double ConversionX();

    double ConversionY();

    Vecteur& Vitesse(Balle& b);

    

    /*void accelerationBalle();*/

    void AffAng();

    void AffPR();
    

    Balle& GetBalle();

    void TestRegression();


};

inline  Balle& Gravite :: GetBalle(){ return jp;}







#endif