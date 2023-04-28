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

void Gravite::ActualiseBalleViaDiv(Balle& b)const
{
    b.SetX(b.GetX()+b.divise.GetX());
    b.SetY(b.GetY()+b.divise.GetY());
    b.AffPosition();
}

void Gravite::ActualiseMouv(Balle& b)const
{
    float coef=0.9;
    b.mouvement.SetX((b.mouvement.GetX()+b.gravite.GetX())*coef);
    b.mouvement.SetY((b.mouvement.GetY()+b.gravite.GetY())*coef);
}

void Gravite::ActualiseAdri(Balle& b)const
{
    b.adrien.SetX(b.divise.GetX()+b.GetX());
    b.adrien.SetY(b.divise.GetY()+b.GetY());
}
void Gravite::ActualiseDirections(Balle& b)const
{
    b.drXP.SetX(b.drXP.GetX()+b.adrien.GetX());
    b.drXP.SetY(b.drXP.GetY()+b.adrien.GetY());
    b.drXM.SetX(b.drXM.GetX()+b.adrien.GetX());
    b.drXM.SetY(b.drXM.GetY()+b.adrien.GetY());
    b.drYP.SetX(b.drYP.GetX()+b.adrien.GetX());
    b.drYP.SetY(b.drYP.GetY()+b.adrien.GetY());
    b.drYM.SetX(b.drYM.GetX()+b.adrien.GetX());
    b.drYM.SetY(b.drYM.GetY()+b.adrien.GetY());
}
void Gravite::ClearDirections(Balle& b)const
{
    b.drXP.SetX(1);
    b.drXP.SetY(0);
    b.drXM.SetX(-1);
    b.drXM.SetY(0);
    b.drYP.SetX(0);
    b.drYP.SetY(1);
    b.drYM.SetX(0);
    b.drYM.SetY(-1);
}

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
    return -b;
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
    //ActualiseVecteur(b);

    std :: cout << b.mouvement.GetX();

    assert(x!=b.mouvement.GetX());assert(b.mouvement.GetY()!=y);
    
    
}
//********************************BackUp************************************************************************
/*


void Gravite :: accelerationBalle()
{

    //pas sur a propos de ce qui est écris ci-dessous, ce que je veux traduire une accélération en vecteur avec un angle choisis, et le veceteur qui appartient a la balle 
    Balle b;
    //b.mouvement.GetX()*cos(angleChoisis(touche));
    //b.mouvement.GetY()*sin(angleChoisis(touche));
}


// a optimiser poour pouvoir utiliser SDL

dans actualise vecteur 2: // b.mouvement= (b.mouvement + b.mouvement)*coef;

           // b.divise.SetX((b.divise.GetX()+b.divise.GetX()));

           // b.divise.SetY((b.divise.GetY()+b.divise.GetY()));
            //usleep(1000000);

            //std::cout<<"divisé:"<<"("<<b.divise.GetX()<<","<<b.divise.GetY()<<")";



void Gravite::ActualiseVecteur(Balle& b)const
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

*/