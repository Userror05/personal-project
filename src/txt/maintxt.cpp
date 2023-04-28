#include "winTxt.h"
#include "txtJeu.h"

int main ( int argc, char** argv ) {
    termClear();
	Jeu jeu;
	TxtBoucle(jeu);
    termClear();
	return 0;
}
