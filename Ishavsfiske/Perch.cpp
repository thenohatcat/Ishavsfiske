//Version: 0.1.4
//Author: Marcus Persson
//Contributors:

#ifndef ISHAV_0_1_4
#error School.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"
#include "Perch.h"
#include "IceBreaker.h"
#include "FishingBoat.h"

using namespace Ishavsfiske;

Perch::Perch(unsigned long id, Angler::Node *parent, IshavsfiskeGame *owner)
	: School(id, parent, owner)
{
	mInit();
}

Perch::Perch(unsigned long id, IshavsfiskeGame *owner)
	: School(id, owner)
{
	mInit();
}

Perch::~Perch()
{
	School::~School();
}

void Perch::update(Angler::Game *context, float time, float deltaTime, bool changed)
{
	if(!mPaused)
	{
		School::update(context, time, deltaTime, changed);
	}
}

void Perch::mInit()
{
	School::mInit();
}