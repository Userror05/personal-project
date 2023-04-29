#ifndef _JEU
#define _JEU
#include"terrain.h"
#include<vector>

class Jeu
{

    private:
    Terrain ter;
    Balle jp;
    int Raf;
    

    

    public:

    std::vector<float> tabPosX;
    std::vector<float> tabPosY;
    /*void jeu();

    void Affichage_txt();*/

    bool Rejouer(Vecteur v);
    Terrain& GetTerrain() ;
    const Terrain& GetConstTerrain() const; 
    void AngleChoisis(const char touche);
    void ChangerRafraichissement(const char touche);
    void BackMouvBalle(Balle& b);
    void GetPuis(const char touche);
    bool Jouer(const char jouer);
    void TestRegression();
    void RepartirPosition(Balle& b);
    void ClearRepartition();
    int GetRaf()const;
    void SetRaf(int raf);
    const Balle& GetConstBalle()const ;
    Balle& GetBalle() ;

};

inline  Terrain& Jeu :: GetTerrain() {return ter;}
inline  const Terrain& Jeu :: GetConstTerrain() const {return ter;}
inline Balle& Jeu :: GetBalle() { return jp;}
inline int Jeu :: GetRaf() const {return Raf;}
inline void Jeu :: SetRaf(int raf)
{   Raf = raf;}
inline const Balle& Jeu :: GetConstBalle() const { return jp;}



#endif
//********************************BackUp************************************************************************
/*

    void ActionJoueur(Balle& b);
    void ActionJoueurVisuelTest45(Balle& b);
    float GetTabX() const;
    float GetTabY() const;
*/