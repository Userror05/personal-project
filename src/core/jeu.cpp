#include"jeu.h"
#include<iostream>

bool Jeu :: Rejouer(Vecteur v)
{
    if(v.magnitude()>=0.1)
    {
        return true;
    }
    else return false;
}

void Jeu :: ActionJoueur()
{
    
    ter.getGravite().Vitesse(ter.GetBalle());
    ter.GetBalle().InitMouvement();
  
    while(!Rejouer(ter.GetBalle().mouvement))
    {
         if(ter.Collision())
        {
            ter.ArrangementTrajectoire();
        }
        ter.getGravite().actualiseVecteur(ter.GetBalle());
        
    }
   
}

/*void Jeu :: ActionJoueurVisuelTest45()
{
    
    ter.getGravite().Power=20;
    ter.getGravite().AffPR();
    ter.getGravite().Angle=45;
    ter.getGravite().AffAng();
    ter.getGravite().Vitesse(ter.getGravite().GetBalle());
    ter.getGravite().GetBalle().AffVitesse();
    ter.getGravite().GetBalle().InitMouvement();
    ter.getGravite().GetBalle().AffInitMouvement();
    for(int t=0;t<=5;t++)
   // while(Rejouer(B.mouvement))
    {
         if(ter.Collision())
        {
            ter.ArrangementTrajectoire();
        }
        ter.getGravite().actualiseVecteur(ter.getGravite().GetBalle());
        
    }
}
*/





void Jeu :: angleChoisis (const char touche)
{
    float ang = 45;
    
    int max=90;

    
				switch (touche) 
                {
				case 'z':
					
                     while (ang<=90){ang=ang+1.0; std :: cout<<"angle = "<< ang;};   // car Y inverse
					
                    break;
                
                case 's':
                     
                     while(ang>=0){ang=ang-1.0;std :: cout<<"angle = "<< ang;}
                    
                    break;
				
                default: 
                    break;
				}
                std :: cout<< "  angle choisie  "<< ang << std::endl;
            
     ter.getGravite().SetAng(ang);

} 



void Jeu :: GetPuis (const char touche)
{
   
    double pui;
    int max=10;

    
				switch (touche) 
                {
				case 't':

					while(max>=pui){pui=pui+0.5;} 
                      // car Y inverse
					break;

                case 'g':

                    while(pui>=0){pui=pui-0.5;}

                    break;
				}
            std :: cout<< "  puissance choisie  "<< pui << std::endl;
    ter.getGravite().SetPow(pui);
}