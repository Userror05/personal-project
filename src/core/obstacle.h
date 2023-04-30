#ifndef _OBSTACLE_H
#define _OBSTACLE_H
#include"cellule.h"
#include<cassert>

class Obstacle
{

    private:

    Cellule Obstacle;

    
    

    public:
    enum typeOBS{ R=2, F=1 };

    typeOBS obs;
    

    void SelectType(unsigned int choix);
    

    void SetObstacle(unsigned int x,unsigned int y);
    

   


};

inline void Obstacle :: SelectType(unsigned int choix){ assert(choix==1 || choix==0);if(choix==1)obs=R;else obs=F;   }


#endif
