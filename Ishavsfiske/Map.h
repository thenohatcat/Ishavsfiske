//Version: 0.1.4
//Author: Sihao Li
//Contributors:

#ifndef INC_MAP_H
#define INC_MAP_H

#ifdef ISHAV_0_1_4

#include <Angler\Game.h>
#include <Angler\Node.h>
#include <Angler\Translation.h>

#include "MapNode.h"

class Map
	: public Angler::Node
{
public:
	Map(unsigned long id, Angler::Node *parent, Angler::Game *owner);
	Map(unsigned long id, Angler::Node *parent, Angler::Game *owner, int lvl);
	
	int getTile(int index);
	void setTile(int index, int tile);

	// Behövs dessa funktioner?
	void setPos(sf::Vector2i pos);
	sf::Vector2i getPos();

	void move(sf::Vector2f diff);

	void genMap(int lvl);

	int getMap();

	void revert();

	void update(Angler::Game* context, float time, float deltaTime, bool changed);

protected:
	virtual void mInit();
private:
	void mSetTranslation(float x, float y);

	int mMap [48 * 40];
	Angler::Game *mParent;
	sf::Vector2i mPos;
	sf::Vector2i mOldPos, mLPos;
	sf::Vector2f mOldTransPos, mLTransPos;
	void mUpdateMap();
	bool isWater(int x, int y), isWaterTop(int x, int y), isWaterRight(int x, int y), isWaterLeft(int x, int y), isWaterBot(int x, int y),
		isWaterTopLeft(int x, int y), isWaterTopRight(int x, int y), isWaterBotLeft(int x, int y), isWaterBotRight(int x, int y);
	int isIceDir(int x, int y);
	bool isIceLeft(int x, int y), isIceRight(int x, int y), isIceTop(int x, int y), isIceBot(int x, int y),
		isIceBotLeft(int x, int y), isIceBotRight(int x, int y), isIceTopLeft(int x, int y), isIceTopRight(int x, int y);
	bool outsideMap(int x, int y);

	Angler::Nodes::Translation *mMapPosition;

	MapNode *mMapNodes[26 * 22];
};

#else
#error Map.h: Wrong version 0.1.4
#endif

#endif