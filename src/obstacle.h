#ifndef _OBSTACLE_H
#define _OBSTACLE_H
#include"terrain.h"

class Obstacle
{

    private:

    Cellule Obstacle;
    Terrain ter;

    public:
    

    void SetObstacle(unsigned int x,unsigned int y);
    void GetObstacle(unsigned int x,unsigned int y);


};

inline void Obstacle :: SetObstacle(unsigned int x, unsigned int y)
{  ter.SetCellule(x,y,Obstacle);}

inline void Obstacle :: GetObstacle(unsigned int x, unsigned int y)
{  ter.GetCellule(x,y);}

#endif
