//Version: 0.1.5
//Author: Sihao Li
//Contributors:

#ifndef INC_PATHFINDER_H
#define INC_PATHFINDER_H

#ifdef ISHAV_0_1_5

#include "PathNode.h"

#include <vector>

using namespace std;

class PathFinder
{
public:
	PathFinder();
	~PathFinder();

	typedef vector<PathNode*> openList;
	typedef vector<PathNode*> closedList;
	typedef vector<PathNode*> pathList;

	//void findPath1(PathNode *start, PathNode *goal/*, PathNode *map[]*/);
	void findPath1(sf::Vector2i start, sf::Vector2i goal/*, PathNode *map[]*/);

	// Calculates all PathNodes H value
	void calcAllH();

	// Puts the PathNodes to goal in the pathList
	void recStructPath();

	void clear();
protected:
private:
	PathNode *mMap[10 * 10];

	PathNode *mStartNode;
	PathNode *mGoalNode;

	PathNode *mCurrent;

	// Calculates the H value
	unsigned int detHVal(int x, int y);

	// Determine the node with the lowest f value in openlist
	PathNode *lowFValueOpen();


	openList mOpenList;
	closedList mClosedList;
	pathList mPathList;

	void genSuccessors(PathNode *currentNode);

	bool inOpenClosed(sf::Vector2i pos);
	bool inOpen(sf::Vector2i pos);
	bool inClosed(sf::Vector2i pos);
	void internalClear();
	void clearOpen(), clearClosed(), clearPath();

	void genPathMap();
};


#else
#error PathFinder.h: Wrong version 0.1.5
#endif

#endif