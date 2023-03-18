#ifndef _BALLE_H
#define _BALLE_H
#include"vecteur.h"
#include"gravite.h"
#include"cellule.h"
#include"terrain.h"

class Balle 
{
    private:

    double pos_x,pos_y;
    Terrain ter;
   


    public:
    
    Vecteur mouvement;
    Vecteur vitesse;
    Vecteur gravite;

    Balle();

    double GetX();
    double GetY();
    void SetX(double x);
    void SetY(double y);
    bool ArrangementTrajectoire();
    void ActionJoueur();
    bool Rejouer(Vecteur v, Balle b);
    



};



#endif
