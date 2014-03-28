//Version: 0.1.5
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_5
#error Animal.cpp: Wrong version 0.1.5
#endif

#include "IshavsfiskeGame.h"
#include "Animal.h"
#include "Ship.h"
#include "FishingBoat.h"
#include "IceBreaker.h"

#include <Angler\DrawNode.h>
#include <Angler\Scale.h>
#include <iostream>

using namespace std;

using namespace Ishavsfiske;
using namespace Angler::Nodes;

#define PI 3.14159265f

Animal::Animal(unsigned long id, Angler::Node *parent, Angler::Game *owner)
	: Node(id, parent), mOwner(owner), mStartX(0.5), mStartY(0.5)
{
	
}

Animal::Animal(unsigned long id, Angler::Game *owner)
	: Node(id), mOwner(owner), mStartX(0), mStartY(0)
{
}

Animal::~Animal()
{
	delete mAnimalRoot;
	delete mRootRotation;
	delete mRootTranslation;

	Node::~Node();
}

void Animal::mInit()
{
	unsigned id = getID();

	mRootTranslation = new Translation(id + 0x0001, this, mStartX, mStartY);
	mRootRotation = new Rotation(id + 0x0002, mRootTranslation, 0);
	mAnimalRoot = new Node(id + 0x0003, mRootRotation);

	/*mBearSprite = new SpriteNode(getID() + 0x1000, this, 1, sf::Vector2f(0, 0), sf::Vector2f(0, 0.25), sf::Vector2f(0.25, 0.25));*/
}


void Animal::update(Angler::Game *context, float time, float deltaTime, bool changed)
{
	
}

void Animal::attack()
{
}


void Animal::rotate(float r)
{
	mRootRotation->rotate(r);

	mChanged = true;
}

void Animal::move(float x, float y)
{
	Rotation r(0, mRootRotation->getRotation());
	sf::Vector2f tv = r.transform(sf::Vector2f(5*x, 5*y));
	mRootTranslation->translate(tv);

	mChanged = true;
}

int Animal::mDirection(sf::Vector2f position)
{
	sf::Vector2f dir = position - mRootTranslation->getTranslation();
	if(dir.x > 0 && dir.y < 0)
		return 9;
	if(dir.x > 0 && dir.y > 0)
		return 3;
	if(dir.x < 0 && dir.y > 0)
		return 1;
	if(dir.x < 0 && dir.y < 0)
		return 7;
}

void Animal::collide()
{

}
