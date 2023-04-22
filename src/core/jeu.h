#ifndef _JEU
#define _JEU
#include"terrain.h"
#include<vector>

class Jeu
{

    private:
    Terrain ter;
    Balle jp;
    std ::  vector<float> tabPosX;
    std :: vector<float> tabPosY;
    

    public:

    /*void jeu();

    void Affichage_txt();*/

    bool Rejouer(Vecteur v);

    void ActionJoueur(Balle& b);
    void ActionJoueurVisuelTest45(Balle& b);

    Terrain& GetTerrain() ;

    const Terrain& getConstTerrain() const; 

    void angleChoisis(const char touche);

    void GetPuis(const char touche);

    bool jouer(const char jouer);
    
    void testRegression();

    const Balle& getConstBalle()const ;
    Balle& GetBalle() ;

    void repartirPosition(Balle& b);
    void clearRepartition();


};

inline  Terrain& Jeu :: GetTerrain() {return ter;}
inline  const Terrain& Jeu :: getConstTerrain() const {return ter;}

inline Balle& Jeu :: GetBalle() { return jp;}

inline const Balle& Jeu :: getConstBalle() const { return jp;}



#endif
