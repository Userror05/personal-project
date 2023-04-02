#include"jeusdl2.h"

const int TAILLE_SPRITE = 32;

void JeuSDL2 :: BoucleChoixPUI()
   
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
					Jeu.GetPuis(SDL_SCANCODE_F);    // car Y inverse
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

void JeuSDL2 :: BoucleChoixANG()
   
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
				case SDL_SCANCODE_UP:
					Jeu.angleChoisis(SDL_SCANCODE_UP);    // car Y inverse
					break;
                case SDL_SCANCODE_DOWN:
					Jeu.angleChoisis(SDL_SCANCODE_DOWN);    // car Y inverse
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

void JeuSDL2 ::SDLinit()
{
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std :: cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() <<  std :: endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0) {
        std :: cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() <<  std :: endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        std :: cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std ::  endl;
        SDL_Quit();
        exit(1);
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        std :: cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std :: endl;
        std ::  cout << "No sound !!!" <<  std :: endl;
        //SDL_Quit();exit(1);
        withSound = false;
    }
    else withSound = true;

	int dimx, dimy;
	dimx = Jeu.GetTerrain().getDimx();
	dimy = Jeu.GetTerrain().getDimx();
	dimx = dimx * TAILLE_SPRITE;
	dimy = dimy * TAILLE_SPRITE;

    // Creation de la fenetre
    window = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        std ::  cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std ::  endl; 
        SDL_Quit(); 
        exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    /*im_pacman.loadFromFile("data/pacman.png",renderer);
    im_mur.loadFromFile("data/mur.png",renderer);
    im_pastille.loadFromFile("data/pastille.png",renderer);
    im_fantome.loadFromFile("data/fantome.png",renderer);*/
    // IMAGES
    

    // FONTS
    font = TTF_OpenFont("data/DejaVuSansCondensed.ttf",50);
    if (font == nullptr)
        font = TTF_OpenFont("../data/DejaVuSansCondensed.ttf",50);
    if (font == nullptr) {
           std ::   cout << "Failed to load DejaVuSansCondensed.ttf! SDL_TTF Error: " << TTF_GetError() << std ::  endl; 
            SDL_Quit(); 
            exit(1);
	}
	font_color.r = 50;font_color.g = 50;font_color.b = 255;
	font_im.setSurface(TTF_RenderText_Solid(font,"Pacman",font_color));
	font_im.loadFromCurrentSurface(renderer);

    // SONS
    if (withSound)
    {
        sound = Mix_LoadWAV("data/son.wav");
        if (sound == nullptr) 
            sound = Mix_LoadWAV("../data/son.wav");
        if (sound == nullptr) {
               std ::   cout << "Failed to load son.wav! SDL_mixer Error: " << Mix_GetError() << std ::  endl; 
                SDL_Quit();
                exit(1);
        }
    }
}
