#include"src/gravite.h"
#include"math.h"
#include<cassert>
#include"SDL2/SDL.h"


void Gravite::actualiseVecteur(Balle& b)
{
    float coef=0.9;
    while(!ter.Collision())
    {
           // b.mouvement= b.mouvement + b.mouvement*coef;
            b.mouvement= (b.mouvement + b.gravite)*coef;
            b.SetX(b.mouvement.GetX());
            b.SetY(b.mouvement.GetY());

    }

    
}

void Gravite :: InitMouvement(Balle& b)
{
    b.mouvement=b.vitesse+b.gravite;
}


void Gravite :: angleChoisis()
{
    float ang = 45;
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
					
                     while (ang<=90){ang=ang+1.0;};   // car Y inverse
					
                    break;
                
                case SDL_SCANCODE_DOWN:
                     
                     while(ang>=0){ang=ang-1.0;};
               
                case SDL_SCANCODE_Q:
                    
                    choixfini = true;
                    
                    break;
				
                default: 
                    break;
				}
            } 
     }
     Angle = ang;

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

    a=cos(Angle);
    
     return a;

}

double Gravite :: RecupB()
{
    double b;

    b=sin(Angle);

    return b;
}

// pour otenir langle et le vecteur adéquate en fonction de l'angle que l'on a choisi
double Gravite :: ConversionX()
{
    return(Power*RecupA());

}

double Gravite :: ConversionY()
{
    return(Power*RecupB());
}

Vecteur Gravite :: Vitesse()
{
    Vecteur v (ConversionX(),ConversionY());
    return(B.vitesse=v);
}


void Gravite :: GetPuis()
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
    Power=pui;
}

void Gravite :: AffPR ()
{
    cout << "La puissance est de " << Power;
}

void Gravite :: AffAng()
{
    cout << "l'angle est de " << Angle << "°";
}