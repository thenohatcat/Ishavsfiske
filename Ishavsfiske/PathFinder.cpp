//Version: 0.1.4
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_4
#error PathFinder.cpp: Wrong version 0.1.4
#endif

#include "PathFinder.h"
#include "Map.h"

static const int moveCostWASD = 10;

PathFinder::PathFinder()
	: mOpenList()
{
}

PathFinder::~PathFinder()
{
}


void PathFinder::findPath(int start, int goal)
{
	mCurrent = start;
	/*g_score[start];
	f_score[start] = g_score[start]; */

	while(!mOpenList.empty())
	{
		mCurrent = lowFScoreOpen();
		if(mCurrent == goal)
		{
			/*return reconstructPath(cameFrom, goal)*/
		}
		rmCurrentOpen();
		addCurrentClosed();
		
	}
}

//void PathFinder::startInit(int x, int y)
//{
//	calcAllH(x, y);
//}


// Calculate the lowest F value in openlist
int PathFinder::lowFScoreOpen()
{
	int lowestF;
	openList open(mOpenList);
	for(openList::size_type i = 0; i < mOpenList.size(); i++)
	{
		PathNode *pathNode0 = open[i];
		for(openList::size_type j = i + 1; j < mOpenList.size(); j++)
		{
			PathNode *pathNode1 = open[j];
			if(pathNode0->getF() < pathNode1->getF())
				lowestF = pathNode0->getF();
			else
				lowestF = pathNode1->getF();
		}
	}
	return lowestF;
}

//void PathFinder::calcFVal()
//{
//	f_score = h_score + g_score;
//}

// Calculates all H values in every node
void PathFinder::calcAllH(int x, int y)
{
	for(int yy = 0; yy < 40; yy++)
		for(int xx = 0; xx < 48; xx++)
			h_score[xx + yy * 48] = detHScore(xx, yy, x, y);
}

// Determine the H value
int PathFinder::detHScore(int xx, int yy, int x, int y)
{
	int h_score = 0;
	for(yy; yy < y; yy++)
		h_score++;
	for(xx; xx < x; xx++)
		h_score++;
	return h_score;
}

void PathFinder::recStructPath(int cameFrom, int goal)
{
	// if current node = came from
}

// Remove current node from openlist
void PathFinder::rmCurrentOpen()
{
	// Calculate directiontile and pop it from openlist...
}

// Add current node to closed list
void PathFinder::addCurrentClosed()
{
	// Same as rmCurrentOpen
}

