#include"jeu.h"
#include<iostream>
/*#include"SDL2/SDL.h"*/

/*void Jeu :: jeu()
{ 
    bool quit = false;
    while(quit)
    {
        SDL_Event events;
        while (SDL_PollEvent(&events)) 
        {
			if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_KEYDOWN) 
            {              // Si une touche est enfoncee
                
				switch (events.key.keysym.scancode) 
                {
				case SDL_SCANCODE_F:
					while(max>=pui){pui+=0,5;};    // car Y inverse
					break;
                case SDL_SCANCODE_Q:
                    choixfini = true;
                    break;
				default: 
                    break;
				}
            } 
        }

}
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
    gr.Power=20;
    gr.AffPR();
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