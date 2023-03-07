#ifndef _TERRAIN_H
#define _TERRAIN_H

#include"cellule.h"
#include"obstacle.h"
#include"balle.h"

//tableau de type cellule pointeur 

class Terrain 
{
    private:
      
     
      int DimX; 
      int DimY;
       Cellule * tab[200][200] ;

      Obstacle obs;
      Balle ply;
      

    public:
    
     Terrain(); // constructeur par defaut 
     
     ~Terrain(); // destructeur par défaut 
    
     void SetCellule(int x, int y,const Cellule& c);

     Cellule& GetCellule()const;

     bool positionValide(Cellule evaluee);//bool
     
     void GenererTerrain(int Xmin,int Ymin,int Xmax,int Ymax);

     void SetObstacle()


     // bool CollectionItem(Item I,Balle B);

     //bool Positionvalide(Balle B);
      

      //bool Collision(Obstacle O,Balle B);










};











#endif
