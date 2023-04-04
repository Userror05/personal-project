#include "terrain.h"
#include<cassert>


Terrain :: Terrain()
{
    DimX=20;
    DimY=20;
    for(int i=0;i<DimX;i++)
    {
        for(int j=0;j<DimY;j++)
        {
           tab[i][j]=nullptr;
        }
    }
}
// création et destruction du terrain, tableau de cellule
Terrain :: ~Terrain()
{
    
    for(int i=0;i<DimX;i++)
    {
        for(int j=0;j<DimY;j++)
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
void Terrain :: SetObstacle (unsigned int xmin,unsigned int ymin,unsigned int xmax,unsigned int ymax,const Obstacle& c)
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
    if (getXY(x,y)!= nullptr)return true;
    else return false;
}


void Terrain :: TestRegression()
{
    Terrain ter;
    const Obstacle c;
    assert(ter.getDimx()==ter.getDimy());
    for(unsigned int i=0;i<ter.getDimx();i++)
    {
        for(unsigned int j=0;j<ter.getDimy();j++)
        {
            assert(tab[i][j]==nullptr);
        }
    }
    
    ter.SetObstacle(1,1,3,3,c);
    assert(ter.getXY(2,2)!=nullptr);
    
}





