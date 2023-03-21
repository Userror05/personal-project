all: bin/txt 

bin/txt: obj/mainTEST1.o obj/vecteur.o obj/cellule.o obj/balle.o obj/jeu.o obj/gravite.o
	g++ obj/mainTEST1.o obj/vecteur.o obj/cellule.o obj/balle.o obj/jeu.o obj/gravite.o -o bin/txt 
	
obj/mainTEST1.o: src/mainTEST1.cpp src/jeu.h src/vecteur.h src/gravite.h src/terrain.h
	g++ -ggdb -c src/mainTEST1.cpp -o obj/mainTEST1.o

obj/vecteur.o: src/vecteur.cpp src/vecteur.h
	g++ -g -Wall -c src/vecteur.cpp -o obj/vecteur.o

obj/cellule.o: src/cellule.cpp src/cellule.h
	g++ -g -Wall -c src/cellule.cpp -o obj/cellule.o

obj/balle.o: src/balle.cpp src/balle.h src/vecteur.h 
	g++ -g -Wall -c src/balle.cpp -o obj/balle.o

obj/gravite.o: src/gravite.cpp src/gravite.h src/vecteur.h src/balle.h
	g++ -g -Wall -c src/gravite.cpp -o obj/gravite.o

obj/jeu.o: src/jeu.cpp src/jeu.h src/gravite.h src/balle.h src/vecteur.h
	g++ -g -Wall -c src/jeu.cpp -o obj/jeu.o



clean:           
	-rm obj/*.o  bin/txt
