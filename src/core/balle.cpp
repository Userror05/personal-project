#include "balle.h"
#include<iostream>
#include<cassert>

Balle :: Balle ()
{
    SetX(3);
    SetY(21); //valeur au pif pour l'instant
    Vecteur g(0,+1);
    gravite = g;
    Vecteur Vec(0.0,0.0);
    vitesse=Vec;
    mouvement=vitesse;
    divise=vitesse;
    adrien=divise;
    Vecteur dr1(1,0);
    drXP=dr1;
    Vecteur dr2(-1,0);
    drXM=dr2;
    Vecteur dr3(0,1);
    drYP=dr3;
    Vecteur dr4(0,-1);
    drYM=dr4;
    pos_x2=GetX()+1;
    pos_x3=GetX();
    pos_x4=GetX()+1;
    pos_y2=GetY();
    pos_y3=GetY()+1;
    pos_y4=GetY()+1;

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
   std::cout<<"balle:"<<"("<<GetX()<<","<<GetY()<<")" << std ::endl;
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
   std::cout<<"INITMOUV: "<<mouvement.GetX()<<";"<<mouvement.GetY()<<std::endl;
}

void Balle :: MoinsHuitMille()
{
    divise.SetX((mouvement.GetX())/50);
    divise.SetY((mouvement.GetY())/50);
}//Cette fonction implémente la valeur de mouvement divisé par 50 dans le vecteur divise

void Balle :: InverseX()
{
    float x1=divise.GetX();
    float x3=mouvement.GetX();
    divise.SetX(-x1);
    mouvement.SetX(-x3);
   
}

void Balle :: InverseY()
{
    float x2=divise.GetY();
    float x4=mouvement.GetY();
    divise.SetY(-x2);
    mouvement.SetY(-x4);
}

void Balle :: ActualisePosition()
{
    pos_x2=GetX()+1;
    pos_x3=GetX();
    pos_x4=GetX()+1;
    pos_y2=GetY();
    pos_y3=GetY()+1;
    pos_y4=GetY()+1;
}

void Balle :: TestRegression()
{
    Balle b;
    assert(b.GetX()==2 && b.GetY()==2);
    assert(b.vitesse.GetX()==0);
    b.InitMouvement();
    assert(b.mouvement.GetX()==b.vitesse.GetX());
    
    
}
