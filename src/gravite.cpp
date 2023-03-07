#include"src/gravite.h"
#include"math.h"
#include<cassert>

void gravite :: gravite (Balle b)
{
     
     //velocity += g * dt;




}


float gravite :: angleChoisis(const char touche)
{
    float angle = 45;
    switch (touche)
    {
    case touche='z'/* constant-expression */:

        while (angle<90){angle=angle+1.0;}

        break;

    case touche='s'

    while(angle>0){angle=angle-1.0;}

    default:
        break;
    }

    assert(angle<90);
    assert(angle>0);

    return angle;
} 

void gravite :: accelerationBalle()
{

    //pas sur a propos de ce qui est écris ci-dessous, ce que je veux traduire une accélération en vecteur avec un angle choisis, et le veceteur qui appartient a la balle 
    Balle b;
    b.mouvement.GetX()*cos(angleChoisis(touche));
    b.mouvement.GetY()*sin(angleChoisis(touche));
}


