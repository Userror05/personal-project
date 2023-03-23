#include "cellule.h"



Cellule::Cellule()
{  pos_x=0;
   pos_y=0;
}


void Cellule::SetX(unsigned int x)
{  pos_x=x;}


void Cellule::SetY(unsigned int y)
{ pos_y=y;}

unsigned int Cellule::GetX()const
{ return pos_x;}

unsigned int Cellule::GetY()const
{ return pos_y;}


Cellule& Cellule::operator = (const Cellule& c)
{
   pos_x=c.pos_x;
   pos_y=c.pos_y;
   return *this;
}