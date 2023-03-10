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

    void actualiseVecteur(Balle b);

    float angleChoisis(const char touche);


    void accelerationBalle();




};









#endif