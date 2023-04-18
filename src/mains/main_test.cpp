#include"../core/jeu.h"

int main()
{ 
    Terrain ter;
    
    ter.TestRegression();
    std :: string mot = "./data/niveau1";
    ter.ouvrir(mot);
    Gravite gr;
    Balle b;
   
    b.TestRegression();
    
    gr.TestRegression();

    return 0;
}

/*
    Jeu jeu;
    jeu.testRegression();
    
   
   


return 0;
*/