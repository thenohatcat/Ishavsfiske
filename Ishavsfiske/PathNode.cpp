//Version: 0.1.4
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_4
#error PathNode.cpp: Wrong version 0.1.4
#endif

#include "PathNode.h"

PathNode::PathNode(int h_score, int g_score, int dir)
	: mH(h_score), mG(g_score), mF(h_score + g_score), mDir(dir)
{

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