#include "cellule.h"



Cellule::Cellule()
{  pos_x=0;
   pos_y=0;
   largeur=0;
   longueur=0;
}

Cellule::~Cellule()
{}
void Cellule::SetX(int x)
{  pos_x=x;}


void Cellule::SetY(int y)
{ pos_y=y;}


void Cellule::SetLargeur(int l)
{ largeur=l;}

void Cellule::SetLongueur(int L)
{ longueur = L;}


unsigned int Cellule::GetX()
{ return pos_x;}

unsigned int Cellule::GetY()
{ return pos_y;}

unsigned int Cellule::GetLargeur()
{ return largeur;}

unsigned int Cellule :: GetLongueur()
{ return longueur;}
