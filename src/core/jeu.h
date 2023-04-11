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

    void ActionJoueur();
    //void ActionJoueurVisuelTest45();

     Terrain& GetTerrain();

     void angleChoisis(const char touche);
     void GetPuis(const char touche);

};

inline  Terrain& Jeu :: GetTerrain(){return ter;}


#endif