//Version: 0.1.4
//Author: Sihao Li
//Contributors:

#ifndef INC_PATHNODE_H
#define INC_PATHNODE_H

#ifdef ISHAV_0_1_4

#include <Angler\Graphics.h>

class PathNode
{
public:
	PathNode();
	PathNode(PathNode *parent, PathNode *child);

	void setH(int h), setG(int g), setF(int f);
	void setParent(PathNode *parent);
	int getH(), getG(), getF();
	void addH(int h), addG(int g), addF(int f);

	int getPathDir();
	PathNode *getParent();
protected:
private:
	int mH, mG, mF;
	int mDir;
	sf::Vector2i mPos;
	PathNode *mParent;
	PathNode *mChild;


	void calcF();
};

#else
#error PathNode.h: Wrong version 0.1.4
#endif

#endif