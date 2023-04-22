#ifndef _GRAVITE
#define _GRAVITE

#include"balle.h"

class Gravite
{

    private:
   
    float Power; 

    int Angle;

    public:
    
    //float g = -9.81;


    Gravite();

    void actualiseVecteur(Balle& b) const;
    void actualiseVecteurV2(Balle& b) const;

    void SetPow(int pow);

    void SetAng(int ang);

    int Getangle()const;

    int Getpow()const;

    

    double RecupA();

    double RecupB();
    double ConversionAng();

    double ConversionX();

    double ConversionY();

    Vecteur& Vitesse(Balle& b);

    void AffAng();

    void AffPR();


    void TestRegression();


};
inline void Gravite :: SetPow(int pow)
{   Power = pow;}
inline void Gravite :: SetAng(int ang)
{   Angle = ang;}

inline int Gravite :: Getpow() const {return Power;}
inline int Gravite :: Getangle() const {return Angle;}









#endif