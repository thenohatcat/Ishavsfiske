//Version: 0.1.5
//Author: Sihao Li
//Contributors:

#ifndef INC_PATHNODE_H
#define INC_PATHNODE_H

#ifdef ISHAV_0_1_5

#include <Angler\Graphics.h>

class PathNode
{
public:
	PathNode();
	PathNode(unsigned int id, PathNode *parent, /*PathNode *child,*/ sf::Vector2i pos);

	void setH(int h), setG(int g), setF(int f);
	void setParent(PathNode *parent);
	int getH(), getG(), getF();
	void addH(int h), addG(int g), addF(int f);

	int getPathDir();
	PathNode *getParent();
	unsigned long getID();
	sf::Vector2i getPos();
protected:
private:
	int mH, mG, mF;
	int mDir;
	sf::Vector2i mPos;
	PathNode *mParent;
	/*PathNode *mChild;*/
	unsigned long mID;


	void calcF();
};

#else
#error PathNode.h: Wrong version 0.1.5
#endif

#endif