#include "vecteur.h"
#include <math.h>

Vecteur::Vecteur ()
{
    x=0;
    y=0;
}

Vecteur::Vecteur(float a, float b)
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

float Vecteur:: GetX() const
{
    return x;
}

float Vecteur :: GetY() const 
{
    return y;
}

void Vecteur :: SetX(double e)
{
    x=e;

}


void Vecteur :: SetY(double f)
{
    y=f;
}
/// possible problem de mémoire avec  des échanges lourds; penser a le modifier 

Vecteur& Vecteur::operator = (const Vecteur& v)
{
   x=v.x;
   y=v.y;
   return *this;
}

Vecteur Vecteur::operator / (float scalar) const{
        return Vecteur (x / scalar, y / scalar);
    }

Vecteur Vecteur::operator * (float scalar) const{
        return Vecteur (x * scalar, y * scalar);
    }

double Vecteur :: magnitude()const 
{
  return sqrt(x*x + y*y);
}

Vecteur Vecteur :: normalized() const 
{
    double mag = magnitude();
        if (mag > 0) {
            return *this / mag;
        } else {
            return Vecteur(0, 0);
        }
        
     }


double Vecteur :: Recupangle()const
{
   double temp;
    temp = acos(x/magnitude());
    return temp;

}