//Version: 0.1.5
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_5
#error Seagull.cpp: Wrong version 0.1.5
#endif

#include "Seagull.h"

#include <Angler\DrawNode.h>
#include <Angler\AnimatedNode.h>
#include <Angler\Scale.h>
#include <Angler\Translation.h>
#include <Angler\Rotation.h>
#include <Angler\CollisionNode.h>

using namespace Ishavsfiske;
using namespace Angler::Nodes;

Seagull::Seagull(unsigned long id, Angler::Node *parent, Angler::Game *owner)
	: Animal(id, parent, owner)
{
	mInit();
}

Seagull::Seagull(unsigned long id, Angler::Game *owner)
	: Animal(id, owner)
{
	mInit();
}

Seagull::~Seagull()
{
	Animal::~Animal();
}

void Seagull::update(Angler::Game* context, float time, float deltaTime, bool changed)
{
	Animal::update(context, time, deltaTime, changed);
}

void Seagull::attack()
{

}

void Seagull::mInit()
{
	mStartX = 0.5f;
	mStartY = 0.5f;

	Animal::mInit();

	// Seagull ID?
	Angler::Nodes::Scale *s = new Angler::Nodes::Scale(getID() + 0x0123, mAnimalRoot, 1, 1);

	/*std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(1, 0));
	pts.push_back(sf::Vector2f(0, 0));
	pts.push_back(sf::Vector2f(0, 1));
	pts.push_back(sf::Vector2f(1, 1));
	new Angler::Nodes::CollisionNode(getID(), s, pts, 0);*/


	std::vector<sf::Vector2f> anime;
	anime.push_back(sf::Vector2f(0, 0));
	anime.push_back(sf::Vector2f(1/5, 0));
	anime.push_back(sf::Vector2f(2/5, 0));
	anime.push_back(sf::Vector2f(3/5, 0));
	anime.push_back(sf::Vector2f(4/5, 0));
	new Angler::Nodes::AnimatedNode(getID() + 0x123, s, 6, anime, 1/5, 0, 0, 1/5, 1); // ID?
}

