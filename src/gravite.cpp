#include"src/gravite.h"
#include"math.h"
#include"vecteur.h"
#include<cassert>
#include"SDL2/SDL.h"

void gravite :: gravite (Balle B)
{

     //velocity += g * dt;

}


float gravite :: angleChoisis(const char touche)
{
    float angle = 45;
    switch (touche)
    {
    case touche='z'/* constant-expression */:

        while (angle<=90){angle=angle+1.0;};

        break;

    case touche='s':

    while(angle>=0){angle=angle-1.0;}

    default:
        break;
    };

    assert(angle=<90);
    assert(angle>=0);

    return angle;
} 


//
Vecteur gravite :: accelerationBalle()
{

    //pas sur a propos de ce qui est écris ci-dessous, ce que je veux traduire une accélération en vecteur avec un angle choisis, et le veceteur qui appartient a la balle 
    Balle b;
    b.mouvement.GetX()*cos(angleChoisis(touche));
    b.mouvement.GetY()*sin(angleChoisis(touche));
}


// a optimiser poour pouvoir utiliser SDL

double gravite :: RecupA()
{
    double a;

    a=cos(angleChoisis(touche));
    
     return a;

}

double gravite :: RecupB()
{
    double b;

    b=sin(angleChoisis(touche));

    return b;
}


double gravite :: ConversionX()
{
    return(x=GetPuis()*RecupA());

}

double gravite :: ConversionY()
{
    return(y=GetPuis()*RecupB());
}


double gravite :: GetPuis()
{

    int max=90;

    
    while(pui<max)
    {



    }


}