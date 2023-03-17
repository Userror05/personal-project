#include"src/gravite.h"
#include"math.h"
#include<cassert>
#include"SDL2/SDL.h"

void Gravite :: graviteConstante (Balle& B)
{

    B.gravite.y=B.gravite.y*g;
     //velocity += g * dt;

}

void Gravite::actualiseVecteur(Balle& b)
{
    Vecteur actualise (0.1,0.1);
    b.mouvement+= actualise;
}


float Gravite :: angleChoisis()
{
    float angle = 45;
    SDL_Event events;
    bool choixfini = false;
    int max=90;

    while (SDL_PollEvent(&events)) 
    {
			if (events.type == SDL_QUIT) choixfini = true;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_KEYDOWN) 
            {              // Si une touche est enfoncee
                
				switch (events.key.keysym.scancode) 
                {
				case SDL_SCANCODE_UP:
					
                     while (angle<=90){angle=angle+1.0;};   // car Y inverse
					
                    break;
                
                case SDL_SCANCODE_DOWN:
                     
                     while(angle>=0){angle=angle-1.0;};
               
                case SDL_SCANCODE_Q:
                    
                    choixfini = true;
                    
                    break;
				
                default: 
                    break;
				}
            } 
     }

    return angle;
} 


//
void Gravite :: accelerationBalle()
{

    //pas sur a propos de ce qui est écris ci-dessous, ce que je veux traduire une accélération en vecteur avec un angle choisis, et le veceteur qui appartient a la balle 
    Balle b;
    //b.mouvement.GetX()*cos(angleChoisis(touche));
    //b.mouvement.GetY()*sin(angleChoisis(touche));
}


// a optimiser poour pouvoir utiliser SDL

double Gravite :: RecupA()
{
    double a;

    a=cos(angleChoisis());
    
     return a;

}

double Gravite :: RecupB()
{
    double b;

    b=sin(angleChoisis());

    return b;
}

// pour otenir langle et le vecteur adéquate en fonction de l'angle que l'on a choisi
double Gravite :: ConversionX()
{
    return(GetPuis()*RecupA());

}

double Gravite :: ConversionY()
{
    return(GetPuis()*RecupB());
}


int Gravite :: GetPuis()
{
    SDL_Event events;
    bool choixfini = false;
    double pui;
    int max=90;

    while (SDL_PollEvent(&events)) 
    {
			if (events.type == SDL_QUIT) choixfini = true;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_KEYDOWN) 
            {              // Si une touche est enfoncee
                
				switch (events.key.keysym.scancode) 
                {
				case SDL_SCANCODE_KP_SPACE:
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

     return pui;
}