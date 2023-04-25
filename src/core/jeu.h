#ifndef _JEU
#define _JEU
#include"terrain.h"
#include<vector>

class Jeu
{

    private:
    Terrain ter;
    

    

    public:

    std::vector<float> tabPosX;
    std::vector<float> tabPosY;
    /*void jeu();

    void Affichage_txt();*/

    bool Rejouer(Vecteur v);

    void ActionJoueur(Balle& b);
    void ActionJoueurVisuelTest45(Balle& b);

    Terrain& GetTerrain() ;

    const Terrain& getConstTerrain() const; 

    void angleChoisis(const char touche);
    void BackMouvBalle(Balle& b);
    void GetPuis(const char touche);

    bool jouer(const char jouer);
    
    void testRegression();

    void repartirPosition(Balle& b);
    void clearRepartition();
    float GetTabX() const;
    float GetTabY() const;

};

inline  Terrain& Jeu :: GetTerrain() {return ter;}
inline  const Terrain& Jeu :: getConstTerrain() const {return ter;}



#endif
