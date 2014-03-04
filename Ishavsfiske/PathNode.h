//Version: 0.1.4
//Author: Sihao Li
//Contributors:

#ifndef INC_PATHNODE_H
#define INC_PATHNODE_H

#ifdef ISHAV_0_1_4

class PathNode
{
public:
	PathNode(int h_score, int g_score, int dir);
	void setH(int h), setG(int g), setF(int f);
	int getH(), getG(), getF();
	void addH(int h), addG(int g), addF(int f);

	int getPathDir();
protected:
private:
	int mH, mG, mF;
	int mDir;

	void calcF();
};


#else
#error PathNode.h: Wrong version 0.1.4
#endif

#endif