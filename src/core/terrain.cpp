#include "terrain.h"
#include<cassert>


Terrain :: Terrain()
{
    DimX=20;
    DimY=20;
     //rempli le contour du terrain, d'obstacle
    for(unsigned int k = 0;k<DimX;k++)
    {
        tab[0][k]=new Obstacle;
    }
    for(unsigned int k = 1;k<DimX;k++)
    {
        tab[k][0]=new Obstacle;
    }
    for(unsigned int k = 1;k<DimX;k++)
    {
        tab[k][DimY-1]=new Obstacle;
    }
    for(unsigned int k = 1;k<DimX-1;k++)
    {
        tab[DimX-1][k]=new Obstacle;
    }
   
        
        
    for(unsigned int i=1;i<DimX-1;i++)
    {
        for(unsigned int j=1;j<DimY-1;j++)
        {
           tab[i][j]=nullptr;
        }
    }
   
    
    
}
// création et destruction du terrain, tableau d'obstacle
Terrain :: ~Terrain()
{
    
    for(unsigned int i=0;i<DimX;i++)
    {
        for(unsigned int j=0;j<DimY;j++)
        {
            if(tab[i][j]!=nullptr)
            {
              delete tab[i][j];
              tab[i][j]=nullptr;
            }
            tab[i][j]=nullptr;
            
        }      

    }

    DimX=0;
    DimY=0;

}
// positionne des obstacles
void Terrain :: SetObstacle (unsigned int xmin,unsigned int ymin,unsigned int xmax,unsigned int ymax)
{
    assert(1<=xmin && xmax<DimX-1);
    assert(1<=ymin && ymax<DimY-1);
    for (unsigned int i=xmin;i<=xmax;i++)    
  {
    for(unsigned int j=ymin;j<=ymax;j++)
    {
        tab[i][j]= new Obstacle; 
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
    for(unsigned int i=1;i<ter.getDimx()-1;i++)
    {
        for(unsigned int j=1;j<ter.getDimy()-1;j++)
        {
            assert(tab[i][j]==nullptr);
        }
    }
    
    ter.SetObstacle(2,2,3,3);
    assert(ter.getXY(2,2)!=nullptr);

    
    
}






