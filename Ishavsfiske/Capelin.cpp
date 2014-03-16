//Version: 0.1.5
//Author: Marcus Persson
//Contributors:

#ifndef ISHAV_0_1_5
#error School.cpp: Wrong version 0.1.5
#endif

#include "IshavsfiskeGame.h"
#include "Capelin.h"
#include "IceBreaker.h"
#include "FishingBoat.h"

using namespace Ishavsfiske;

Capelin::Capelin(unsigned long id, Angler::Node *parent, IshavsfiskeGame *owner)
	: School(id, parent, owner)
{
	mInit();
}

Capelin::Capelin(unsigned long id, IshavsfiskeGame *owner)
	: School(id, owner)
{
	mInit();
}

Capelin::~Capelin()
{
	School::~School();
}

void Capelin::update(Angler::Game *context, float time, float deltaTime, bool changed)
{
	if(!mPaused)
	{
		School::update(context, time, deltaTime, changed);

		if(School::scaredDistance(((IshavsfiskeGame*)context)->getIceBreaker()->getPosition()))
			School::scaredByBoat(((IshavsfiskeGame*)context)->getIceBreaker()->getPosition(), deltaTime, true);
		else if(School::scaredDistance(((IshavsfiskeGame*)context)->getShipFishing()->getPosition()))
			School::scaredByBoat(((IshavsfiskeGame*)context)->getShipFishing()->getPosition(), deltaTime, true);
	}
}

void Capelin::mInit()
{
	School::mInit();
}