//Version: 0.1.4
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_4
#error MapNode.cpp: Wrong version 0.1.4
#endif

#include "MapNode.h"
#include "Map.h"

#include <Angler\Transformation.h>
#include <Angler\Scale.h>
#include <Angler\Translation.h>
#include <Angler\DrawNode.h>
#include <Angler\CollisionNode.h>

MapNode::MapNode(unsigned long id, Angler::Node *parent, Angler::Game *owner, int tile)
	: Node(id, parent), mTile(tile)
{
	mInit();
}

MapNode::MapNode(unsigned long id, Angler::Game *owner, int tile)
	: Node(id), mTile(tile)
{
	mInit();
}

void MapNode::draw(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime)
{
	mDrawChildren(context, graphics, time, deltaTime);
}

void MapNode::update(Angler::Game* context, float time, float deltaTime)
{
	mUpdateChildren(context, time, deltaTime);
}

void MapNode::mInit()
{
	mSprite = new Angler::Nodes::SpriteNode(getID() + 0x1000, this, 0, sf::Vector2f(0, 0), sf::Vector2f(0, 0.25 * mTile), sf::Vector2f(0.25, 0.25));

	std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(1, 0));
	pts.push_back(sf::Vector2f(0, 0));
	pts.push_back(sf::Vector2f(0, 1));
	pts.push_back(sf::Vector2f(1, 1));
	new Angler::Nodes::CollisionNode(getID() + 0x2000, this, pts, 1);
}

int MapNode::getTile()
{
	return mTile;
}

void MapNode::setTile(int tileID)
{
	mTile = tileID;
	switch(mTile)
	{
	case 0:
		mSprite->setCropOrigin(0, 0);
		break;
	case 0x10:
		mSprite->setCropOrigin(0.25, 0);
		break;
	case 0x11:
		mSprite->setCropOrigin(0, 0.25);
		break;
	case 0x12:
		mSprite->setCropOrigin(0.75, 0);
		break;
	case 0x13:
		mSprite->setCropOrigin(0.25, 0.25);
		break;
	case 0x14:
		mSprite->setCropOrigin(0.5, 0.25);
		break;
	case 0x15:
		mSprite->setCropOrigin(0.75, 0.25);
		break;
	case 0x16:
		mSprite->setCropOrigin(0, 0.5);
		break;
	case 0x17:
		mSprite->setCropOrigin(0.25, 0.5);
		break;
	case 0x18:
		mSprite->setCropOrigin(0.5, 0.5);
		break;
	case 0x19:
		mSprite->setCropOrigin(0.5, 0);
		break;
	}
}