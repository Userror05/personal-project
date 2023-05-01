#include "terrain.h"
#include<cassert>
#include<iostream>
#include<string>
#include<fstream>


Terrain :: Terrain()
{
    DimX=60;
    DimY=32;
     //rempli le contour du terrain, d'obstacle
    for(unsigned int k = 0;k<DimY;k++)
    {
        tab[0][k]=new Obstacle;tab[0][k]->SelectType(1);
    }
    for(unsigned int k = 1;k<DimX;k++)
    {
        tab[k][0]=new Obstacle;tab[k][0]->SelectType(1);
    }
    for(unsigned int k = 1;k<DimX;k++)
    {
        tab[k][DimY-1]=new Obstacle;tab[k][DimY-1]->SelectType(1);
    }
    for(unsigned int k = 1;k<DimY-1;k++)
    {
        tab[DimX-1][k]=new Obstacle;tab[DimX-1][k]->SelectType(1);
    }
    

    for(unsigned int k = 1;k<DimY-1;k++)
    {
        tab[1][k]=new Obstacle;tab[1][k]->SelectType(1);
    }
    for(unsigned int k = 2;k<DimX-1;k++)
    {
        tab[k][1]=new Obstacle;tab[k][1]->SelectType(1);
    }
    for(unsigned int k = 2;k<DimX-1;k++)
    {
        tab[k][DimY-2]=new Obstacle;tab[k][DimY-2]->SelectType(1);
    }
    for(unsigned int k = 2;k<DimY-2;k++)
    {
        tab[DimX-2][k]=new Obstacle;tab[DimX-2][k]->SelectType(1);
    }
   
   
        
        
    for(unsigned int i=2;i<DimX-2;i++)
    {
        for(unsigned int j=2;j<DimY-2;j++)
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
            
            
        }      

    }

    DimX=0;
    DimY=0;

}
// positionne des obstacles
void Terrain :: SetObstacle (unsigned int xmin,unsigned int ymin,unsigned int xmax,unsigned int ymax, unsigned int type)
{
    assert(1<=xmin && xmax<DimX-1);
    assert(1<=ymin && ymax<DimY-1);
    assert(type==0 || type==1);

    for (unsigned int i=xmin;i<=xmax;i++)    
  {
    for(unsigned int j=ymin;j<=ymax;j++)
    {
        tab[i][j]= new Obstacle;tab[i][j]->SelectType(type); 
        
    }
  }

}

void Terrain :: ArrangementTrajectoire(Balle& b)
{
    float a= b.divise.GetX();
    float c= b.divise.GetY();
    gr.ActualiseDirections(b);
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

bool Terrain :: CollisionBalle(Balle& b)
{
    float x = b.GetX();
    float y = b.GetY();
    if (getXY(x,y)!= nullptr && getXY(x,y)->R)return true;
    else return false;
}

bool Terrain :: CollisionVect(Vecteur& v)
{
    float x = v.GetX();
    float y = v.GetY();
    if (getXY(x,y)!= nullptr)return true;
    else return false;
    /*debut de la nouvelle version:
     float x = v.GetX();
    float y = v.GetY();
    if (getXY(x,y)!= nullptr && getXY(x,y)->R)return true;
    else return false;*/
}

bool Terrain :: CollisionObsType0(Vecteur& v)
{
    float x = v.GetX();
    float y = v.GetY();
    if(getXY(x,y)!=nullptr)
    {
        if(getXY(x,y)->obs==getXY(x,y)->F)return true;
        else return false;
    }
}
bool Terrain :: CollisionObsType1(Vecteur& v)
{
    float x = v.GetX();
    float y = v.GetY();
    if(getXY(x,y)!=nullptr)
    {
        if(getXY(x,y)->obs==getXY(x,y)->R)return true;
        else return false;
    }
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
    
   
    for(unsigned int i=2;i<ter.GetDimx()-2;i++)
    {
        for(unsigned int j=2;j<ter.GetDimy()-2;j++)
        {
            assert(tab[i][j]==nullptr);
        }
    }
    
    
    if(ter.getXY(0,2)->R) std :: cout<<"je suis la";

    ter.SetObstacle(2,2,4,4,1);
    assert(ter.getXY(2,2)!=nullptr);
    if(ter.getXY(3,3)->F)
    {
        std::cout<<"c'est la ligne d'arrivée";
    }

    ter.getXY(3,3)->SelectType(1);
    if(ter.getXY(3,3)->obs==ter.getXY(3,3)->F){std::cout<<"peut etre le debut de la fin"<< std::endl;}


    ter.SetObstacle(10,10,12,12,0);
    if(ter.getXY(11,11)->R)
    {
        std::cout<<"c'est KKKKKKKKKK ";
    }

    
    
     Balle b ;


    


    
    std :: cout<<b.GetX(); std :: cout << b.GetY();

    
    
}


void Terrain ::Ouvrir(const std :: string & filename)
 {
 std :: ifstream fichier (filename.c_str());

    assert(fichier.is_open());

	unsigned int xmin,ymin,xmax,ymax,type;
	//std :: string mot;
	//dimX = dimY = 0;
	//fichier >> mot >> dimX >> dimY >> mot;
	
	//if (tab != NULL) delete [] tab;
	//tab = new Pixel [dimX*dimY];
	
    while(!fichier.eof())
	{
		fichier >> xmin >> ymin >> xmax >> ymax >> type;

    	assert(xmin > 0 && xmin<xmax && xmax < GetDimx());

		assert(ymin > 0 && ymin<ymax && ymax < GetDimy());

		SetObstacle(xmin,ymin,xmax,ymax,type);

		std :: cout << "obstacle posé à   "<<(xmax-xmin)<<" x "<<(ymax-ymin)<< std :: endl;
	}

    fichier.close();

    std :: cout << "Lecture de niveau  " << filename << " ... OK\n";
}


//********************************BackUp************************************************************************
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