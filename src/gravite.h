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

    void graviteConstante (Balle& b);

    void actualiseVecteur(Balle& b);

    float angleChoisis();

    double RecupA();

    double RecupB();

    double ConversionX();

    double ConversionY();

    int GetPuis();

    void accelerationBalle();

    

  //const Terrain& GetTerrain();


};


// inline const Terrain& Gravite :: GetTerrain() {return ter;}






#endif