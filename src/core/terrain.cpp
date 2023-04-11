#include "terrain.h"
#include<cassert>


Terrain :: Terrain()
{
    DimX=20;
    DimY=20;
    for(unsigned int i=0;i<DimX;i++)
    {
        for(unsigned int j=0;j<DimY;j++)
        {
           tab[i][j]=nullptr;
        }
    }
}
// création et destruction du terrain, tableau de cellule
Terrain :: ~Terrain()
{
    
    for(unsigned int i=0;i<DimX;i++)
    {
        for(unsigned int j=0;j<DimY;j++)
        {
            if(tab[i][j]!=nullptr)
            {
              delete tab[i][j];
            }
            
        }      

    }

    DimX=0;
    DimY=0;

}
// positionne des obstacles
void Terrain :: SetObstacle (unsigned int xmin,unsigned int ymin,unsigned int xmax,unsigned int ymax)
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
    Balle b = jp;
    if (Collision())
    {
        
        b.mouvement.SetX(jp.mouvement.GetX());
    }
    if (Collision()&& jp.mouvement.GetY()<0)
    {
        float y=jp.mouvement.GetY();
         b.mouvement.SetY(-y);
    }


}

bool Terrain :: Collision()
{
    int x = (int)jp.GetX();
    int y = (int)jp.GetY();
    if (getXY(x,y)!= nullptr)return true;
    else return false;
}


void Terrain :: TestRegression()
{
    Terrain ter;
    
    assert(ter.getDimx()==ter.getDimy());
    for(unsigned int i=0;i<ter.getDimx();i++)
    {
        for(unsigned int j=0;j<ter.getDimy();j++)
        {
            assert(tab[i][j]==nullptr);
        }
    }
    
    ter.SetObstacle(1,1,3,3);
    assert(ter.getXY(2,2)!=nullptr);
    
}





