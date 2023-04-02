#include "terrain.h"
#include<cassert>


Terrain :: Terrain()
{
    DimX=20;
    DimY=20;
    tab[DimX][DimY]=nullptr;
}
// création et destruction du terrain, tableau de cellule
Terrain :: ~Terrain()
{
    
    for(int i=0;i<=DimX;i++)
    {
        for(int j=0;j<=DimY;j++)
        {
            delete tab[i][j];
        }
        

    }
    tab[DimX][DimY] = nullptr;
    DimX=0;
    DimY=0;

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
        tab[i][j]= new Obstacle; //improvisation
    }
  }

}

void Terrain :: ArrangementTrajectoire()
{
    Balle b = gr.GetBalle();
    if (Collision())
    {
        
        b.mouvement.SetX(gr.GetBalle().mouvement.GetX());
    }
    if (Collision()&& gr.GetBalle().mouvement.GetY()<0)
    {
        float y=gr.GetBalle().mouvement.GetY();
         b.mouvement.SetY(-y);
    }


}

bool Terrain :: Collision()
{
    int x = (int)gr.GetBalle().GetX();
    int y = (int)gr.GetBalle().GetY();
    if (tab[x][y]!= nullptr)return true;
    else return false;
}


void Terrain :: TestRegression()
{
    Terrain ter;
    const Obstacle c;
    assert(ter.getDimx()==ter.getDimy());
    assert(tab[20][20]==nullptr);
    ter.SetObstacle(1,1,3,3,c);
    assert(ter.getXY(2,2)!=nullptr);
    
}





