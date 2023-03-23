#include"jeusdl2.h"

void JeuSDL2 :: Bouclejeu()
   
    {
        
         bool quit = false;
        while(quit){
        SDL_Event events;
        while (SDL_PollEvent(&events)) 
        {
			if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_KEYDOWN) 
            {              // Si une touche est enfoncee
                
				switch (events.key.keysym.scancode) 
                {
				case SDL_SCANCODE_F:
					while(max>=jeu.GetTerrain().getGravite().Power){jeu.GetTerrain().getGravite().Power++;};    // car Y inverse
					break;
                case SDL_SCANCODE_Q:
                    quit = true;
                    break;
				default: 
                    break;
				}
            } 
        }
        }

}