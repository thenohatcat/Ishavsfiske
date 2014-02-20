//Version: 0.1.4
//Author: Marcus Persson
//Contributors: 

#ifndef ISHAV_0_1_4
#error Ship.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"
#include "School.h"

using namespace Angler::Nodes;

Ishavsfiske::School::School(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id, parent), mOwner(owner), mVel(0, 0), mStartX(0.5f), mStartY(0.5f)
{

}

Ishavsfiske::School::School(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mOwner(owner), mVel(0, 0), mStartX(0.5f), mStartY(0.5f)
{

}

void Ishavsfiske::School::move(float x, float y)
{

}

void Ishavsfiske::School::getPosition()
{

}

void Ishavsfiske::School::setPosition(float x, float y)
{

}

int Ishavsfiske::School::fish(int ammount)
{

}

void Ishavsfiske::School::mInit()
{
	unsigned long id = getID();
	mRootTranslation = new Translation(id + 0x0001, this, mStartX, mStartY);
	mRootRotation = new Rotation(id + 0x0003, mRootTranslation, 0);
	mSchoolRoot = new Node(id + 0x0004, mRootRotation);
}