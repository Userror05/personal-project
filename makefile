all: bin/test 

bin/test: obj/mainTEST1.o obj/vecteur.o obj/cellule.o obj/balle.o obj/jeu.o obj/gravite.o obj/terrain.o obj/obstacle.o
	g++ obj/mainTEST1.o obj/vecteur.o obj/cellule.o obj/balle.o obj/jeu.o obj/gravite.o obj/terrain.o obj/obstacle.o -o bin/test 
	
obj/mainTEST1.o: src/mainTEST1.cpp src/core/jeu.h src/core/vecteur.h src/core/gravite.h src/core/terrain.h
	g++ -ggdb -c src/mainTEST1.cpp -o obj/mainTEST1.o

obj/vecteur.o: src/core/vecteur.cpp src/core/vecteur.h
	g++ -ggdb -Wall -c src/core/vecteur.cpp -o obj/vecteur.o

obj/cellule.o: src/core/cellule.cpp src/core/cellule.h
	g++ -ggdb -Wall -c src/core/cellule.cpp -o obj/cellule.o

obj/obstacle.o: src/core/obstacle.cpp src/core/obstacle.h src/core/cellule.h
	g++ -ggdb -Wall -c src/core/obstacle.cpp -o obj/obstacle.o

obj/balle.o: src/core/balle.cpp src/core/balle.h src/core/vecteur.h 
	g++ -ggdb -Wall -c src/core/balle.cpp -o obj/balle.o

obj/gravite.o: src/core/gravite.cpp src/core/gravite.h src/core/vecteur.h src/core/balle.h
	g++ -ggdb -Wall -c src/core/gravite.cpp -o obj/gravite.o

obj/terrain.o: src/core/gravite.h src/core/balle.h src/core/vecteur.h src/core/obstacle.h
	g++ -ggdb -Wall -c src/core/terrain.cpp -o obj/terrain.o

obj/jeu.o: src/core/jeu.cpp src/core/jeu.h src/core/gravite.h src/core/balle.h src/core/vecteur.h
	g++ -ggdb -Wall -c src/core/jeu.cpp -o obj/jeu.o


clean:           
	-rm obj/*.o  bin/test
