#ifndef _BALLE_H
#define _BALLE_H
#include"vecteur.h"
#include"gravite.h"
#include"cellule.h"
#include"terrain.h"

class Balle 
{
    private:

    Cellule balle;
    Terrain ter;


    public:
    
    Vecteur position;
    Vecteur vitesse;
    Vecteur gravite;

    Balle();

    int GetX();
    int GetY();
    bool ArrangementTrajectoire();
    



};



#endif
