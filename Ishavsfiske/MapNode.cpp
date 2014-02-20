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
	new Angler::Nodes::SpriteNode(getID() + 0x4000, this, 0, sf::Vector2f(0, 0), sf::Vector2f(700/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
	mSprite = new Angler::Nodes::SpriteNode(getID() + 0x1000, this, 1, sf::Vector2f(0, 0), sf::Vector2f(0, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));

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
		mSprite->setCropOrigin(700/1500.0, 0);
		break;
	case 0x10:
		mSprite->setCropOrigin(500.0/1500.0f, 625.0/1600.0f);
		break;
	case 0x11:
		mSprite->setCropOrigin(450.0/1500.0f, 625.0/1600.0f);
	}
}