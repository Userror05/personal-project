#include"jeu.h"
#include<iostream>

}*/


  //tant que F pas presser, on fait ActionJoueur()
    

    


/*Void Jeu :: Affichage_txt()
{
    int t=0;
    while (t=0)
    {
        Action
    }
    
}*/


//Tant que F pas presser, on fait ActionJoueurVisuel()

bool Jeu :: Rejouer(Vecteur v)
{
    if(v.magnitude()>=0.1)
    {
        return true;
    }
    else return false;
}

/*void Jeu :: ActionJoueurVisuel()
{
    Gravite gr;
    gr.angleChoisis();
    gr.AffAng();
    gr.GetPuis();
    gr.AffPR();
    gr.Vitesse();
    gr.InitMouvement(B);
    while(!Rejouer(B.mouvement,*this))
    {
        gr.actualiseVecteur(*this);
        AffPosition();
    }
   
}*/

void Jeu :: ActionJoueurVisuelTest45()
{
    int t;
    ter.getGravite().Power=20;
    ter.getGravite().AffPR();
    gr.Angle=45;
    gr.AffAng();
    gr.Vitesse(B);
    B.AffVitesse();
    B.InitMouvement();
    B.AffInitMouvement();
    for(t=0;t<=5;t++)
   // while(Rejouer(B.mouvement))
    {
        gr.actualiseVecteur(B);
        
    }
}