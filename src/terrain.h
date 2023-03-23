#ifndef _TERRAIN_H
#define _TERRAIN_H


#include"obstacle.h"
#include"gravite.h"


//tableau de type cellule pointeur 

class Terrain 
{
    private:
      
     
      int DimX=20; 
      int DimY=20;
      
      //enum TypeCellule { Balle='B', Obstacle='O', Cellule='#',SPACE=' ' };

      //Cellule  tab[20][20] ;
      //Obstacle obs;
       Gravite gr;
       //Obstacle obs;
      //template < class T> class vector;

      //vector <Obstacle> O;

      //TypeCellule m_ter[20][20];

      
      Cellule ** tab[20][20];
      
     
      

    public:

    
     Terrain(); // constructeur par defaut 
     
     ~Terrain(); // destructeur par défaut 
    
    
     void SetCellule(int x, int y,const Cellule& c);

     Cellule GetCellule(int x, int y)const;
     
     void GenererTerrain(int Xmin,int Ymin,int Xmax,int Ymax);

     void SetObstacle();

     bool positionValide(Cellule evaluee);//bool

     int getDimx()const;

     int getDimy() const;

     //bool CollectionItem(Item I,Balle B);

     //bool PositionBallevalide(Balle B);

     //bool CollisionObstacle(Obstacle O,Balle B);

      
     bool Collision();

     void ArrangementTrajectoire(); 

     
     const Gravite& getGravite()const;

};



inline int Terrain :: getDimx()const{return DimX;}

inline int Terrain :: getDimy()const{return DimY;}

inline const Gravite& Terrain :: getGravite()const{return gr;}


#endif
