#include"jeu.h"
#include<cassert>
#include<iostream>

bool Jeu :: Rejouer(Vecteur v)
{
    if(v.magnitude()>=0.1)
    {
        return true;
    }
    else return false;
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
        ter.GetGravite().actualiseVecteur(b);
        
    }
   
}

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
        ter.GetGravite().actualiseVecteur(b);
        
    }
}

void Jeu :: repartirPosition(Balle& b)
{
    float x=b.GetX();
    float y = b.GetY();


    tabPosX.push_back(x);
    tabPosY.push_back(y);
}       

void Jeu :: clearRepartition()
{
    tabPosX.clear();
    tabPosY.clear();
}

void Jeu :: BackMouvBalle(Balle& b)
{
    ter.GetGravite().Getpow();
    ter.GetGravite().AffPR();
    ter.GetGravite().Getangle();
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
                ter.GetGravite().actualiseAdri(b);
                if (ter.CollisionVect(b.adrien)==true)
                {
                    ter.ArrangementTrajectoire(b);
                    //ter.GetGravite().actualiseVecteurV2(b);
                    //repartirPosition(b);
                    break;
                }
                else
                {
                    ter.GetGravite().actualiseVecteurV2(b);
                    repartirPosition(b);
                 }
            }
            
            ter.GetGravite().actualiseMouv(b);   
        }
}

//  if(ter.Collision(b)==true)
               // {
                   // ter.ArrangementTrajectoire(b);
                //    break;
               // }
               // else






void Jeu :: angleChoisis (const char touche)
{
    int ang = ter.GetGravite().Getangle();
    
    int max=90;

    
				switch (touche) 
                {
				case  'z':
					
                      if(ang<=max){ang++; std :: cout<<"angle = "<< ang;};   // car Y inverse
					
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



void Jeu :: GetPuis (const char touche)
{
   
    int pui = ter.GetGravite().Getpow();
    int max=10;
				switch (touche) 
                {
				case 't':

					if(max>pui){pui++;}else std :: cout<<"max de puissace atteint"<< std ::endl;
                      // car Y inverse
					break;

                case 'g':

                    if(pui>=0){pui--;} else std ::  cout << "min de puissance atteint " << std :: endl;

                    break;
				}

                assert(pui>=0 && pui <=10);
            std :: cout<< "  puissance choisie  "<< pui << std::endl;
    ter.GetGravite().SetPow(pui);
}

bool Jeu :: jouer(const char jouer)
{
    if(jouer=='j') return true; else return false;
}


void Jeu :: testRegression()
{
    Jeu gami;
    int ang = gami.GetTerrain().GetGravite().Getangle();
    assert(ang<=90 && ang>=0);
    gami.angleChoisis('z');

    assert(gami.GetTerrain().GetGravite().Getangle() && gami.GetTerrain().GetGravite().Getangle()!=ang);

    gami.GetPuis('t');
}





//********************************BackUp************************************************
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

*/