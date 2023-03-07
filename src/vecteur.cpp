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


Vecteur& Vecteur::operator + ( const Vecteur &v1)
{
    x = x + v1.x;
    y = y + v1.y;

    return *this;


}
// mettres des asserts partout 
Vecteur& Vecteur ::operator - (const Vecteur &v1)
{ 

     x = x - v1.x;
     y = y - v1.y; 

     return *this;


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

Vecteur& Vecteur::operator = (const Vecteur& v)
{
   x=v.x;
   y=v.y;
   return *this;
}