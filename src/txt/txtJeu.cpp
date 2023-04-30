#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"
#include "../core/jeu.h"

void TxtAff(WinTXT & win,Jeu & jeu) {
	const Terrain& ter = jeu.GetTerrain();
	const Balle& b = jeu.GetBalle();

	win.clear();

    // Affichage des murs
	for(int x=0;x<ter.GetDimx();++x)
		{for(int y=0;y<ter.GetDimy();++y)
			{if(ter.getXY(x,y)!=nullptr )
				{if (ter.getXY(x,y)->F)win.print( x, y,'1');
			       if(ter.getXY(x,y)->R) win.print(x,y,'z');}}}
    // Affichage de la balle
	win.print(b.GetX(),b.GetY(),'O');
	

	win.draw();
}

void TxtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.GetTerrain().GetDimx(),jeu.GetTerrain().GetDimy());
	//jeu.Get;

	bool ok = true;
	int c;

	do {
	    TxtAff(win,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		//usleep(100000);
        #endif // WIN32
		//on a enlever ActionJoueur, ca change quelque chose?
		//jeu.ActionJoueur(jeu.GetBalle());

		c = win.getCh();
		
		
			switch (c) {
			case 'z':
				jeu.AngleChoisis('z');
				break;
			case 's':
				jeu.AngleChoisis('s');
				break;
				
				case 't':
				jeu.GetPuis('t');
				break;
			case 'g':
				jeu.GetPuis('g');
				break;
			case 'q':
				ok = false;
				break;

		
		}
		

	} while (ok);

}
