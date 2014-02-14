//Version: 0.1.3
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_3
#error Wreck_draw.cpp: Wrong version 0.1.3
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
	unsigned long id = getID();
	Translation *t = new Translation(id + 0x0001, this, 0, 0);
	Rotation *r = new Rotation(id + 0x0002, t, 0);
	Scale *s = new Scale(id + 0x0003, r, 1.75/10.0, 1.75/10.0);
	DrawNode *d = new DrawNode(id + 0x0004, s, 1, mTX, 0.5, 0.5);
	std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(-(2/3.5 * 0.5), -0.5));
	pts.push_back(sf::Vector2f(2/3.5 * 0.5, -0.5));
	pts.push_back(sf::Vector2f(2/3.5 * 0.5, 0.5));
	pts.push_back(sf::Vector2f(-(2/3.5 * 0.5), 0.5));
	CollisionNode *c = new CollisionNode(id + 0x1005, s, pts, 0);
}