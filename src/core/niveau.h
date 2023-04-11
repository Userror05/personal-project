#ifndef _NIVEAU
#define _NIVEAU


#include"terrain.h"
#include<cassert>
#include<string>


class Niveau
{ 
private :

    Terrain ter;

public :

    /**
    @brief <B>Construit</B> un objet Terrain.
    Le constructeur remplit dimx et dimy et les cases du tableau ter avec un terrain par défaut.
    @bug S'il y a un bug dans le constructeur, je peux le signaler ici ...
    */
    Niveau();

    void ouvrir(const std::string & filename,Terrain& ter);

    void TestRegression(); //marche pas encore

};




#endif
