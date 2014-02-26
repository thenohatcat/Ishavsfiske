//Version: 0.1.4
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_4
#error PolarBear.cpp: Wrong version 0.1.4
#endif

#include "PolarBear.h"

#include <Angler\DrawNode.h>
#include <Angler\Scale.h>

PolarBear::PolarBear(unsigned long id, Angler::Node *parent, Angler::Game *owner)
	: Animal(id, parent, owner)
{
	mInit();
}

PolarBear::PolarBear(unsigned long id, Angler::Game *owner)
	: Animal(id, owner)
{
	mInit();
}

void PolarBear::update(Angler::Game* context, float time, float deltaTime, bool changed)
{
	Animal::update(context, time, deltaTime, changed);
}

//void PolarBear::attack()
//{
//
//}
//
//void PolarBear::move(float x, float y)
//{
//	
//}

void PolarBear::mInit()
{
	//mStartX = 0.5;
	//mStartY = 0.5;

	Animal::mInit();

	Angler::Nodes::Scale *s = new Angler::Nodes::Scale(getID() + 0x0100, mAnimalRoot, 2.5f/20, 2.5f/20);
	new Angler::Nodes::DrawNode(getID() + 0x0101, s, 5, 0.5f, 0.5f);
}