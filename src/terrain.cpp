#include "terrain.h"
#include<cassert>


Terrain :: Terrain()
{
    DimX=20;
    DimY=20;
    tab[DimX][DimY];
}
// création et destruction du terrain, tableau de cellule
Terrain :: ~Terrain()
{
    DimX=0;
    DimY=0;
    delete[]tab;
    tab == nullptr;

}
// positionne des cellules
void Terrain :: SetCellule (int x,int y,const Cellule& c)
{
    assert(0<=x && x<DimX);
    assert(0<=y && y<DimY);
    tab[x][y]=c;

}

Cellule Terrain :: GetCellule(int x, int y)const
{
    return tab[x][y];

}











bool Terrain :: Collision()
{
    if (player.GetX()

}

void Terrain :: ArrangementTrajectoire()
{
    if (Collision()) player.ArrangementTrajectoire();
}