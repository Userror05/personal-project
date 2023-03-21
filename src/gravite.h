#ifndef _GRAVITE
#define _GRAVITE

#include"balle.h"

class Gravite
{

    private:
    
    

    public:
    
    float g = -9.81;

    double Power; 

    double Angle;

    /*void graviteConstante (Balle& b);*/

    void actualiseVecteur(Balle& b);

    /*void angleChoisis();*/

    double RecupA();

    double RecupB();
    double ConversionAng();

    double ConversionX();

    double ConversionY();

    Vecteur& Vitesse(Balle& b);

    /*void GetPuis();*/

    /*void accelerationBalle();*/

    void AffAng();

    void AffPR();
    

  //const Terrain& GetTerrain();


};


// inline const Terrain& Gravite :: GetTerrain() {return ter;}






#endif