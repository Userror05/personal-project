#ifndef _JEU
#define _JEU

#include"obstacle.h"
#include"item.h"
#include"vecteur.h"
#include"balle.h"
#include"gravite.h"
#include<vector>

class Jeu
{

    private:
    Balle B;
    Item item;
    Obstacle Obs;
    Terrain ter;
    Gravite gr;

    public:

    void jeu();

    void Affichage_txt();

};


#endif