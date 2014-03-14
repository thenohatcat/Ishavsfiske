//Version: 0.1.4
//Author: Marcus Persson
//Contributors:

#ifndef ISHAV_0_1_4
#error School.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"
#include "Pinksalmon.h"
#include "FishingBoat.h"
#include "IceBreaker.h"

using namespace Ishavsfiske;

Pinksalmon::Pinksalmon(unsigned long id, Angler::Node *parent, IshavsfiskeGame *owner)
	: School(id, parent, owner)
{
	mInit();
}

Pinksalmon::Pinksalmon(unsigned long id, IshavsfiskeGame *owner)
	: School(id, owner)
{
	mInit();
}

Pinksalmon::~Pinksalmon()
{
	School::~School();
}

void Pinksalmon::update(Angler::Game *context, float time, float deltaTime, bool changed)
{
	if(!mPaused)
	{
		School::update(context, time, deltaTime, changed);

		if(School::scaredDistance(((IshavsfiskeGame*)context)->getIceBreaker()->getPosition()))
			School::scaredByBoat(((IshavsfiskeGame*)context)->getIceBreaker()->getPosition(), deltaTime, false);
		else if(School::scaredDistance(((IshavsfiskeGame*)context)->getShipFishing()->getPosition()))
			School::scaredByBoat(((IshavsfiskeGame*)context)->getShipFishing()->getPosition(), deltaTime, false);
	}
}

void Pinksalmon::mInit()
{
	School::mInit();
}