#include "vecteur.h"

Vecteur::Vecteur ()
{
    x=0;
    y=0;
}

Vecteur::Vecteur(int a, int b)
{
    x=a;
    y=b;
}


void Vecteur::ajouterVecteur( Vecteur v1)
{
    x = x + v1.x;
    y = y + v1.y;


}
// mettres des asserts partout 
void Vecteur :: retirerVecteur(Vecteur v1)
{ 

     x = x - v1.x;
     y = y - v1.y;


}

int Vecteur:: GetX() const
{
    return x;
}

int Vecteur :: GetY() const 
{
    return y;
}
/// possible problem de mémoire avec  des échanges lourds; penser a le modifier 