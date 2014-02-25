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
			mMapNodes[x + y * 24] = new MapNode(0x80010000 + x + y * 24, col, mParent, 0);
		}
	}
	mUpdateMap();
}

void Map::genMap(int lvl)
{
	switch(lvl)
	{
	case 1:
		for(int y = 0; y < 40; y++)
		{
			for(int x = 0; x < 48; x++)
			{
				if (y == 0 || x == 0 ||x == 23 || y == 19)
				{
					mMap[x + y * 48] = 0x10;
				}
				else if (x >= 2 && x <= 8 && y >= 2 && y <= 6)
				{
					mMap[x + y * 48] = 0x10;
				}
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
	{
		for(int x = 0; x < 24; x++)
		{
			if(mMap[(x + mPos.x) + (y + mPos.y) * 48] == 0x10 && isWater((x + mPos.x), (y + mPos.y)))
			{
					switch(isIceDir((x + mPos.x), (y + mPos.y)))
					{
					case 8:
						mMapNodes[x + y * 24]->setTile(0x12);
						break;
					case 1:
						mMapNodes[x + y * 24]->setTile(0x13);
						break;
					case 6:
						mMapNodes[x + y * 24]->setTile(0x14);
						break;
					case 3:
						mMapNodes[x + y * 24]->setTile(0x15);
						break;
					case 2:
						mMapNodes[x + y * 24]->setTile(0x16);
						break;
					case 9:
						mMapNodes[x + y * 24]->setTile(0x17);
						break;
					case 4:
						mMapNodes[x + y * 24]->setTile(0x18);
						break;
					case 7:
						mMapNodes[x + y * 24]->setTile(0x19);
						break;
					default:
						mMapNodes[x + y * 24]->setTile(0x11);
						break;
					}
			}
			else
				mMapNodes[x + y * 24]->setTile(mMap[(x + mPos.x) + (y + mPos.y) * 48]);
		}
	}
}

// WATER CHECK
bool Map::isWater(int x, int y)
{
	return isWaterTop(x, y) || isWaterBot(x, y) || isWaterLeft(x, y) || isWaterRight(x, y) || isWaterTopRight(x, y) || isWaterTopLeft(x, y) || isWaterBotLeft(x, y) || isWaterBotRight(x, y);
}

bool Map::isWaterTop(int x, int y)
{
	return mMap[x + (y-1) * 48] == 0 && !outsideMap(x, y-1);
}

bool Map::isWaterRight(int x, int y)
{
	return mMap[(x+1) + y * 48] == 0 && !outsideMap(x+1, y);
}

bool Map::isWaterLeft(int x, int y)
{
	return mMap[(x-1) + y * 48] == 0 && !outsideMap(x-1, y);
}

bool Map::isWaterBot(int x, int y)
{
	return mMap[x + (y+1) * 48] == 0 && !outsideMap(x, y+1);
}

bool Map::isWaterTopLeft(int x, int y)
{
	return mMap[(x-1) + (y-1) * 48] == 0 && !outsideMap(x-1, y-1);
}

bool Map::isWaterTopRight(int x, int y)
{
	return mMap[(x+1) + (y-1) * 48] == 0 && !outsideMap(x+1, y-1);
}

bool Map::isWaterBotLeft(int x, int y)
{
	return mMap[(x-1) + (y+1) * 48] == 0 && !outsideMap(x-1, y+1);
}

bool Map::isWaterBotRight(int x, int y)
{
	return mMap[(x+1) + (y+1) * 48] == 0 && !outsideMap(x+1, y+1);
}

// ICE CHECKS

bool Map::isIceLeft(int x, int y)
{
	return mMap[(x-1) + y * 48] == 0x10 || outsideMap(x-1, y);
}

bool Map::isIceRight(int x, int y)
{
	return mMap[(x+1) + y * 48] == 0x10 || outsideMap(x+1, y);
}

bool Map::isIceTop(int x, int y)
{
	return mMap[x + (y-1) * 48] == 0x10 || outsideMap(x, y-1);
}

bool Map::isIceBot(int x, int y)
{
	return mMap[x + (y+1) * 48] == 0x10 || outsideMap(x, y+1);
}

bool Map::isIceBotLeft(int x, int y)
{
	return mMap[(x-1) + (y+1) * 48] == 0x10 || outsideMap(x-1, y+1);
}

bool Map::isIceBotRight(int x, int y)
{
	return mMap[(x+1) + (y+1) * 48] == 0x10 || outsideMap(x+1, y+1);
}

bool Map::isIceTopLeft(int x, int y)
{
	return mMap[(x-1) + (y-1) * 48] == 0x10 || outsideMap(x-1, y-1);
}

bool Map::isIceTopRight(int x, int y)
{
	return mMap[(x+1) + (y-1) * 48] == 0x10 || outsideMap(x+1, y-1);
}


int Map::isIceDir(int x, int y)
{
	if(!(isWaterTop(x, y) || isIceBot(x, y) || (isIceRight(x, y) && isWaterLeft(x, y)) || (isIceLeft(x, y) && isWaterRight(x, y))))
	{
		return 8;
	}
	else if(!(isWaterRight(x, y) || isIceLeft(x, y) || (isWaterBot(x, y) && isIceTop(x, y)) || (isWaterTop(x, y) && isIceBot(x, y))))
	{
		return 6;
	}
	else if(!(isWaterBot(x, y) || isIceTop(x, y) || (isIceLeft(x, y) && isWaterRight(x, y)) || (isIceRight(x, y) && isWaterLeft(x, y))))
	{
		return 2;
	}
	else if(!(isWaterLeft(x, y) || isIceRight(x, y) || (isWaterBot(x, y) && isIceTop(x, y)) || (isWaterTop(x, y) && isIceBot(x, y))))
	{
		return 4;
	}
	else if(!(isWaterTopRight(x, y) || isIceBotLeft(x, y) || (isWaterTopLeft(x, y) && isIceBotRight(x, y)) || (isWaterBotRight(x, y) && isIceTopLeft(x, y)) || (isIceBot(x, y) && isIceLeft(x, y))))
	{
		return 9;
	}
	else if(!(isWaterBotRight(x, y) || isIceTopLeft(x, y) || (isWaterBotLeft(x, y) && isIceTopRight(x, y)) || (isWaterTopRight(x, y) && isIceBotLeft(x, y))))
	{
		return 3;
	}
	else if(!(isWaterBotLeft(x, y) || isIceTopRight(x, y) || (isWaterBotRight(x, y) && isIceTopLeft(x, y)) || (isWaterTopLeft(x, y) && isIceBotRight(x, y))))
	{
		return 1;
	}
	else if(!(isWaterTopLeft(x, y) || isIceBotRight(x, y) || (isWaterBotLeft(x, y) && isIceTopRight(x, y)) || (isWaterTopRight(x, y) && isIceBotLeft(x, y))))
	{
		return 7;
	}
	return 0;
}

bool Map::outsideMap(int x, int y)
{
	return x < 0 || x >= 48 || y < 0 || y >= 40;
}