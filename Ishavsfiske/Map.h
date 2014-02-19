//Version: 0.1.4
//Author: Sihao Li
//Contributors:

#ifndef INC_MAP_H
#define INC_MAP_H

#ifdef ISHAV_0_1_4

#include <Angler\Game.h>
#include <Angler\Node.h>

#include "MapNode.h"

class Map
	: public Angler::Node
{
public:
	Map(unsigned long id, Angler::Node *parent, Angler::Game *owner);
	Map(unsigned long id, Angler::Node *parent, Angler::Game *owner, int lvl);
	
	int getTile(int index);
	void setTile(int index, int tile);

	void setPos(sf::Vector2i pos);
	sf::Vector2i getPos();

	void genMap(int lvl);

protected:
	virtual void mInit();
private:
	int mMap [48 * 40];
	Angler::Game *mParent;
	sf::Vector2i mPos;
	void mUpdateMap();
};

#else
#error Map.h: Wrong version 0.1.4
#endif

#endif