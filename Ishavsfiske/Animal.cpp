//Version: 0.1.4
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_4
#error Animal.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"
#include "Animal.h"

#include <Angler\DrawNode.h>
#include <Angler\Scale.h>

using namespace Angler::Nodes;

Animal::Animal(unsigned long id, Angler::Node *parent, Angler::Game *owner)
	: Node(id, parent), mOwner(owner), mStartX(0.5), mStartY(0.5)
{
}

Animal::Animal(unsigned long id, Angler::Game *owner)
	: Node(id), mOwner(owner), mStartX(0.5), mStartY(0.5)
{
}

void Animal::mInit()
{
	unsigned id = getID();

	mRootTranslation = new Translation(id + 0x0001, this, mStartX, mStartY);
	mRootRotation = new Rotation(id + 0x0003, mRootTranslation, 0);
	mAnimalRoot = new Node(id + 0x0004, mRootRotation);

	/*mBearSprite = new SpriteNode(getID() + 0x1000, this, 1, sf::Vector2f(0, 0), sf::Vector2f(0, 0.25), sf::Vector2f(0.25, 0.25));*/
}

void Animal::update(Angler::Game *context, float time, float deltaTime, bool changed)
{
	mChanged |= changed;
	
	mUpdateChildren(context, time, deltaTime);
}
