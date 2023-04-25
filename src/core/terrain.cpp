#include "terrain.h"
#include<cassert>
#include<iostream>


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

void Terrain :: ArrangementTrajectoire(Balle& b)
{
    float a= b.divise.GetX();
    float c= b.divise.GetY();
    gr.actualiseDirections(b);
    if (a<0 && c<0) // cas jaune (bas gauche)
    {
        if (CollisionVect(b.drXM)==true && CollisionVect(b.drYP)==true && CollisionVect(b.drYM)==true)//bas gauche -> bas droite
        {
            //inverse le x
            b.InverseX();
        }
        
        else //bas gauche -> haut gauche
        {
            //inverse le y
            b.InverseY();
           // b.mouvement.SetY(b.mouvement.GetY()+1);
        }
    }
    if (a>0 && c<0) // cas violet
    {
        if (CollisionVect(b.drXM)==true && CollisionVect(b.drXP)==true && CollisionVect(b.drYM)==true)//bas droite -> haut droite
        {
            //inverse le y
            b.InverseY();
            //b.mouvement.SetY(b.mouvement.GetY()+1);
        }
        else //bas droite -> bas gauche 
        {
            //inverse le X
            b.InverseX();
        }
    }
    if (a<0 && c>0) // cas bleu
    {
        if (CollisionVect(b.drXM)==true && CollisionVect(b.drYP)==true && CollisionVect(b.drYM)==true)//haut gauche -> haut droite 
        {
            //inverser le x
            b.InverseX();
        }
        else //haut gauche -> bas gauche 
        {
            //inverse le y
            b.InverseY();
        }
    }
    if (a>0 && c>0) // cas rose
    {
        if (CollisionVect(b.drXP)==true && CollisionVect(b.drYP)==true && CollisionVect(b.drYM)==true)//haut droite -> haut gauche
        {
            //inverse le x
            b.InverseX();
        }
        else //haut droite -> bas droite 
        {
            //inverse le y
            b.InverseY();
        }
    }

    gr.ClearDirections(b);
}

    
    
    
    
    
    
    
    
    
    /*if (Collision(b))
    {
        
        b.divise.SetX(b.divise.GetX());
    }
    if (Collision(b)&& b.divise.GetY()<0)
    {
        float y=b.divise.GetY();
         b.divise.SetY(-y);
         float ym=b.mouvement.GetY()/2;
         std::cout<<"collision!"<<std::endl;
         std::cout<<"mouv avant changement:"<<"("<<b.mouvement.GetX()<<","<<b.mouvement.GetY()<<")" << std ::endl;
        b.mouvement.SetY(-ym);
        std::cout<<"mouv avant changement:"<<"("<<b.mouvement.GetX()<<","<<b.mouvement.GetY()<<")" << std ::endl;
    }
*/


bool Terrain :: CollisionBalle(Balle& b)
{
    float x = b.GetX();
    float y = b.GetY();
    if (getXY(x,y)!= nullptr)return true;
    else return false;
}

bool Terrain :: CollisionVect(Vecteur& v)
{
    float x = v.GetX();
    float y = v.GetY();
    if (getXY(x,y)!= nullptr)return true;
    else return false;
}
/* La fonction getXY ici:
inline Obstacle * Terrain::getXY (unsigned int x, unsigned int y) const {
	assert(x>=0);
	assert(y>=0);
	assert(x<DimX);
	assert(y<DimY);
	return tab[x][y];
}
*/

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
    
    const Balle& b = ter.GetBalle();


    
    std :: cout<<b.GetX(); std :: cout << b.GetY();

    
    
}




