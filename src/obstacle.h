#ifndef _OBSTACLE_H
#define _OBSTACLE_H
#include"cellule.h"

class Obstacle
{

    private:

    Cellule Obstacle;
    

    public:
    

    void SetObstacle(unsigned int x,unsigned int y);
    void GetObstacle(unsigned int x,unsigned int y);


};

inline void Obstacle :: SetObstacle(unsigned int x, unsigned int y)
{  /*SetCellule(x,y,Obstacle);*/}

inline void Obstacle :: GetObstacle(unsigned int x, unsigned int y)
{  /*GetCellule(x,y);*/}

#endif
