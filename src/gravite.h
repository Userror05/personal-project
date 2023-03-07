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
    float g =9.81;

    public:

    void gravite(Balle b);


    float angleChoisis(const char touche);


    void accelerationBalle();




};









#endif