#include "terrain.h"
#include<cassert>


Terrain :: Terrain()
{
    tab=nullptr;
}
// création et destruction du terrain, tableau de cellule
Terrain :: ~Terrain()
{
    DimX=0;
    DimY=0;
    delete[]tab;
    tab == nullptr;

}
// positionne des obstacles
void Terrain :: SetObstacle (int xmin,int ymin,int xmax, int ymax,const Obstacle& c)
{
    assert(0<=xmin && xmax<DimX);
    assert(0<=ymin && ymax<DimY);
    for (unsigned int i=xmin;i<=xmax;i++)    
  {
    for(unsigned int j=ymin;j<=ymax;j++)
    {
        tab[i*xmax+j] ;//tab[i][j]; ///u= new Obstacle[ymax]; //improvisation
    }
  }

}

void Terrain :: ArrangementTrajectoire()
{
    if (Collision())
    {
        gr.GetBalle().mouvement.SetX(gr.GetBalle().mouvement.GetX());
    }
    if (Collision()&& gr.GetBalle().mouvement.GetY()<0)
    {
         gr.GetBalle().mouvement.SetY(-gr.GetBalle().mouvement.GetY());
    }


}

bool Terrain :: Collision()
{
    int x = (int)gr.GetBalle().GetX();
    int y = (int)gr.GetBalle().GetY();
    if (tab[y*DimX+x]!= nullptr)return true;
    else return false;
}







