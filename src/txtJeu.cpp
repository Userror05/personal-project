#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"
#include "core/jeu.h"

void txtAff(WinTXT & win, const Jeu & jeu) {
	//const Terrain& ter = jeu.getTerrain();
	const Balle& b = jeu.GetTerrain().getGravite().GetBalle();

	win.clear();

    /*/ Affichage des murs et des pastilles
	for(int x=0;x<ter.getDimX();++x)
		for(int y=0;y<ter.getDimY();++y)
			win.print( x, y, ter.getXYasChar(x,y));*/

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

		jeu.Affichage_txt();

		c = win.getCh();
		switch (c) {
			case 'z':
				jeu.ActionJoueur(jeu.getTerrain().GetBalle(),'z');
				break;
			case 's':
				jeu.ActionJoueur(jeu.getTerrain().GetBalle(),'s');
				break;
				break;
			case 'q':
				ok = false;
				break;
		}

	} while (ok);

}
