//Version: 0.1.3
//Author: Sihao Li
//Contributors:

#ifndef INC_MAP_H
#define INC_MAP_H

#ifdef ISHAV_0_1_3

#include <Angler\Game.h>
#include <Angler\Node.h>

#include "MapNode.h"

class Map
	: public Angler::Node
{
public:
	Map(unsigned long id, Angler::Node *parent, Angler::Game *owner);
	Map(unsigned long id, Angler::Node *parent, Angler::Game *owner, int lvl);
	
	void genMap(int lvl);
	void setMap();

	void perlin2d(double **x, double **y, double **z, int xn, int yn, int sps);
protected:
	virtual void mInit();
private:
	int mMap[24][20], mapTemp[24][20];
	Angler::Game *mParent;
};

#else
#error Map.h: Wrong version 0.1.3
#endif

#endif