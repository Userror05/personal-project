#include"jeusdl2.h"
#include<iostream>
#include<string>
using namespace std;

const int TAILLE_SPRITE = 32;

Image::Image () : m_surface(nullptr), m_texture(nullptr), m_hasChanged(false) {
}

Image::~Image()
{
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = nullptr;
    m_texture = nullptr;
    m_hasChanged = false;
}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr) {
     string nfn =  string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<< endl;
        m_surface = IMG_Load(nfn.c_str());
        if (m_surface == nullptr) {
            nfn = string("../") + nfn;
            m_surface = IMG_Load(nfn.c_str());
        }
    }
    if (m_surface == nullptr) {
        cout<<"Error: cannot load "<< filename << endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(m_surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(m_surface);
    m_surface = surfaceCorrectPixelFormat;

    m_texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (m_texture == NULL) {
         cout << "Error: problem to create the texture of "<< filename << endl;
        SDL_Quit();
        exit(1);
    }
    
}

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    m_texture = SDL_CreateTextureFromSurface(renderer,m_surface);
    if (m_texture == nullptr) {
         cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?m_surface->w:w;
    r.h = (h<0)?m_surface->h:h;

    if (m_hasChanged) {
        ok = SDL_UpdateTexture(m_texture,nullptr,m_surface->pixels,m_surface->pitch);
        assert(ok == 0);
        m_hasChanged = false;
    }

    ok = SDL_RenderCopy(renderer,m_texture,nullptr,&r);
    assert(ok == 0);
}

SDL_Texture * Image::getTexture() const {return m_texture;}

void Image::setSurface(SDL_Surface * surf) {m_surface = surf;}


JeuSDL2 ::JeuSDL2() : gami()
{
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() <<   endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
         cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
         cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() <<  endl;
        cout << "No sound !!!" <<   endl;
        //SDL_Quit();exit(1);
        withSound = false;
    }
    else withSound = true;
//////////////////
	int dimx, dimy;
	dimx = gami.GetTerrain().getDimx();
	dimy = gami.GetTerrain().getDimx();
	dimx = dimx * TAILLE_SPRITE;
	dimy = dimy * TAILLE_SPRITE;

    // Creation de la fenetre
    window = SDL_CreateWindow("Golfnic", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
         cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    im_balle.loadFromFile("data/balle.jpg",renderer);
    im_mur.loadFromFile("data/mur.jpg",renderer);
    // IMAGES
    

    /*// FONTS
    font = TTF_OpenFont("data/SIXTY.ttf",50);
    if (font == nullptr)
        font = TTF_OpenFont("../data/SIXTY.ttf",50);
    if (font == nullptr) {
            cout << "Failed to load SIXTY.ttf! SDL_TTF Error: " << TTF_GetError() << endl; 
            SDL_Quit(); 
            exit(1);
	}
	font_color.r = 50;font_color.g = 50;font_color.b = 255;
	font_im.setSurface(TTF_RenderText_Solid(font,"golfnic",font_color));
	font_im.loadFromCurrentSurface(renderer);

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
    }*/ // SONS
    
}


JeuSDL2::~JeuSDL2 () {
    //if (withSound) Mix_Quit();
    //TTF_CloseFont(font);
    //TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


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
					gami.GetPuis(SDL_SCANCODE_F);    // car Y inverse
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
					gami.angleChoisis(SDL_SCANCODE_UP);    // car Y inverse
					break;
                case SDL_SCANCODE_DOWN:
					gami.angleChoisis(SDL_SCANCODE_DOWN);    // car Y inverse
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



void JeuSDL2 :: sdlaff()
{ 

     Terrain& ter = gami.GetTerrain();
    SDL_RenderClear(renderer);

im_balle.draw(renderer,ter.GetBalle().GetX()*TAILLE_SPRITE,ter.GetBalle().GetY()*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
for(unsigned int i=0;i<ter.getDimx();i++)
{
    for(unsigned int j=0;j<ter.getDimy();j++)
    {
        if(ter.getXY(i,j)!=nullptr)
        im_mur.draw(renderer,i*TAILLE_SPRITE,j*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
    }
}
}
void JeuSDL2 :: Bouclejeu()
{     
    SDL_Event events;
      bool jouer = false;
    //BoucleChoixANG();
    //BoucleChoixPUI();

   /*while(!gami.Rejouer(gami.GetTerrain().GetBalle().mouvement))
    {
        gami.ActionJoueur();
        
        
    }*/ 
    //gami.Rejouer(gami.GetTerrain().GetBalle().mouvement)==0

     bool quit = false;
        while(!quit){
       
        while (SDL_PollEvent(&events)) 
        {
			if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
			if(jouer)
            {
                 if (events.type == SDL_KEYDOWN) 
            {              // Si une touche est enfoncee
                
				switch (events.key.keysym.scancode) 
                {
				case SDL_SCANCODE_UP:
					gami.angleChoisis(SDL_SCANCODE_UP);    // car Y inverse
					break;
                case SDL_SCANCODE_DOWN:
					gami.angleChoisis(SDL_SCANCODE_DOWN);    // car Y inverse
					break;
				case SDL_SCANCODE_F:
					gami.GetPuis(SDL_SCANCODE_F);    // car Y inverse
					break;
                case SDL_SCANCODE_Q:
                    quit = true;
                    break;
				default: 
                    break;
				}
            } jouer=true;
            
            } else gami.ActionJoueur();

            sdlaff();
		        // on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
            SDL_RenderPresent(renderer);

        }
        }

}



