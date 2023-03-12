#ifndef _BALLE_H
#define _BALLE_H
#include"vecteur.h"
#include"gravite.h"
#include"cellule.h"

class Balle 
{
    private:

    Cellule balle;


    public:
    
    Vecteur mouvement;
    Vecteur gravite;

    Balle();

    int GetX();
    int GetY();
    void ArrangementTrajectoire();
    
    



    

    /*  fonction qui fait bouger la balle en fonction de touche appuyée 
    fonctions qui utilisent gravite pour avancer et changer le vecteur de positions*/

    




};



#endif
