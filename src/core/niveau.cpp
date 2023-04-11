#include"niveau.h"
#include<fstream>
#include<iostream>


const char m_terrain1[15][21] = {
 "####################",
 "#.###....##........#",
 "#.#####..##...####.#",
 "#........##........#",
 "#........###.......#",
 "#...#..#....#......#",
 "#......#...##......#",
 "#####..#....#..#####",
 "#......##...#......#",
 "#......#....#......#",
 "#..................#",
 "#..................#",
 "#.....#......#.....#",
 "#.....#......#.....#",
 "####################"
};

const char m_terrain2[15][21] = {
 "####################",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "####################"
};


Niveau::Niveau () { Terrain();
}



void Niveau::ouvrir(const std :: string & filename)
 {

    std :: ifstream fichier (filename.c_str());

    assert(fichier.is_open());

	unsigned int xmin,ymin,xmax,ymax;
	//std :: string mot;
	//dimX = dimY = 0;
	//fichier >> mot >> dimX >> dimY >> mot;
	
	//if (tab != NULL) delete [] tab;
	//tab = new Pixel [dimX*dimY];
	
    while(!fichier.eof())
	{
		fichier >> xmin >> ymin >> xmax >> ymax ;

    	assert(xmin > 0 && xmin<xmax && xmax < ter.getDimx());

		assert(ymin > 0 && ymin<ymax && ymax < ter.getDimy());

		ter.SetObstacle(xmin,ymin,xmax,ymax);

		std :: cout << "obstacle posé à   "<<(xmax-xmin)<<" x "<<(ymax-ymin)<< std :: endl;
	}

    fichier.close();

    std :: cout << "Lecture de niveau  " << filename << " ... OK\n";
}