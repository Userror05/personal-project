#ifndef _BALLE_H
#define _BALLE_H
#include"vecteur.h"

class Balle 
{
    private:

    double pos_x,pos_y;
   


    public:
    
    Vecteur Sauvegarde;
    Vecteur mouvement;
    Vecteur vitesse;
    Vecteur gravite;

    Balle();

    double GetX();
    double GetY();
    void SetX(double x);
    void SetY(double y);
   /* bool ArrangementTrajectoire();*/
    /*void ActionJoueur()*/
    void AffPosition();
    void InitMouvement();
    void AffVitesse();
    void AffInitMouvement();




};



#endif
