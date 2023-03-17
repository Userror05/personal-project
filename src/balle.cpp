#include "balle.h"

Balle :: Balle ()
{
    balle.SetX(10);
    balle.SetY(10);
    Vecteur v(0,0);
    mouvement(0,0);
    gravite(-9.81)
}



int Balle :: GetX()
{
    balle.GetX();
}

int Balle :: GetY()
{
    balle.GetY();
}


bool Balle :: ArrangementTrajectoire()
{
    return ter.Collision();
}