#include"gravite.h"
#include"math.h"
/*#include<cassert>*/
/*#include"SDL2/SDL.h"*/
#include<iostream>
#include<unistd.h>


void Gravite::actualiseVecteur(Balle& b)
{
    float coef=0.9;
           // b.mouvement= (b.mouvement + b.mouvement)*coef;
            b.mouvement.SetX((b.mouvement.GetX()+b.gravite.GetX())*coef);
            b.mouvement.SetY((b.mouvement.GetY()+b.gravite.GetY())*coef);
            b.SetX(b.GetX()+b.mouvement.GetX());
            b.SetY(b.GetY()+b.mouvement.GetY());
            usleep(1000000);
            std::cout<<"mouv:"<<"("<<b.mouvement.GetX()<<","<<b.mouvement.GetY()<<")";
            
            b.AffPosition();

//avant while(!ter.collision)
    
}


/*
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
					
                     while (ang<=90){ang=ang+1.0; std :: cout<<"angle="<<ang;};   // car Y inverse
					
                    break;
                
                case SDL_SCANCODE_DOWN:
                     
                     while(ang>=0){ang=ang-1.0;std :: cout<<"angle="<<ang;};
               
                case SDL_SCANCODE_Q:
                    
                    choixfini = true;
                    
                    break;
				
                default: 
                    break;
				}
            } 
     }
     Angle = ang;
     std::cout<<"Angle final:"<<Angle;

} */


/*
void Gravite :: accelerationBalle()
{

    //pas sur a propos de ce qui est écris ci-dessous, ce que je veux traduire une accélération en vecteur avec un angle choisis, et le veceteur qui appartient a la balle 
    Balle b;
    //b.mouvement.GetX()*cos(angleChoisis(touche));
    //b.mouvement.GetY()*sin(angleChoisis(touche));
}
*/

// a optimiser poour pouvoir utiliser SDL

double Gravite :: RecupA()
{
    double a;
    a=cos(Angle);
    std::cout<<" "<<a<<" ";
     return a;

}

double Gravite :: RecupB()
{
    double b;
    b=sin(ConversionAng());
    std::cout<<" "<<b<<" ";
    return b;
}

double Gravite :: ConversionAng()
{

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

Vecteur& Gravite :: Vitesse(Balle& b)
{
    Vecteur v (ConversionX(),ConversionY());
    return(b.vitesse=v);
}

/*
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
					while(max>=pui){pui+=0,5;std::cout<<"Puissance="<<Power;};    // car Y inverse
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
    std::cout<<"Puissance Finale="<<Power;
}*/

void Gravite :: AffPR ()
{
    std :: cout << "La puissance est de " << Power;
}

void Gravite :: AffAng()
{
    std :: cout << "l'angle est de " << Angle << "°";
}