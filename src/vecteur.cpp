#include "vecteur.h"
#include"math.h"

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
    return ;
}
/// possible problem de mémoire avec  des échanges lourds; penser a le modifier 

Vecteur& Vecteur::operator = (const Vecteur& v)
{
   x=v.x;
   y=v.y;
   return *this;
}

Vecteur& Vecteur ::operator / (double scalar) const {
        return Vecteur(x / scalar, y / scalar);
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