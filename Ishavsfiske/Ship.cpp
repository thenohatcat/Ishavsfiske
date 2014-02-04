//Version: 0.1.2
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_2
#error Ship.cpp: Wrong version 0.1.2
#endif

#include "Ship.h"

#include <Angler\DrawNode.h>
#include <Angler\Scale.h>
#include <Angler\CollisionNode.h>

using namespace Angler::Nodes;

Ishavsfiske::Ship::Ship(unsigned long id, Angler::Node *parent, sf::Texture *txShip, sf::Texture *txCrane, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id, parent), mTXShip(txShip), mTXCrane(txCrane), mOwner(owner)
{
	mInit();
}

Ishavsfiske::Ship::Ship(unsigned long id, sf::Texture *txShip, sf::Texture *txCrane, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mTXShip(txShip), mTXCrane(txCrane), mOwner(owner)
{
	mInit();
}

void Ishavsfiske::Ship::mInit()
{
	mTransl = new Translation(0, this, 0.5, 0.5);
	Scale *s = new Scale(0, mTransl, 1.75/10, 1.75/10);
	mRotation = new Rotation(0, s, 0);
	new DrawNode(0, mRotation, 1, mTXShip, 0.5, 0.5);	
	
	std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(-(2/3.5 * 0.5), -0.5));
	pts.push_back(sf::Vector2f(2/3.5 * 0.5, -0.5));
	pts.push_back(sf::Vector2f(2/3.5 * 0.5, 0.5));
	pts.push_back(sf::Vector2f(-(2/3.5 * 0.5), 0.5));
	mCol = new CollisionNode(0, new Scale(0, mRotation, -1, 1), pts);

	mRotationA = new Rotation(0, mRotation, 0);
	Scale *s2 = new Scale(0, mRotationA, 1/3.5, 1/3.5);
	new DrawNode(getID() + 8, s2, 2, mTXCrane, 0.25, 0.5);

	std::vector<sf::Vector2f> pts2;
	pts2.push_back(sf::Vector2f(-3 * 0.75, -0.5));
	pts2.push_back(sf::Vector2f(3 * 0.25, -0.5));
	pts2.push_back(sf::Vector2f(3 * 0.25, 0.5));
	pts2.push_back(sf::Vector2f(-3 * 0.75, 0.5));
	//new CollisionNode(0, new Scale(0, s2, -1, 1), pts2); 
}

void Ishavsfiske::Ship::move(float x, float y)
{
	//This cumbersome code will be fixed by the next version
	//Rotation r(0, mRotation->getRotation());
	Node *n = new Node(0);
	Scale r(0, new Rotation(0, n, mRotation->getRotation()), -0.5, 0.5);
	sf::Vector2f tv = r.transform(sf::Vector2f(x, y));
	mTransl->translate(tv);
	delete n;
}

void Ishavsfiske::Ship::update(Angler::Game *context, float time, float deltaTime)
{
	mRotationA->setRotation(-90 + 45 * (2 - sin(time)));
}

void Ishavsfiske::Ship::rotate(float r)
{
	mRotation->rotate(r);
}

Angler::Nodes::CollisionNode Ishavsfiske::Ship::getCol()
{
	return *mCol;
}