#include "balle.h"
#include <iostream>

Balle :: Balle ()
{
    SetX(0);
    SetY(0); //valeur au pif pour l'instant
    Vecteur g(0,-2.81);
    gravite = g;
    Vecteur Vec(0.0,0.0);
    vitesse=Vec;
    mouvement=vitesse;
}



double Balle :: GetX()const 
{
    return pos_x;
}

double Balle :: GetY()const
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

/*bool Balle :: ArrangementTrajectoire()
{
    return ter.Collision();
}

void Balle :: ActionJoueur()
{
    Gravite gr;
    gr.angleChoisis();
    gr.GetPuis();
    gr.Vitesse();
    gr.InitMouvement(B);
    while(!Rejouer(mouvement,*this))
    {
        gr.actualiseVecteur(*this);
        
    }

}*/


void Balle :: AffPosition()
{
   std::cout<<"("<<GetX()<<","<<GetY()<<")";
}

void Balle :: AffVitesse()
{
   std::cout<<"vitesse"<<vitesse.GetX()<<";"<<vitesse.GetY();
}

void Balle :: InitMouvement()
{
    mouvement.SetX(vitesse.GetX());
    mouvement.SetY(vitesse.GetY());
}

void Balle :: AffInitMouvement()
{
   std::cout<<"INITMOUV: "<<mouvement.GetX()<<";"<<mouvement.GetY();
}
