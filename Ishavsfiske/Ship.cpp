//Version: 0.1.1
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_1
#error Ship.cpp: Wrong version 0.1.1
#endif

#include "Ship.h"

#include <Angler\DrawNode.h>
#include <Angler\Scale.h>

using Angler::Nodes::Translation;
using Angler::Nodes::Rotation;

Ishavsfiske::Ship::Ship(unsigned long id, Angler::Node *parent, sf::Texture *tx, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id, parent), mTX(tx), mOwner(owner)
{
	mInit();
}

Ishavsfiske::Ship::Ship(unsigned long id, sf::Texture *tx, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mTX(tx), mOwner(owner)
{
	mInit();
}

void Ishavsfiske::Ship::mInit()
{
	mTransl = new Translation(getID() + 1, this, 0.5, 0.5);
	Angler::Nodes::Scale *s = new Angler::Nodes::Scale(getID() + 2, mTransl, 0.1, 0.1);
	mRotation = new Rotation(getID() + 3, s, 0);
	new Angler::Nodes::DrawNode(getID() + 4, mRotation, 0, mTX, 0.5, 0.5);
	
	Angler::Nodes::Translation *t1 = new Angler::Nodes::Translation(getID() + 5, mRotation, 0.375, 0);
	
	mRotationA = new Rotation(getID() + 6, t1, 0);
	Angler::Nodes::Scale *s2 = new Angler::Nodes::Scale(getID() + 7, mRotationA, 0.50, 0.25);
	new Angler::Nodes::DrawNode(getID() + 8, s2, 0, mTX, 0.25, 0.5);

	Angler::Nodes::Translation *t2 = new Angler::Nodes::Translation(getID() + 5, mRotation, -0.375, 0);

	mRotationB = new Rotation(getID() + 9, t2, 0);
	Angler::Nodes::Scale *s3 = new Angler::Nodes::Scale(getID() + 10, mRotationB, -0.50, 0.25);
	new Angler::Nodes::DrawNode(getID() + 11, s3, 0, mTX, 0.25, 0.5);
}

void Ishavsfiske::Ship::move(float x, float y)
{
	//This cumbersome code will be fixed by the next version
	Rotation r(0, new Node(0), -mRotation->getRotation());
	sf::Vector2f tv = r.transform(sf::Vector2f(x, y));
	mTransl->translate(tv);
}

void Ishavsfiske::Ship::update(Angler::Game *context, float time, float deltaTime)
{
	mRotationA->setRotation(-90 + 45 * (2 - sin(time)));
	mRotationB->setRotation(-90 + 45 * (2 - sin(time)));
}

void Ishavsfiske::Ship::rotate(float r)
{
	mRotation->rotate(r);
}