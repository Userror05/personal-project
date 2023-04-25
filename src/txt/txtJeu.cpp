#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"
#include "../core/jeu.h"

void txtAff(WinTXT & win,Jeu & jeu) {
	const Terrain& ter = jeu.GetTerrain();
	const Balle& b = jeu.GetTerrain().GetBalle();

	win.clear();

    // Affichage des murs
	for(int x=0;x<ter.getDimx();++x)
		for(int y=0;y<ter.getDimy();++y)
			if(ter.getXY(x,y)!=nullptr)
				win.print( x, y,'1');

    // Affichage de la balle
	win.print(b.GetX(),b.GetY(),'O');
	

	win.draw();
}

void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.GetTerrain().getDimx(),jeu.GetTerrain().getDimy());
	//jeu.Get;

	bool ok = true;
	int c;

	do {
	    txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		jeu.ActionJoueur(jeu.GetTerrain().GetBalle());

		c = win.getCh();
		
		
			switch (c) {
			case 'z':
				jeu.angleChoisis('z');
				break;
			case 's':
				jeu.angleChoisis('s');
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
