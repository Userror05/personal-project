#include "terrain.h"
#include<cassert>


Terrain :: Terrain()
{
    DimX=0;
    DimY=0;
    tab[200][200]=nullptr;
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
void Terrain :: SetCellule (int x,int y, const Cellule& c)
{
    assert(0<=x && x<DimX);
    assert(0<=y && y<DimY);
    tab[y*200 + x]=c;

}

Cellule& Terrain:: GetCellule()