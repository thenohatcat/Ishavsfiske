//Version: 0.1.4
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_4
#error PathFinder.cpp: Wrong version 0.1.4
#endif

#include "PathFinder.h"

static const int moveCost2486 = 10;

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
	mStartNode = start;
	mGoalNode = goal;
	mOpenList.push_back(mStartNode);

	while(!mOpenList.empty())
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

		if(mCurrent == mGoalNode)
		{
			mGoalNode->setParent(mCurrent);
			break;
		}
		
		genSuccessors(mCurrent);

		for(vector<PathNode*>::const_iterator i = mOpenList.begin(); i != mOpenList.end(); i++)
		{
			PathNode *node = *i;
			node->setG(mCurrent->getG() + moveCost2486);
			//if(!inClosed(node)) // Check to ignore if in closed list
			//{
				if(node->getParent() == mCurrent)
				{
					if(node->getF() < mCurrent->getF())
					{
						mCurrent = node;
					}
				}
				/*else if(inClosed(node) && node->getParent() == mCurrent)
				{
					if(node->getF() < mCurrent->getF())
					{
						node->setParent(mCurrent);
						mCurrent = node;
					}
				}*/
				node->setParent(mCurrent);
		}
		mClosedList.push_back(mCurrent);
	}
}

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

// Calculates all H values in every node
void PathFinder::calcAllH(PathNode *map[])
{
	for(int y = 0; y < 10; y++)
		for(int x = 0; x < 10; x++)
			map[x + y * 10]->setH(detHVal(x, y));
}

// Determine the H value
unsigned int PathFinder::detHVal(int x, int y)
{
	int hVal = 0;
	hVal += mGoalNode->getPos().x - x;
	hVal += mGoalNode->getPos().y - y;
	return hVal;
}

void PathFinder::recStructPath()
{
	PathNode *p = mGoalNode;
	while(p != 0)
	{
		mPathList.push_back(p);
		p = p->getParent();
	}
}


// NOTE TO MYSELF!!
// Make do not generate successors if successor already is in any list or if theres no PathNode in that position
void PathFinder::genSuccessors(PathNode *currentNode)
{
	PathNode *left = new PathNode(0, currentNode, sf::Vector2i(currentNode->getPos().x - 1, currentNode->getPos().y));
	mOpenList.push_back(left);
	PathNode *right = new PathNode(0, currentNode, sf::Vector2i(currentNode->getPos().x + 1, currentNode->getPos().y));
	mOpenList.push_back(right);
	PathNode *top = new PathNode(0, currentNode, sf::Vector2i(currentNode->getPos().x, currentNode->getPos().y));
	mOpenList.push_back(top);
	PathNode *bot = new PathNode(0, currentNode, sf::Vector2i(currentNode->getPos().x - 1, currentNode->getPos().y));
	mOpenList.push_back(bot);
}

// Check if the PathNode is in closed list
bool PathFinder::inClosed(PathNode *node)
{
	for(closedList::size_type i = 0; i < mClosedList.size(); i++)
	{
		return node == mClosedList[i];
	}
}

