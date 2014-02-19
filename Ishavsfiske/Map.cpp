//Version: 0.1.4
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_4
#error Map.cpp: Wrong version 0.1.4
#endif

#include "Map.h"
#include "MapNode.h"

#include <Angler\Graphics.h>
#include <Angler\Scale.h>
#include <Angler\Translation.h>
#include <Angler\HelpFunctions.h>

#include <iostream>
#include <cstdlib>

int randomValue(int number) {
	return rand() % number;
}
//
//int tempMap[48][40] = {
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
//	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
//}; 

Map::Map(unsigned long id, Angler::Node *parent, Angler::Game *owner)
	: Node(id, parent), mParent(owner), mPos(0, 0)
{
	genMap(1);
	mInit();
}

Map::Map(unsigned long id, Angler::Node *parent, Angler::Game *owner, int lvl)
	: Node(id, parent), mParent(owner), mPos(0, 0)
{
	genMap(lvl);
	mInit();
}

void Map::mInit()
{
	Angler::Nodes::Scale *s = new Angler::Nodes::Scale(0, this, 1/20.0, 1/20.0);
	Angler::Nodes::Translation *t = new Angler::Nodes::Translation(0, s, 4, 0);
	for(int y = 0; y < 20; y++)
	{
		Angler::Nodes::Translation *row = new Angler::Nodes::Translation(0, t, 0, y);
		for(int x = 0; x < 24; x++)
		{
			Angler::Nodes::Translation *col = new Angler::Nodes::Translation(0, row, x, 0);
			new MapNode(0x80010000 + x + y * 24, col, mParent, 0);
		}
	}
	mUpdateMap();
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
				{/*
					if(isBorderIce(x, y))
						mMap[x + y * 48] = 0x11;
					else*/
						mMap[x + y * 48] = 0x10;
				}
				if (x >= 2 && x <= 5 && y >= 2 && y <= 5)
					mMap[x + y * 48] = 0;
				else
					mMap[x + y * 48] = 0;
			}
		}
		break;
	case 2:
		for(int y = 0; y < 20; y++)
		{
			for(int x = 0; x < 24; x++)
			{
				if (x == y)
				{
					mMap[x + y * 48] = 0x10;
				}
				else
					mMap[x + y * 48] = 0;
			}
		}
		break;
	case 3:
		for(int y = 0; y < 20; y++)
			for(int x = 0; x < 24; x++)
			{
				switch(randomValue(2))
				{
				case 0:
					mMap[x + y * 48] = 0;
					break;
				case 1:
					mMap[x + y * 48] = 0x10;
					break;
				/*if(mMap[x + y * 48] == 1)
				{
					mMap[x - 1 + y * 48] = 1;
					mMap[x + y - 1 * 48] = 1;
					mMap[x + 1 + y * 48] = 1;
					mMap[x + y + 1 * 48] = 1;*/
				}
			}
		/*srand();*/
		break;
	}
}


int Map::getTile(int index)
{
	int x = index % 24;
	int y = index / 24;
	return mMap[(x + mPos.x) + (y + mPos.y) * 48];
}

void Map::setTile(int index, int tile)
{
	int x = index % 24;
	int y = index / 24;

	mMap[(x + mPos.x) + (y + mPos.y) * 48] = tile;
	mUpdateMap();
}

void Map::setPos(sf::Vector2i position)
{
	mPos = position;
	mUpdateMap();
}

sf::Vector2i Map::getPos()
{
	return mPos;
}

void Map::mUpdateMap()
{
	for(int y = 0; y < 20; y++)
		for(int x = 0; x < 24; x++)
		{
			MapNode *n = (MapNode *)Angler::HelpFunctions::Nodes::getNode(0x80010000 + x + y * 24, this);
			n->setTile(mMap[(x + mPos.x) + (y + mPos.y) * 48]);
		}
}

bool Map::isBorderIce(int x, int y)
{
	return mMap[x-1 + y-1 * 48] == 0 || mMap[x + y-1 * 48] == 0 || mMap[x+1 + y-1 * 48] == 0 || mMap[x-1 + y * 48] == 0
		|| mMap[x+1 + y * 48] == 0 || mMap[x-1 + y+1 * 48] == 0 || mMap[x + y+1 * 48] == 0 || mMap[x+1 + y+1 * 48] == 0;
}