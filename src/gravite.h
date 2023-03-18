#ifndef _GRAVITE
#define _GRAVITE

#include"vecteur.h"
#include"terrain.h"
#include"cellule.h"
#include"balle.h"

class Gravite
{

    private:

    
    Terrain ter;
    
    

    public:
    
    float g = -9.81;

    double Power; 

    float Angle;

    void graviteConstante (Balle& b);

    void actualiseVecteur(Balle& b);

    void angleChoisis();

    double RecupA();

    double RecupB();

    double ConversionX();

    double ConversionY();

    Vecteur Vitesse(Balle& b);

    void GetPuis();

    void accelerationBalle();

    void AffAng();

    void AffPR();
    
    void InitMouvement(Balle& b);

  //const Terrain& GetTerrain();


};


// inline const Terrain& Gravite :: GetTerrain() {return ter;}






#endif