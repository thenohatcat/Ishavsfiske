//Version: 0.1.4
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_4
#error PathNode.cpp: Wrong version 0.1.4
#endif

#include "PathNode.h"

PathNode::PathNode()
	: mH(0), mG(0), mF(0)
{
}

PathNode::PathNode(unsigned int id, PathNode *parent, /*PathNode *child,*/ sf::Vector2i pos)
	: mH(0), mG(0), mF(0), mParent(parent), /*mChild(child),*/ mID(id), mPos(pos)
{
	calcF();
}

void PathNode::setH(int h)
{
	mH = h;
	calcF();
}

void PathNode::setG(int g)
{
	mG = g;
	calcF();
}

void PathNode::setF(int f)
{
	mF = f;
}

int PathNode::getH()
{
	return mH;
}

int PathNode::getG()
{
	return mG;
}

int PathNode::getF()
{
	return mF;
}

void PathNode::addH(int h)
{
	mH += h;
	calcF();
}

void PathNode::addG(int g)
{
	mG += g;
	calcF();
}

void PathNode::addF(int f)
{
	mF += f;
}

int PathNode::getPathDir()
{
	return mDir;
}

void PathNode::calcF()
{
	mF = mH + mG;
}

PathNode *PathNode::getParent()
{
	return mParent;
}

void PathNode::setParent(PathNode *parent)
{
	mParent = parent;
}

unsigned long PathNode::getID()
{
	return mID;
}

sf::Vector2i PathNode::getPos()
{
	return mPos;
}