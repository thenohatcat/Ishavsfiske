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

	void findPath(int start, int goal);

	void findPath1(int start, int goal);


	int firstNode;

	// Arguments are goal position
	void startInit(int x, int y);

	// Arguments are goal position
	void calcAllH(int x, int y);
protected:
private:
	int mStart;
	int mGoal;

	int mCurrent;

	// Arguments are start position and goal position
	int detHScore(int xx, int yy, int x, int y);
	
	//void calcFVal();
	int lowFScoreOpen();
	void addToOpen(int node);
	void addToClosed(int node);




	openList mOpenList;

	void recStructPath(int cameFrom, int goal);
	void rmCurrentOpen();
	void addCurrentClosed();
};


#else
#error PathFinder.h: Wrong version 0.1.4
#endif

#endif