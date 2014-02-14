//Version: 0.1.3
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_3
#error Map.cpp: Wrong version 0.1.3
#endif

#include "Map.h"
#include "MapNode.h"

#include <Angler\Graphics.h>
#include <Angler\Scale.h>
#include <Angler\Translation.h>

#include <iostream>

int mapTemp[24][20] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
}; 

Map::Map(unsigned long id, Angler::Node *parent, Angler::Game *owner, sf::Texture *mapTexture)
	: Node(id, parent), mParent(owner), mTXMap(mapTexture)
{
	setMap();
	mInit();
}

Map::Map(unsigned long id, Angler::Node *parent, Angler::Game *owner, sf::Texture *mapTexture, int lvl)
	: Node(id, parent), mParent(owner), mTXMap(mapTexture)
{
	genMap(lvl);
	mInit();
}

void Map::mInit()
{
	// Draw map

	/*Angler::Nodes::Scale *s = new Angler::Nodes::Scale(0, this, 1/20.0, 1/20.0);
	Angler::Nodes::Translation *t = new Angler::Nodes::Translation(0, s, 4.5, 0.5);
	for(int y = 0; y < 20; y++)
	{
		Angler::Nodes::Translation *row = new Angler::Nodes::Translation(0, t, 0, y);
		for(int x = 0; x < 24; x++)
		{
			Angler::Nodes::Translation *col = new Angler::Nodes::Translation(0, row, x, 0);
			new MapNode(0, col, mTXMap, mParent, x == y);
		}
	}*/


	Angler::Nodes::Scale *s = new Angler::Nodes::Scale(0, this, 1/20.0, 1/20.0);
	Angler::Nodes::Translation *t = new Angler::Nodes::Translation(0, s, 4.5, 0.5);
	for(int y = 0; y < 20; y++)
	{
		Angler::Nodes::Translation *row = new Angler::Nodes::Translation(0, t, 0, y);
		for(int x = 0; x < 24; x++)
		{
			Angler::Nodes::Translation *col = new Angler::Nodes::Translation(0, row, x, 0);
			new MapNode(x + y * 24, col, mTXMap, mParent, mMap[x][y]);

			
			/*std::cout << mMap[x][y] << std::endl;*/
		}
	}
}

void Map::genMap(int lvl)
{
	switch(lvl)
	{
	case 1:
		for(int y = 0; y < 20; y++)
		{
			for(int x = 0; x < 24; x++)
			{
				if (y == 0 || x == 0 ||x == 23 || y == 19)
				{
					mapTemp[x][y] = 0;
				}
				else
					mapTemp[x][y] = 1;
			}
		}
		setMap();
		break;
	case 2:
		for(int y = 0; y < 20; y++)
		{
			for(int x = 0; x < 24; x++)
			{
				if (x == y)
				{
					mapTemp[x][y] = 0;
				}
				else
					mapTemp[x][y] = 1;
			}
		}
		setMap();
		break;
	}
}

void Map::setMap()
{
	memcpy(mMap, mapTemp, sizeof(mapTemp));
}

void Map::perlin2d(double **x, double **y, double **z, int xn, int yn, int sps)
{
	int m = yn * sps;
	int n = xn * sps;

	double **U = new double *[yn+1];
	double **V = new double *[yn+1];
	x = new double *[m];
	y = new double *[m];
	z = new double *[m];

	for(int i = 0; i < m; i++)
	{
		x[i] = new double[n];
		y[i] = new double[n];
		z[i] = new double[n];
	}

	for(int i = 0; i < m; i++)
	{
		U[i] = new double[xn+1];
		V[i] = new double[xn+1];
	}
	for(int i = 0; i < yn+1; i++)
	{
		for(int j = 0; j < yn+1; j++)
		{
			U[i][j] = randRange[-1, 1];
			V[i][j] = randRange[-1, 1];
		}
	}