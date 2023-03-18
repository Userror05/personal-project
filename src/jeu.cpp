#include"jeu.h"
#include"SDL2/SDL.h"

void Jeu :: jeu()
{ 
    bool quit = false;
    
    
        SDL_Event events;
        while (SDL_PollEvent(&events)) 
        {
			if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_KEYDOWN) 
            {              // Si une touche est enfoncee
				if(events.key.keysym.scancode==SDL_SCANCODE_F)
                
                {quit=true;}

                else  B.ActionJoueur();
				}
            } 
 }



  //tant que F pas presser, on fait ActionJoueur()
    

    


void Jeu :: Affichage_txt()
{
    //Tant que F pas presser, on fait ActionJoueurVisuel()

    
}


