//Version: 0.1.2
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_2
#error Wreck_draw.cpp: Wrong version 0.1.2
#endif

#include "Wreck.h"

#include <Angler\Translation.h>
#include <Angler\Scale.h>
#include <Angler\CollisionNode.h>
#include <Angler\DrawNode.h>
#include <Angler\Rotation.h>

using namespace Ishavsfiske;
using namespace Angler::Nodes;

Wreck::Wreck(unsigned long id, Node *parent, sf::Texture *tx)
	: Node(id, parent), mTX(tx)
{
	mInit();
}

Wreck::Wreck(unsigned long id, sf::Texture *tx)
	: Node(id), mTX(tx)
{
	mInit();
}

void Wreck::mInit()
{
	Translation *t = new Translation(0, this, 1, 0.5);
	Rotation *r = new Rotation(0, t, 45);
	Scale *s = new Scale(0, r, 1.75/10.0, 1.75/10.0);
	DrawNode *d = new DrawNode(0, s, 1, mTX, 0.5, 0.5);
	std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(-(2/3.5 * 0.5), -0.5));
	pts.push_back(sf::Vector2f(2/3.5 * 0.5, -0.5));
	pts.push_back(sf::Vector2f(2/3.5 * 0.5, 0.5));
	pts.push_back(sf::Vector2f(-(2/3.5 * 0.5), 0.5));
	CollisionNode *c = new CollisionNode(0, new Scale(0, s, -1, 1), pts);
}