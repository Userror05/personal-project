#include"gravite.h"
#include"math.h"
#include<cassert>
#include<iostream>
#include<unistd.h>


void Gravite::actualiseVecteur(Balle& b)
{
    float coef=0.9;
           // b.mouvement= (b.mouvement + b.mouvement)*coef;
            b.mouvement.SetX((b.mouvement.GetX()+b.gravite.GetX())*coef);
            b.mouvement.SetY((b.mouvement.GetY()+b.gravite.GetY())*coef);
            b.SetX(b.GetX()+b.mouvement.GetX());
            b.SetY(b.GetY()+b.mouvement.GetY());
            usleep(1000000);
            std::cout<<"mouv:"<<"("<<b.mouvement.GetX()<<","<<b.mouvement.GetY()<<")";
            
            b.AffPosition();

//avant while(!ter.collision)
    
}





/*
void Gravite :: accelerationBalle()
{

    //pas sur a propos de ce qui est écris ci-dessous, ce que je veux traduire une accélération en vecteur avec un angle choisis, et le veceteur qui appartient a la balle 
    Balle b;
    //b.mouvement.GetX()*cos(angleChoisis(touche));
    //b.mouvement.GetY()*sin(angleChoisis(touche));
}
*/

// a optimiser poour pouvoir utiliser SDL

double Gravite :: RecupA()
{
    double a;
    a=cos(Angle);
    std::cout<<" "<<a<<" ";
     return a;

}

double Gravite :: RecupB()
{
    double b;
    b=sin(ConversionAng());
    std::cout<<" "<<b<<" ";
    return b;
}

double Gravite :: ConversionAng()
{
    double c;
    c=(Angle*3.141592653589)/180;
    return c;
}


// pour otenir langle et le vecteur adéquate en fonction de l'angle que l'on a choisi
double Gravite :: ConversionX()
{
    return(Power*RecupA());

}

double Gravite :: ConversionY()
{
    return(Power*RecupB());
}

Vecteur& Gravite :: Vitesse(Balle& b)
{
    Vecteur v (ConversionX(),ConversionY());
    return(b.vitesse=v);
}



void Gravite :: AffPR ()
{
    std :: cout << "La puissance est de " << Power;
}

void Gravite :: AffAng()
{
    std :: cout << "l'angle est de " << Angle << "°";
}

void Gravite :: TestRegression()
{
    Balle b;
    AffAng();
    AffPR();
    float x =b.mouvement.GetX();
    actualiseVecteur(b);
    assert(b.mouvement.GetX()!=x);assert(b.mouvement.GetY()!=x);
    AffAng();
    AffPR();
    
}