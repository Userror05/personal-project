#ifndef _TERRAIN_H
#define _TERRAIN_H


#include"obstacle.h"
#include"gravite.h"
#include<cassert>

//tableau de type cellule pointeur 

class Terrain 
{
    private:
      
     
      unsigned int DimX; 
      unsigned int DimY;
      //enum TypeCellule { Balle='B', Obstacle='O', Cellule='#',SPACE=' ' };

       Gravite gr;
       
      
       Obstacle * tab[20][20];
       

    public:

    
     Terrain(); // constructeur par defaut 
     
     ~Terrain(); // destructeur par défaut 
    
    
     void SetObstacle(unsigned int xmin,unsigned int ymin,unsigned int xmax,unsigned int ymax,const Obstacle& c);

     bool Collision();

     void ArrangementTrajectoire(); 

     void TestRegression();

     int getDimx()const;

     int getDimy() const;
     
     Gravite& getGravite();

     Obstacle* getXY (const int x, const int y) const;

     //Obstacle GetObs(int x, int y)const;

     bool positionValide(Cellule evaluee);//bool

     //bool CollectionItem(Item I,Balle B);

     //bool PositionBallevalide(Balle B);

     //bool CollisionObstacle(Obstacle O,Balle B);

};

inline Obstacle * Terrain::getXY (const int x, const int y) const {
	assert(x>=0);
	assert(y>=0);
	assert(x<DimX);
	assert(y<DimY);
	return tab[x][y];
}

inline int Terrain :: getDimx()const{return DimX;}

inline int Terrain :: getDimy()const{return DimY;}

inline Gravite& Terrain :: getGravite(){return gr;}


#endif
