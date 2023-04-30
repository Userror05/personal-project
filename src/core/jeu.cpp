#include"jeu.h"
#include<cassert>
#include<iostream>

bool Jeu :: Rejouer(Vecteur v)
{
    if(v.Magnitude()>=0.1)
    {
        return true;
    }
    else return false;
}

void Jeu :: RepartirPosition(Balle& b)
{
    float x=b.GetX();
    float y = b.GetY();


    tabPosX.push_back(x);
    tabPosY.push_back(y);
}       

void Jeu :: ClearRepartition()
{
    tabPosX.clear();
    tabPosY.clear();
}

void Jeu :: BackMouvBalle(Balle& b)
{
    ter.GetGravite().GetPow();
    ter.GetGravite().AffPR();
    ter.GetGravite().GetAngle();
    ter.GetGravite().AffAng();
    ter.GetGravite().Vitesse(b);
    b.AffVitesse();
    b.InitMouvement();
    b.AffInitMouvement();
        for(int i=0;i<=50;i++)
        { 
            b.MoinsHuitMille();
            for (int i = 0; i <=50; i++)
            {
                ter.GetGravite().ActualiseAdri(b);
                if (ter.CollisionVect(b.adrien)==true)
                {
                    ter.ArrangementTrajectoire(b);
                    //ter.GetGravite().actualiseVecteurV2(b);
                    //repartirPosition(b);
                    break;
                }
                else
                {
                    ter.GetGravite().ActualiseBalleViaDiv(b);
                    RepartirPosition(b);
                 }
            }
            
            ter.GetGravite().ActualiseMouv(b);   
        }
}

void Jeu :: AngleChoisis (const char touche)
{
    int ang = ter.GetGravite().GetAngle();
    
    int max=360;

    
				switch (touche) 
                {
				case  'z':
					
                      if(ang<=max){ang++; std :: cout<<"angle = "<< ang;}   // car Y inverse
					
                    break;
                
                case 's':
                     
                     if(ang>=0){ang--;std :: cout<<"angle = "<< ang;}
                    
                    break;
				
                default: 
                    break;
				}
                std :: cout<< "  angle choisie  "<< ang << std::endl;
            
     ter.GetGravite().SetAng(ang);

} 
void Jeu :: ChangerRafraichissement (const char touche)
{
    int Rafraichissement = GetRaf();
    int max=9;
				switch (touche) 
                {
				case  'o':
					
                      if(Rafraichissement<=max){Rafraichissement++; std :: cout<<"Vitesse du jeu = "<< Rafraichissement;}
					
                    break;
                
                case 'l':
                     
                     if(Rafraichissement>=2){Rafraichissement--;std :: cout<<"Vitesse du jeu = "<< Rafraichissement;}
                    
                    break;
				
                default: 
                    break;
				}
                std :: cout<< "  Vitesse du jeu "<< Rafraichissement << std::endl;
            
     SetRaf(Rafraichissement);

} 

void Jeu :: GetPuis (const char touche)
{
   
    float pui = ter.GetGravite().GetPow();
    int max=5;
				switch (touche) 
                {
				case 't':

					if(max>pui){pui=pui+0.5;}else std :: cout<<"max de puissace atteint"<< std ::endl;
                      // car Y inverse
					break;

                case 'g':

                    if(pui>=0){pui=pui-0.5;} else std ::  cout << "min de puissance atteint " << std :: endl;

                    break;
				}

                assert(pui>=0 && pui <=10);
            std :: cout<< "  puissance choisie  "<< pui << std::endl;
    ter.GetGravite().SetPow(pui);
}

bool Jeu :: Jouer(const char jouer)
{
    if(jouer=='j') return true; else return false;
}


void Jeu :: TestRegression()
{
    Jeu gami;
    int ang = gami.GetTerrain().GetGravite().GetAngle();
    assert(ang<=90 && ang>=0);
    gami.AngleChoisis('z');

    assert(gami.GetTerrain().GetGravite().GetAngle() && gami.GetTerrain().GetGravite().GetAngle()!=ang);

    gami.GetPuis('t');
}





//********************************BackUp************************************************************************
/*
void Jeu :: ActionJoueurVisuelTest45()
{
    ter.getGravite().Power=5;
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


float Jeu :: GetTabX()const 
{
    return tabPosX;
}

float Jeu :: GetTabY()const
{
    return tabPosY;
}

//  if(ter.Collision(b)==true)
               // {
                   // ter.ArrangementTrajectoire(b);
                //    break;
               // }
               // else

void Jeu :: ActionJoueurVisuelTest45(Balle& b)
{
    
    ter.GetGravite().SetPow(5);
    ter.GetGravite().AffPR();
    ter.GetGravite().SetAng(45);
    ter.GetGravite().AffAng();
    ter.GetGravite().Vitesse(b);
    b.AffVitesse();
    b.InitMouvement();
    b.AffInitMouvement();
    //for(int t=0;t<=5;t++)
    // while(Rejouer(b.mouvement))
    //{
        for(int i=0;i<=5;i++)
        {
        // if(ter.Collision())
       // {
       //     ter.ArrangementTrajectoire();
        //}
        ter.GetGravite().ActualiseVecteur(b);
        
    }
}
void Jeu :: ActionJoueur(Balle& b)
{
    
    ter.GetGravite().Vitesse(b);
    b.InitMouvement();
  
    while(!Rejouer(b.mouvement))
    {
       //  if(ter.Collision())
       // {
       //     ter.ArrangementTrajectoire();
        //}
        ter.GetGravite().ActualiseVecteur(b);
        
    }
   
}
*/