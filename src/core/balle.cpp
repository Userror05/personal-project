#include "balle.h"
#include <iostream>
#include<cassert>

Balle :: Balle ()
{
    SetX(2);
    SetY(2); //valeur au pif pour l'instant
    Vecteur g(0,-1);
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



void Balle :: AffPosition()
{
   std::cout<<"("<<GetX()<<","<<GetY()<<")" << std ::endl;
}

void Balle :: AffVitesse()
{
   std::cout<<"vitesse  :  "<<vitesse.GetX()<<"  ;  "<<vitesse.GetY()<<std ::endl;
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



void Balle :: TestRegression()
{
    Balle b;
    assert(b.GetX()==2 && b.GetY()==2);
    assert(b.vitesse.GetX()==0);
    b.InitMouvement();
    assert(b.mouvement.GetX()==b.vitesse.GetX());
    //assert(b.mouvement == v && b.vitesse == v );
    
}