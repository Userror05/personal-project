#ifndef _GRAVITE
#define _GRAVITE

#include"balle.h"

class Gravite
{

    private:
   
    double Power; 

    double Angle;

    public:
    
    //float g = -9.81;


    Gravite();

    void actualiseVecteur(Balle& b) const;

    void SetPow(float pow);

    void SetAng(float ang);

    

    double RecupA();

    double RecupB();
    double ConversionAng();

    double ConversionX();

    double ConversionY();

    Vecteur& Vitesse(Balle& b);

    

    /*void accelerationBalle();*/

    void AffAng();

    void AffPR();
    

    

    void TestRegression();


};
inline void Gravite :: SetPow(float pow)
{   Power = pow;}
inline void Gravite :: SetAng(float ang)
{   Angle = ang;}








#endif