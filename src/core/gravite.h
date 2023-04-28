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
    void ActualiseBalleViaDiv(Balle& b) const;
    void ActualiseMouv(Balle& b)const;
    void ActualiseAdri(Balle& b)const;
    void ActualiseDirections(Balle& b)const;
    void ClearDirections(Balle& b)const;
    void SetPow(int pow);
    void SetAng(int ang);
    int GetAngle()const;
    int GetPow()const;
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

inline int Gravite :: GetPow() const {return Power;}
inline int Gravite :: GetAngle() const {return Angle;}









#endif

//********************************BackUp************************************************************************
/*
    void ActualiseDivise(Balle& b) const;
    void ActualiseVecteur(Balle& b) const;
void accelerationBalle();
*/