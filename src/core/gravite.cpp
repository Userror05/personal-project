#include"gravite.h"
#include"math.h"
#include<cassert>
#include<iostream>
#include<unistd.h>



Gravite :: Gravite ()
{
    Angle = 45;
    Power = 5;
}

void Gravite::actualiseVecteur(Balle& b)const
{
    float coef=0.9;
            b.Sauvegarde.SetX(b.mouvement.GetX());

            b.Sauvegarde.SetY(b.mouvement.GetY());

           // b.mouvement= (b.mouvement + b.mouvement)*coef;

            b.mouvement.SetX((b.mouvement.GetX()+b.gravite.GetX())*coef);

            b.mouvement.SetY((b.mouvement.GetY()+b.gravite.GetY())*coef);

            //b.SetX(b.GetX()+b.mouvement.GetX());
            //b.SetY(b.GetY()+b.mouvement.GetY());
           
           
            //usleep(1000000);

            std::cout<<"mouv:"<<"("<<b.mouvement.GetX()<<","<<b.mouvement.GetY()<<")";
            
            b.AffPosition();


    
}
void Gravite::actualiseVecteurV2(Balle& b)const
{
            // b.mouvement= (b.mouvement + b.mouvement)*coef;

           // b.divise.SetX((b.divise.GetX()+b.divise.GetX()));

           // b.divise.SetY((b.divise.GetY()+b.divise.GetY()));

            b.SetX(b.GetX()+b.divise.GetX());
            b.SetY(b.GetY()+b.divise.GetY());
           
           
            //usleep(1000000);

            std::cout<<"diviser:"<<"("<<b.divise.GetX()<<","<<b.divise.GetY()<<")";
            
            b.AffPosition();


    
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
    a=cos(ConversionAng());
    /*std::cout<<" "<<a<<" "<<"le_return:_";*/
     return a;

}

double Gravite :: RecupB()
{
    double b;
    b=sin(ConversionAng());
    /*std::cout<<" "<<b<<" "<<"le_return:_";*/
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
    Vecteur v (ConversionX(),-ConversionY());
    return(b.vitesse=v);
}



void Gravite :: AffPR ()
{
    std :: cout << "La puissance est de " << Power<< std :: endl;
}

void Gravite :: AffAng()
{
    std :: cout << "l'angle est de " << Angle << "°"<<std :: endl;
}

void Gravite :: TestRegression()
{
    Balle b;
    AffAng();
    AffPR();
    float x = b.mouvement.GetX();
    std :: cout << x;
    float y = b.mouvement.GetY();
    float ang = ConversionAng();
    assert(ang!= Angle);
    
    b.AffPosition();

    AffAng();
    AffPR();
    
    
    Vitesse(b);
    std :: cout << b.vitesse.GetX() << std :: endl;
    b.InitMouvement();std :: cout << b.mouvement.GetX() << std :: endl;
    actualiseVecteur(b);

    std :: cout << b.mouvement.GetX();

    assert(x!=b.mouvement.GetX());assert(b.mouvement.GetY()!=y);
    
    
}