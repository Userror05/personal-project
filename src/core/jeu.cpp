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
    SetFinal(0);
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
           if(GetFinal()==0)
           { std :: cout << "yo"<< std::endl;
            b.MoinsHuitMille();
            for (int j= 0; j <=50; j++)
            {
                ter.GetGravite().ActualiseAdri(b,1);
                /***************************cas d'étude sur le coin haut gauche*****************************/
                if (ter.CollisionObsType0(b.adrien)==true)
                {
                    std::cout<<"GG mon reuf ta gagné";
                    if (GetFinal()==0)
                    {
                        SetFinal(1);
                    }
                    break;
                }
                if (ter.CollisionObsType2(b.adrien)==true)
                    {
                        std::cout<<"OH! t mort cousin";
                        if (GetFinal()==0)
                    {
                        SetFinal(2);
                    }
                    break;
                    }
                if (ter.CollisionObsType1(b.adrien)==true)
                {
                    ter.ArrangementTrajectoire(b);
                    break;
                }
                else
                {
                    /***************************cas d'étude sur le coin haut droit*****************************/
                    ter.GetGravite().ActualiseAdri(b,2);
                    if (ter.CollisionObsType0(b.adrien)==true)
                    {
                        std::cout<<"GG mon reuf ta gagné";
                        if (GetFinal()==0)
                        {
                            SetFinal(1);
                        }
                        break;
                    }
                    if (ter.CollisionObsType2(b.adrien)==true)
                    {
                        std::cout<<"OH! t mort cousin";
                        if (GetFinal()==0)
                        {
                            SetFinal(2);
                        }
                        break;
                    }
                    
                    if (ter.CollisionObsType1(b.adrien)==true)
                    {
                        ter.ArrangementTrajectoire(b);
                        break;
                    }
                    else
                    {
                        /***************************cas d'étude sur le coin bas gauche*****************************/
                        ter.GetGravite().ActualiseAdri(b,3);
                        if (ter.CollisionObsType0(b.adrien)==true)
                        {
                            std::cout<<"GG mon reuf ta gagné";
                            if (GetFinal()==0)
                            {
                                SetFinal(1);
                            }
                            break;
                        }
                        if (ter.CollisionObsType2(b.adrien)==true)
                        {
                            std::cout<<"OH! t mort cousin";
                            if (GetFinal()==0)
                            {
                                SetFinal(2);
                            }
                            break;
                        }
                        if (ter.CollisionObsType1(b.adrien)==true)
                        {
                            ter.ArrangementTrajectoire(b);
                            break;
                        }
                        else
                        {
                            /***************************cas d'étude sur le coin bas droit*****************************/
                            ter.GetGravite().ActualiseAdri(b,4);
                            if (ter.CollisionObsType0(b.adrien)==true)
                            {
                                std::cout<<"GG mon reuf ta gagné";
                                if (GetFinal()==0)
                                {
                                 SetFinal(1);
                                }
                                break;
                            }
                            if (ter.CollisionObsType2(b.adrien)==true)
                            {
                                std::cout<<"OH! t mort cousin";
                                if (GetFinal()==0)
                                {
                                 SetFinal(2);
                                }
                                break;
                            }
                            if (ter.CollisionObsType1(b.adrien)==true)
                            {
                                ter.ArrangementTrajectoire(b);
                                break;
                            }
                            else
                            {
                                ter.GetGravite().ActualiseBalleViaDiv(b);
                                b.ActualisePosition();
                                RepartirPosition(b);
                            }
                        }
                    }
                }
            }
            
            ter.GetGravite().ActualiseMouv(b);   
           }
           else
           {
            break;
           }
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

					if(pui<5){pui=pui+0.5;}else {std :: cout<<"max de puissace atteint"<< std ::endl;}
                      // car Y inverse
					break;

                case 'g':

                    if(pui>=0.5){pui=pui-0.5;} else{ std ::  cout << "min de puissance atteint " << std :: endl;}

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