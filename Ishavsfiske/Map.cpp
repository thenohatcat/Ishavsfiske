//Version: 0.1.5
//Author: Sihao Li
//Contributors: Jakob Pipping

#ifndef ISHAV_0_1_5
#error Map.cpp: Wrong version 0.1.5
#endif

#include "Map.h"
#include "MapNode.h"

#include <Angler\Graphics.h>
#include <Angler\Scale.h>
#include <Angler\Translation.h>
#include <Angler\HelpFunctions.h>

#include <iostream>
#include <cstdlib>

using namespace Ishavsfiske;

int mapDir[256] = 
{
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//0
	0x0, 0x0, 0x8, 0x8, 0x0, 0x0, 0x8, 0x8,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//8
	0x4, 0x4, 0x7, 0x7, 0x4, 0x4, 0x7, 0x7,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//16
	0x6, 0x6, 0x9, 0x9, 0x6, 0x6, 0x9, 0x9,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//24
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8,

	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//32
	0x0, 0x0, 0x8, 0x8, 0x0, 0x0, 0x8, 0x8,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//40
	0x4, 0x4, 0x7, 0x7, 0x4, 0x4, 0x7, 0x7,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//48
	0x6, 0x6, 0x9, 0x9, 0x6, 0x6, 0x9,0x9,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//56
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8,

	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//64
	0x2, 0x2, 0x0, 0x0, 0x2, 0x2, 0x0, 0x0,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//72
	0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x0, 0x0,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//80
	0x3, 0x3, 0x0, 0x0, 0x3, 0x3, 0x0, 0x0,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//88
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//96
	0x2, 0x2, 0x0, 0x0, 0x2, 0x2, 0x0, 0x0,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//104
	0x1, 0x1, 0x0, 0x4, 0x1, 0x1, 0x0, 0x4,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//112
	0x3, 0x3, 0x0, 0x0, 0x3, 0x3, 0x0, 0x0,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//120
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa,

	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//128
	0x0, 0x0, 0x8, 0x8, 0x0, 0x0, 0x8, 0x8,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//136
	0x4, 0x4, 0x7, 0x7, 0x4, 0x4, 0x7, 0x7,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//144
	0x6, 0x6, 0x9, 0x9, 0x6, 0x6, 0x9, 0x9,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//152
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8,

	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//160
	0x0, 0x0, 0x8, 0x8, 0x0, 0x0, 0x8, 0x8,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//168
	0x4, 0x4, 0x7, 0x7, 0x4, 0x4, 07, 0x7, 
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//176
	0x6, 0x6, 0x9, 0x9, 0x6, 0x6, 0x9, 0x9,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//184
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8,

	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//192
	0x2, 0x2, 0x0, 0x0, 0x2, 0x2, 0x0, 0x0,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//200
	0x1, 0x1, 0x0, 0x0, 0x1, 0x1, 0x0, 0x0,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//208
	0x3, 0x3, 0x0, 0x0, 0x3, 0x3, 0x6, 0x6,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//216
	0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb,

	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//224
	0x2, 0x2, 0x0, 0x0, 0x2, 0x2, 0x0, 0x0,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//232
	0x1, 0x1, 0x0, 0x4, 0x1, 0x1, 0x0, 0x4,
	/*-1, -1, -1, -1, -1, -1, -1, -1,*/					//240
	0x3, 0x3, 0x0, 0x0, 0x3, 0x3, 0x6, 0x6,
	/*-1, -1, -1, -1, -1, -1, -1, -1*/					//248
	0x2, 0x2, 0x0, 0xd, 0x2, 0x2, 0xc, 0x0
};

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
			for(int x = 0; x < 48; x++)
			{
				if (x == 0 || y == 0 || x == 47 || y == 39)
				{
					mMap[x + y * 48] = 0x20;
				}
				else if (!(x >= 14 && x <= 33 && y >= 12 && y <= 27))
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
			}
		/*srand();*/
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
		for(int y = 0; y < 40; y++)
		{
			for(int x = 0; x < 48; x++)
			{
				if ((x >= 11 && x <= 37 && y >= 9 && y <= 31) && !(x >= 13 && x <= 34 && y >= 11 && y <= 28))
				{
					mMap[x + y * 48] = 0x20;
				}
				else
					mMap[x + y * 48] = 0;
			}
		}
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


// Behövs denna funktion?
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
				if(mMap[(x + mPos.x) + (y + mPos.y) * 48] == 0x10 || mMap[(x + mPos.x) + (y + mPos.y) * 48] == 0x20)
				{
					if (mIsWater((x + mPos.x), (y + mPos.y)))
					{
						switch(mIsIceDir((x + (int)mPos.x), (y + (int)mPos.y)))
						{
						case 8:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(mMap[(x + mPos.x) + (y + mPos.y) * 48] + 0x02);
							break;
						case 1:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(mMap[(x + mPos.x) + (y + mPos.y) * 48] + 0x03);
							break;
						case 6:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(mMap[(x + mPos.x) + (y + mPos.y) * 48] + 0x04);
							break;
						case 3:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(mMap[(x + mPos.x) + (y + mPos.y) * 48] + 0x05);
							break;
						case 2:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(mMap[(x + mPos.x) + (y + mPos.y) * 48] + 0x06);
							break;
						case 9:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(mMap[(x + mPos.x) + (y + mPos.y) * 48] + 0x07);
							break;
						case 4:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(mMap[(x + mPos.x) + (y + mPos.y) * 48] + 0x08);
							break;
						case 7:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(mMap[(x + mPos.x) + (y + mPos.y) * 48] + 0x09);
							break;

						case 10:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(mMap[(x + mPos.x) + (y + mPos.y) * 48] + 0x0A);
							break;
						case 11:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(mMap[(x + mPos.x) + (y + mPos.y) * 48] + 0x0B);
							break;
						case 12:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(mMap[(x + mPos.x) + (y + mPos.y) * 48] + 0x0C);
							break;
						case 13:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(mMap[(x + mPos.x) + (y + mPos.y) * 48] + 0x0D);
							break;
						
						default:
							mMapNodes[(x + 1) + (y + 1) * 26]->setTile(mMap[(x + mPos.x) + (y + mPos.y) * 48] + 0x01);
							break;
						}
					}
					else
					{
						mMapNodes[(x + 1) + (y + 1) * 26]->setTile(mMap[(x + mPos.x) + (y + mPos.y) * 48] + 0x00);
					}
				}
				else
					mMapNodes[(x + 1) + (y + 1) * 26]->setTile(mMap[(x + mPos.x) + (y + mPos.y) * 48]);
			}
		}
	}
}

// WATER CHECK
bool Map::mIsWater(int x, int y)
{
	return mIsWaterTop(x, y) || mIsWaterBot(x, y) || mIsWaterLeft(x, y) || mIsWaterRight(x, y) || mIsWaterTopRight(x, y) || mIsWaterTopLeft(x, y) || mIsWaterBotLeft(x, y) || mIsWaterBotRight(x, y);
}

bool Map::mIsWaterTop(int x, int y)
{
	//We have to check if we are using a legitime coordinate
	if (mOutsideMap(x, y-1))
		return 0;
	return mMap[x + (y-1) * 48] == 0;
}

bool Map::mIsWaterRight(int x, int y)
{
	if (mOutsideMap(x+1, y))
		return 0;
	return mMap[(x+1) + y * 48] == 0;
}

bool Map::mIsWaterLeft(int x, int y)
{
	if (mOutsideMap(x-1, y))
		return 0;
	return mMap[(x - 1) + y * 48] == 0;
}

bool Map::mIsWaterBot(int x, int y)
{
	if (mOutsideMap(x, y+1))
		return 0;
	return mMap[x + (y+1) * 48] == 0;
}

bool Map::mIsWaterTopLeft(int x, int y)
{
	if (mOutsideMap(x-1, y-1))
		return 0;
	return mMap[(x-1) + (y-1) * 48] == 0;
}

bool Map::mIsWaterTopRight(int x, int y)
{
	if (mOutsideMap(x+1, y-1))
		return 0;
	return mMap[(x+1) + (y-1) * 48] == 0;
}

bool Map::mIsWaterBotLeft(int x, int y)
{
	if (mOutsideMap(x-1, y+1))
		return 0;
	return mMap[(x-1) + (y+1) * 48] == 0;
}

bool Map::mIsWaterBotRight(int x, int y)
{
	if (mOutsideMap(x+1, y+1))
		return 0;
	return mMap[(x+1) + (y+1) * 48] == 0;
}

// ICE CHECKS

bool Map::mIsIceLeft(int x, int y)
{
	if (mOutsideMap(x-1, y))
		return 1;
	return (mMap[(x-1) + y * 48] == 0x10 || mMap[(x-1) + y * 48] == 0x20);
}

bool Map::mIsIceRight(int x, int y)
{
	if (mOutsideMap(x+1, y))
		return 1;
	return (mMap[(x+1) + y * 48] == 0x10 || mMap[(x+1) + y * 48] == 0x20);
}

bool Map::mIsIceTop(int x, int y)
{
	if (mOutsideMap(x, y-1))
		return 1;
	return (mMap[x + (y-1) * 48] == 0x10 || mMap[x + (y-1) * 48] == 0x20);
}

bool Map::mIsIceBot(int x, int y)
{
	if (mOutsideMap(x, y+1))
		return 1;
	return (mMap[x + (y+1) * 48] == 0x10 || mMap[x + (y+1) * 48] == 0x20);
}

bool Map::mIsIceBotLeft(int x, int y)
{
	if (mOutsideMap(x-1, y+1))
		return 1;
	return (mMap[(x-1) + (y+1) * 48] == 0x10 || mMap[(x-1) + (y+1) * 48] == 0x20);
}

bool Map::mIsIceBotRight(int x, int y)
{
	if (mOutsideMap(x+1, y+1))
		return 1;
	return (mMap[(x+1) + (y+1) * 48] == 0x10 || mMap[(x+1) + (y+1) * 48] == 0x20);
}

bool Map::mIsIceTopLeft(int x, int y)
{
	if (mOutsideMap(x-1, y-1))
		return 1;
	return (mMap[(x-1) + (y-1) * 48] == 0x10 || mMap[(x-1) + (y-1) * 48] == 0x20);
}

bool Map::mIsIceTopRight(int x, int y)
{
	if (mOutsideMap(x+1, y-1))
		return 1;
	return (mMap[(x+1) + (y-1) * 48] == 0x10 || mMap[(x+1) + (y-1) * 48] == 0x20);
}

bool Map::mIsEdge(int x, int y)
{
	return (x == 0 || x == 47 || y == 0 || y == 39);
}

int Map::mIsIceDir(int x, int y)
{
	return mapDir[mIsIceTopLeft(x, y) * 0x01 + mIsIceTop(x, y) * 0x02 + mIsIceTopRight(x, y) * 0x04 + mIsIceLeft(x, y) * 0x08 + 
		mIsIceRight(x, y) * 0x10 + mIsIceBotLeft(x, y) * 0x20 + mIsIceBot(x, y) * 0x40 + mIsIceBotRight(x, y) * 0x80];

	//if( !(mIsWaterTop(x, y) || mIsIceBot(x, y) || (mIsIceRight(x, y) && mIsWaterLeft(x, y)) || (mIsIceLeft(x, y) && mIsWaterRight(x, y))
	//	/*|| ((mIsIceTopLeft(x, y) || mIsIceTopRight(x, y)) && (mIsWaterLeft(x, y) || mIsWaterRight(x, y)))*/
	//	) )
	//{
	//	return 8;
	//}
	//else if( !(mIsWaterRight(x, y) || mIsIceLeft(x, y) || (mIsIceTop(x, y) && mIsWaterBot(x, y)) || (mIsIceBot(x, y) && mIsWaterTop(x, y))
	//	/*|| ((mIsIceTopLeft(x, y) || mIsIceBotLeft(x, y)) && (mIsWaterTop(x, y) || mIsWaterBot(x, y)))*/
	//	) )
	//{
	//	return 6;
	//}
	//else if( !( mIsWaterBot(x, y) || mIsIceTop(x, y) || (mIsIceRight(x, y) && mIsWaterLeft(x, y)) || (mIsIceLeft(x, y) && mIsWaterRight(x, y))
	//	/*|| ((mIsIceBotLeft(x, y) || mIsIceBotRight(x, y)) && (mIsWaterLeft(x, y) || mIsWaterRight(x, y)))*/
	//	) )
	//{
	//	return 2;
	//}
	//else if( !( mIsWaterLeft(x, y) || mIsIceRight(x, y) || (mIsIceTop(x, y) && mIsWaterBot(x, y)) || (mIsIceBot(x, y) && mIsWaterTop(x, y))
	//	/*|| ((mIsIceTopRight(x, y) || mIsIceBotRight(x, y)) && (mIsWaterTop(x, y) || mIsWaterBot(x, y)))*/
	//	) )
	//{
	//	return 4;
	//}

	//else if( !( mIsWaterTopRight(x, y) || mIsIceBotLeft(x, y) || mIsWaterTop(x, y) || mIsWaterRight(x, y) || mIsIceBot(x, y) || mIsIceLeft(x, y) ) )
	//{
	//	return 9;
	//}
	//else if( !( mIsWaterBotRight(x, y) || mIsIceTopLeft(x, y) || mIsWaterBot(x, y) || mIsWaterRight(x, y) || mIsIceTop(x, y) || mIsIceLeft(x, y) ) )
	//{
	//	return 3;
	//}
	//else if( !( mIsWaterBotLeft(x, y) || mIsIceTopRight(x, y) || mIsWaterBot(x, y) || mIsWaterLeft(x, y) || mIsIceTop(x, y) || mIsIceRight(x, y) ) )
	//{
	//	return 1;
	//}
	//else if( !( mIsWaterTopLeft(x, y) || mIsIceBotRight(x, y) || mIsWaterTop(x, y) || mIsWaterLeft(x, y) || mIsIceBot(x, y) || mIsIceRight(x, y) ) )
	//{
	//	return 7;
	//}

	return 0;
}

bool Map::mOutsideMap(int x, int y)
{
	return x < 0 || x >= 48 || y < 0 || y >= 40;
}