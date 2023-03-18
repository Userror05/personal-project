#include"jeu.h"
#include"SDL2/SDL.h"

void Jeu :: jeu()
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
}


  //tant que F pas presser, on fait ActionJoueur()
    

    


Void Jeu :: Affichage_txt()
{
    //Tant que F pas presser, on fait ActionJoueurVisuel()
}


