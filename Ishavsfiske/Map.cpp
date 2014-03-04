//Version: 0.1.4
//Author: Sihao Li
//Contributors: Jakob Pipping

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
	Angler::Nodes::Scale *s = new Angler::Nodes::Scale(0, this, 1/20.0f, 1/20.0f);
	mMapPosition = new Angler::Nodes::Translation(0, s, 0, 0);
	Angler::Nodes::Translation *t = new Angler::Nodes::Translation(0, mMapPosition, 3, -1); 
	for(int y = 0; y < 22; y++)
	{
		Angler::Nodes::Translation *row = new Angler::Nodes::Translation(0, t, 0, y);
		for(int x = 0; x < 26; x++)
		{
			Angler::Nodes::Translation *col = new Angler::Nodes::Translation(0, row, x, 0);
			mMapNodes[x + y * 26] = new MapNode(0x80010000 + x + y * 26, col, mParent, 0);
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
				if (y == 0 || x == 0 || x == 23 || y == 19 || x == 47 || y == 39)
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
	int x = (index % 26) - 1;
	int y = (index / 26) - 1;
	if (x >= 0 && x <= 47 && y >= 0 && y <= 39)
	{			
		return mMap[(x + mPos.x) + (y + mPos.y) * 48];
	}
	return 0;
}

void Map::setTile(int index, int tile)
{
	int x = (index % 26) - 1;
	int y = (index / 26) - 1;

	if (x >= 0 && x <= 47 && y >= 0 && y <= 39)
	{
		mMap[(x + mPos.x) + (y + mPos.y) * 48] = tile;
		mUpdateMap();
	}
	mChanged = false;
}

void Map::move(sf::Vector2f diff)
{
	//setPos(sf::Vector2f(mPos.x + diff.x, mPos.y + diff.y));
	
	float posX = mMapPosition->getTranslationX();
	float posY = mMapPosition->getTranslationY();

	posX -= diff.x;
	posY -= diff.y;

	if (diff.x > 0 && posX < -1) //Moving to the right
	{
		setPos(sf::Vector2i(mPos.x + 1, mPos.y));
		posX = 0;
	}
	else if (diff.x < 0 && posX > 1)
	{
		setPos(sf::Vector2i(mPos.x - 1, mPos.y));
		posX = 0;
	}

	if (diff.y > 0 && posY < -1) //Moving down
	{
		setPos(sf::Vector2i(mPos.x, mPos.y + 1));
		posY = 0;
	}
	else if (diff.y < 0 && posY > 1)
	{
		setPos(sf::Vector2i(mPos.x, mPos.y - 1));
		posY = 0;
	}

	mSetTranslation(posX, posY);
}

void Map::mSetTranslation(float x, float y)
{
	if ((mPos.x == 0 && x > 0) || (mPos.x == 24 && x < 0))
		x = 0;

	if ((mPos.y == 0 && y > 0) || (mPos.y == 20 && y < 0))
		y = 0;

	mMapPosition->setTranslation(x, y);
	mChanged = true;
}

void Map::setPos(sf::Vector2i position)
{
	if (position.x >= 0 && position.x <= 24 && position.y >= 0 && position.y <= 20)
	{
		mPos = position;
		mChanged = true;
		mUpdateMap();
	}
}

sf::Vector2i Map::getPos()
{
	return mPos;
}

void Map::revert()
{
	setPos(mOldPos);
	mSetTranslation(mOldTransPos.x, mOldTransPos.y);
}

void Map::update(Angler::Game* context, float time, float deltaTime, bool changed)
{
	if (!mPaused)
	{
		mOldPos = mLPos;
		mOldTransPos = mLTransPos;
		mLPos = mPos;
		mLTransPos = mMapPosition->getTranslation();

		mChanged |= changed;

		mUpdateChildren(context, time, deltaTime);
	}
}

void Map::mUpdateMap()
{
	for(int y = -1; y < 21; y++)
	{
		for(int x = -1; x < 25; x++)
		{
			if (((x + mPos.x) >= 0 && (x + mPos.x) <= 47 && (y + mPos.y) >= 0 && (y + mPos.y) <= 39) &&
				(x >= -1 && x <= 25 && y >= -1 && y <= 21))
			{
				if(mMap[(x + mPos.x) + (y + mPos.y) * 48] == 0x10 && isWater((x + mPos.x), (y + mPos.y)))
				{
						switch(isIceDir((x + (int)mPos.x), (y + (int)mPos.y)))
						{
						case 8:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(0x12);
							break;
						case 1:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(0x13);
							break;
						case 6:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(0x14);
							break;
						case 3:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(0x15);
							break;
						case 2:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(0x16);
							break;
						case 9:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(0x17);
							break;
						case 4:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(0x18);
							break;
						case 7:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(0x19);
							break;
						default:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(0x11);
							break;
						}
				}
				else
					mMapNodes[(x + 1) + (y + 1) * 26]->setTile(mMap[(x + mPos.x) + (y + mPos.y) * 48]);
			}
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
	//We have to check if we are using a legitime coordinate
	if (outsideMap(x, y-1))
		return 0;
	return mMap[x + (y-1) * 48] == 0;
}

bool Map::isWaterRight(int x, int y)
{
	if (!outsideMap(x+1, y))
		return 0;
	return mMap[(x+1) + y * 48] == 0;
}

bool Map::isWaterLeft(int x, int y)
{
	if (outsideMap(x-1, y))
		return 0;
	return mMap[(x-1) + y * 48] == 0;
}

bool Map::isWaterBot(int x, int y)
{
	if (outsideMap(x, y+1))
		return 0;
	return mMap[x + (y+1) * 48] == 0;
}

bool Map::isWaterTopLeft(int x, int y)
{
	if (outsideMap(x-1, y-1))
		return 0;
	return mMap[(x-1) + (y-1) * 48] == 0;
}

bool Map::isWaterTopRight(int x, int y)
{
	if (outsideMap(x+1, y-1))
		return 0;
	return mMap[(x+1) + (y-1) * 48] == 0;
}

bool Map::isWaterBotLeft(int x, int y)
{
	if (outsideMap(x-1, y+1))
		return 0;
	return mMap[(x-1) + (y+1) * 48] == 0;
}

bool Map::isWaterBotRight(int x, int y)
{
	if (outsideMap(x+1, y+1))
		return 0;
	return mMap[(x+1) + (y+1) * 48] == 0;
}

// ICE CHECKS

bool Map::isIceLeft(int x, int y)
{
	if (outsideMap(x-1, y))
		return 1;
	return mMap[(x-1) + y * 48] == 0x10;
}

bool Map::isIceRight(int x, int y)
{
	if (outsideMap(x+1, y))
		return 1;
	return mMap[(x+1) + y * 48] == 0x10;
}

bool Map::isIceTop(int x, int y)
{
	if (outsideMap(x, y-1))
		return 1;
	return mMap[x + (y-1) * 48] == 0x10;
}

bool Map::isIceBot(int x, int y)
{
	if (outsideMap(x, y+1))
		return 1;
	return mMap[x + (y+1) * 48] == 0x10;
}

bool Map::isIceBotLeft(int x, int y)
{
	if (outsideMap(x-1, y+1))
		return 1;
	return mMap[(x-1) + (y+1) * 48] == 0x10;
}

bool Map::isIceBotRight(int x, int y)
{
	if (outsideMap(x+1, y+1))
		return 1;
	return mMap[(x+1) + (y+1) * 48] == 0x10;
}

bool Map::isIceTopLeft(int x, int y)
{
	if (outsideMap(x-1, y-1))
		return 1;
	return mMap[(x-1) + (y-1) * 48] == 0x10;
}

bool Map::isIceTopRight(int x, int y)
{
	if (outsideMap(x+1, y-1))
		return 1;
	return mMap[(x+1) + (y-1) * 48] == 0x10;
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