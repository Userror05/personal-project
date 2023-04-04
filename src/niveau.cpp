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
	const Obstacle c;
    while(!fichier.eof())
	{
		fichier >> xmin >> ymin>> xmax >> ymax ;

    	assert(xmin > 0 && xmin<xmax && xmax < ter.getDimx()-1);

		assert(ymin > 0 && ymin<ymax && ymax < ter.getDimy()-1);

		ter.SetObstacle(xmin,ymin,xmax,ymax,c);
	}

    fichier.close();

    std :: cout << "Lecture de niveau  " << filename << " ... OK\n";
}