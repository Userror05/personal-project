#include "balle.h"

Balle :: Balle ()
{
    SetX(10);
    SetY(10); //valeur au pif pour l'instant
    gravite(0.0,-9.81);
    vitesse(0.0,0.0);
    mouvement= Vecteur v(0,0);
}



double Balle :: GetX() 
{
    return pos_x;
}

double Balle :: GetY()
{
    return pos_y;
}


void Balle :: SetX(double x)
{
    pos_x=x;

}


void Balle :: SetY(double y)
{
    pos_y=y;
}

bool Balle :: ArrangementTrajectoire()
{
    return ter.Collision();
}

void Balle :: ActionJoueur()
{
    angleChoisis();
    GetPuis();
    Vitesse();
    InitMouvement(B);
    while(!Rejouer(B.mouvement,B))
    {
        actualiseVecteur(B);
    }
    
}

bool Balle :: Rejouer(Vecteur v,Balle b)
{
    if(v.GetX()==b.GetX() && v.GetY()==b.GetY())
    {
        return true;
    }
    else return false;
}

void Balle :: ActionJoueurVisuel()
{
    angleChoisis();
    AffAng();
    GetPuis();
    AffPR();
    Vitesse();
    InitMouvement(B);
    while(!Rejouer(B.mouvement,B))
    {
        actualiseVecteur(B);
        AffPosition();
    }
   
}

void Balle :: AffPosition()
{
    cout<<"("<<pos_x<<","<<pos_y<<")";
}