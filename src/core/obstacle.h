#ifndef _OBSTACLE_H
#define _OBSTACLE_H
#include"cellule.h"

class Obstacle
{

    private:

    Cellule Obstacle;
    enum TypePiece 
    { RIEN=0,
	OVER=1, 
    };
    

    public:

    void SetObstacle(unsigned int x,unsigned int y);

    void gettype_Obs();
    

   


};


#endif
