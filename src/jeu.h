#ifndef _JEU
#define _JEU
#include"terrain.h"

class Jeu
{

    private:
    Terrain ter;
    

    public:

    /*void jeu();

    void Affichage_txt();*/

    bool Rejouer(Vecteur v);

    void ActionJoueurVisuel();
    void ActionJoueurVisuelTest45();

    const Terrain& GetTerrain()const;

};

inline const Terrain& Jeu :: GetTerrain()const {return ter;}


#endif