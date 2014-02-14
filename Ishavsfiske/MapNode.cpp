//Version: 0.1.3
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_3
#error MapNode.cpp: Wrong version 0.1.3
#endif

#include "MapNode.h"
#include "Map.h"

#include <Angler\Transformation.h>
#include <Angler\Scale.h>
#include <Angler\Translation.h>
#include <Angler\DrawNode.h>

MapNode::MapNode(unsigned long id, Angler::Node *parent, sf::Texture *textureMap, Angler::Game *owner, int tile)
	: Node(id, parent), mTXMap(textureMap), mTile(tile)
{
	mInit();
}

MapNode::MapNode(unsigned long id, sf::Texture *textureMap, Angler::Game *owner, int tile)
	: Node(id), mTXMap(textureMap), mTile(tile)
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
	mSprite = new Angler::Nodes::SpriteNode(0, this, 0, mTXMap, sf::Vector2f(0.5, 0.5), sf::Vector2f(0, 0.5 * mTile), sf::Vector2f(0.5, 0.5));

	std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(0, 0));
	pts.push_back(sf::Vector2f(0, 1));
	pts.push_back(sf::Vector2f(1, 0));
	pts.push_back(sf::Vector2f(1, 1));
	new Angler::Nodes::CollisionNode(getID() + 0x1000, this, pts, 1);
}

int MapNode::getTile()
{
	return mTile;
}

void MapNode::setTile(int tileID)
{
	mTile = tileID;
	mSprite->setCropOrigin(0, 0.5 * tileID);
}