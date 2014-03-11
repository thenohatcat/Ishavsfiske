//Version: 0.1.4
//Author: Sihao Li
//Contributors:

#ifndef INC_PATHFINDER_H
#define INC_PATHFINDER_H

#ifdef ISHAV_0_1_4

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
	typedef vector<PathNode*> cameFrom;

	//void findPath(int start, int goal);

	void findPath1(PathNode *start, PathNode *goal);


	//// Arguments are goal position
	//void startInit(int x, int y);

	// Arguments are goal position
	void calcAllH(int x, int y);
protected:
private:
	PathNode *map[10 * 10];

	int mStart;
	int mGoal;

	PathNode *mStartNode;
	PathNode *mGoalNode;

	PathNode *mCurrent;

	// Arguments are start position and goal position
	unsigned int detHVal(int x, int y);
	
	////void calcFVal();

	// Determine the node with the lowest f value in openlist
	PathNode *lowFValueOpen();




	openList mOpenList;
	closedList mClosedList;

	void genSuccessors(PathNode *currentNode);

	bool inClosed(PathNode *node);

	//void recStructPath(int cameFrom, int goal);
	//void rmCurrentOpen();
	//void addCurrentClosed();
};


#else
#error PathFinder.h: Wrong version 0.1.4
#endif

#endif