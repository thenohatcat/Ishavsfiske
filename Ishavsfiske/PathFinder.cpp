//Version: 0.1.4
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_4
#error PathFinder.cpp: Wrong version 0.1.4
#endif

#include "PathFinder.h"

static const int moveCostWASD = 10;

PathFinder::PathFinder()
	: mOpenList(), mClosedList()
{
}

PathFinder::~PathFinder()
{
}


//void PathFinder::findPath(int start, int goal)
//{
//	/*mCurrent = start;*/
//
//	while(!mOpenList.empty())
//	{
//		mCurrent = lowFScoreOpen();
//		if(mCurrent == goal)
//		{
//			/*return reconstructPath(cameFrom, goal)*/
//		}
//		rmCurrentOpen();
//		addCurrentClosed();
//		
//	}
//}

void PathFinder::findPath1(PathNode *start, PathNode *goal)
{
	PathNode *startNode = start;
	PathNode *goalNode = goal;
	mOpenList.push_back(startNode);

	while(!mOpenList.empty() && mCurrent != goalNode)
	{
		mCurrent = lowFValueOpen();
		
		for (vector<PathNode*>::const_iterator i = mOpenList.begin(); i != mOpenList.end(); i++)
		{
			if ((*i) == mCurrent)
			{
				mOpenList.erase(i);
				break;
			}
		}
		
		genSuccessors(mCurrent);

		openList open(mOpenList);
		for(vector<PathNode*>::const_iterator i = mOpenList.begin(); i != mOpenList.end(); i++)
		{
			PathNode *node = *i;
			if(node->getParent() == mCurrent)
			{
				if(!inClosed(node))
				{
					node->setG(mCurrent->getG() + moveCostWASD);
					if(node->getF() < mCurrent->getF())
					{
						node->setParent(mCurrent);
						mCurrent = node;
					}
					else
					{
						mClosedList.push_back(node);
						mOpenList.erase(i);
					}
				}
			}
			else
			{
				if(node->getF() < mCurrent->getF())
				{
					node->setParent(mCurrent);
					mCurrent = node;
				}
			}
				
		}
		mClosedList.push_back(mCurrent);
	}
}


//void PathFinder::startInit(int x, int y)
//{
//	calcAllH(x, y);
//}


// Calculate the lowest F value in openlist
PathNode *PathFinder::lowFValueOpen()
{
	PathNode *lowestF = nullptr;
	openList open(mOpenList);
	for(openList::size_type i = 0; i < open.size(); i++)
	{
		PathNode *pathNode0 = open[i];
		for(openList::size_type j = i + 1; j < open.size(); j++)
		{
			PathNode *pathNode1 = open[j];
			if(pathNode0->getF() < pathNode1->getF())
				lowestF = pathNode0;
			else
				lowestF = pathNode1;
		}
	}
	return lowestF;
}

//void PathFinder::calcFVal()
//{
//	f_score = h_score + g_score;
//}

//// Calculates all H values in every node
//void PathFinder::calcAllH(int x, int y)
//{
//	for(int yy = 0; yy < 40; yy++)
//		for(int xx = 0; xx < 48; xx++)
//			h_score[xx + yy * 48] = detHScore(xx, yy, x, y);
//}

//// Determine the H value
//int PathFinder::detHScore(int xx, int yy, int x, int y)
//{
//	int h_score = 0;
//	for(yy; yy < y; yy++)
//		h_score++;
//	for(xx; xx < x; xx++)
//		h_score++;
//	return h_score;
//}

//void PathFinder::recStructPath(int cameFrom, int goal)
//{
//	// if current node = came from
//}

//// Remove current node from openlist
//void PathFinder::rmCurrentOpen()
//{
//	// Calculate directiontile and pop it from openlist...
//}

//// Add current node to closed list
//void PathFinder::addCurrentClosed()
//{
//	// Same as rmCurrentOpen
//}

void PathFinder::genSuccessors(PathNode *currentNode)
{
	PathNode *left = new PathNode(0, currentNode, 0, sf::Vector2i(currentNode->getPos().x - 1, currentNode->getPos().y));
	mOpenList.push_back(left);
	PathNode *right = new PathNode(0, currentNode, 0, sf::Vector2i(currentNode->getPos().x + 1, currentNode->getPos().y));
	mOpenList.push_back(right);
	PathNode *top = new PathNode(0, currentNode, 0, sf::Vector2i(currentNode->getPos().x, currentNode->getPos().y));
	mOpenList.push_back(top);
	PathNode *bot = new PathNode(0, currentNode, 0, sf::Vector2i(currentNode->getPos().x - 1, currentNode->getPos().y));
	mOpenList.push_back(bot);
}

bool PathFinder::inClosed(PathNode *node)
{
	for(closedList::size_type i = 0; i < mClosedList.size(); i++)
	{
		return node == mClosedList[i];
	}
}

