//Version: 0.1.5
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_5
#error MapNode.cpp: Wrong version 0.1.5
#endif

#include "MapNode.h"
#include "Map.h"

#include <Angler\Transformation.h>
#include <Angler\Scale.h>
#include <Angler\Translation.h>
#include <Angler\AnimatedNode.h>
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

MapNode::~MapNode()
{
	Node::~Node();
}

void MapNode::draw(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime)
{
	if (mVisible)
		mDrawChildren(context, graphics, time, deltaTime);
}

void MapNode::mInit()
{
	std::vector<sf::Vector2f> ptsa;
	ptsa.push_back(sf::Vector2f(700/1500.0f, 0));
	ptsa.push_back(sf::Vector2f(750/1500.0f, 0));
	ptsa.push_back(sf::Vector2f(800/1500.0f, 0));
	ptsa.push_back(sf::Vector2f(850/1500.0f, 0));
	ptsa.push_back(sf::Vector2f(900/1500.0f, 0));
	ptsa.push_back(sf::Vector2f(950/1500.0f, 0));
	ptsa.push_back(sf::Vector2f(1000/1500.0f, 0));
	ptsa.push_back(sf::Vector2f(1050/1500.0f, 0));
	ptsa.push_back(sf::Vector2f(1100/1500.0f, 0));
	new Angler::Nodes::AnimatedNode(getID() + 0x4000, this, 0, ptsa, 0.1f, 0, 0, 50/1500.0f, 50/1600.0f);
	mSprite = new Angler::Nodes::SpriteNode(getID() + 0x1000, this, 1, sf::Vector2f(0, 0), sf::Vector2f(0, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));

	std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(1, 0));
	pts.push_back(sf::Vector2f(0, 0));
	pts.push_back(sf::Vector2f(0, 1));
	pts.push_back(sf::Vector2f(1, 1));
	mColl = new Angler::Nodes::CollisionNode(getID() + 0x2000, this, pts, 1);
}

int MapNode::getTile()
{
	return mTile;
}

void MapNode::setTile(int tileID)
{
	mTile = tileID;
	mSprite->setCropSize(50/1500.0f, 50/1600.0f);
	std::vector<sf::Vector2f> pts;
	switch(mTile)
	{
	case 0:
		//mSprite->setCropOrigin(700/1500.0f, 0);
		mSprite->setCropSize(0, 0);
		break;
	case 0x10:
	case 0x20:
		//Center
		pts.push_back(sf::Vector2f(1.0f, 0.0f));
		pts.push_back(sf::Vector2f(0.0f, 0.0f));
		pts.push_back(sf::Vector2f(0.0f, 1.0f));
		pts.push_back(sf::Vector2f(1.0f, 1.0f));
		mSprite->setCropOrigin(500/1500.0f, 625/1600.0f);
		break;
	case 0x11:
	case 0x21:
		//Broken center
		pts.push_back(sf::Vector2f(1.0f, 0.0f));
		pts.push_back(sf::Vector2f(0.0f, 0.0f));
		pts.push_back(sf::Vector2f(0.0f, 1.0f));
		pts.push_back(sf::Vector2f(1.0f, 1.0f));
		mSprite->setCropOrigin(450/1500.0f, 625/1600.0f);
		break;
	case 0x12:
	case 0x22:
		//Lower
		pts.push_back(sf::Vector2f(1.0f, 0.0f));
		pts.push_back(sf::Vector2f(0.0f, 0.0f));
		pts.push_back(sf::Vector2f(0.0f, 0.5f));
		pts.push_back(sf::Vector2f(1.0f, 0.5f));
		mSprite->setCropOrigin(450/1500.0f, 675/1600.0f);
		break;
	case 0x13:
	case 0x23:
		//Top right
		pts.push_back(sf::Vector2f(0.5f, 0.5f));
		pts.push_back(sf::Vector2f(0.0f, 0.5f));
		pts.push_back(sf::Vector2f(0.0f, 1.0f));
		pts.push_back(sf::Vector2f(0.5f, 1.0f));
		mSprite->setCropOrigin(600/1500.0f, 525/1600.0f);
		break;
	case 0x14:
	case 0x24:
		//Left
		pts.push_back(sf::Vector2f(1.0f, 0.0f));
		pts.push_back(sf::Vector2f(0.5f, 0.0f));
		pts.push_back(sf::Vector2f(0.5f, 1.0f));
		pts.push_back(sf::Vector2f(1.0f, 1.0f));
		mSprite->setCropOrigin(400/1500.0f, 575/1600.0f);
		break;
	case 0x15:
	case 0x25:
		//Top left
		pts.push_back(sf::Vector2f(1.0f, 0.5f));
		pts.push_back(sf::Vector2f(0.5f, 0.5f));
		pts.push_back(sf::Vector2f(0.5f, 1.0f));
		pts.push_back(sf::Vector2f(1.0f, 1.0f));
		mSprite->setCropOrigin(400/1500.0f, 525/1600.0f);
		break;
	case 0x16:
	case 0x26:
		//Top
		pts.push_back(sf::Vector2f(1.0f, 0.5f));
		pts.push_back(sf::Vector2f(0.0f, 0.5f));
		pts.push_back(sf::Vector2f(0.0f, 1.0f));
		pts.push_back(sf::Vector2f(1.0f, 1.0f));
		mSprite->setCropOrigin(450/1500.0f, 525/1600.0f);
		break;
	case 0x17:
	case 0x27:
		//Lower Left
		pts.push_back(sf::Vector2f(1.0f, 0.0f));
		pts.push_back(sf::Vector2f(0.5f, 0.0f));
		pts.push_back(sf::Vector2f(0.5f, 0.5f));
		pts.push_back(sf::Vector2f(1.0f, 0.5f));
		mSprite->setCropOrigin(400/1500.0f, 675/1600.0f);
		break;
	case 0x18:
	case 0x28:
		//Right
		pts.push_back(sf::Vector2f(0.5f, 0.0f));
		pts.push_back(sf::Vector2f(0.0f, 0.0f));
		pts.push_back(sf::Vector2f(0.0f, 1.0f));
		pts.push_back(sf::Vector2f(0.5f, 1.0f));
		mSprite->setCropOrigin(600/1500.0f, 575/1600.0f);
		break;
	case 0x19:
	case 0x29:
		//Lower right
		pts.push_back(sf::Vector2f(0.50f, 0.0f));
		pts.push_back(sf::Vector2f(0.0f, 0.0f));
		pts.push_back(sf::Vector2f(0.0f, 0.5f));
		pts.push_back(sf::Vector2f(0.5f, 0.5f));
		mSprite->setCropOrigin(600/1500.0f, 675/1600.0f);
		break;
	case 0x1A:
	case 0x2A:
		//Inner Lower Right
		pts.push_back(sf::Vector2f(1.0f, 0.0f));
		pts.push_back(sf::Vector2f(0.0f, 0.0f));
		pts.push_back(sf::Vector2f(0.0f, 1.0f));
		pts.push_back(sf::Vector2f(0.5f, 1.0f));
		pts.push_back(sf::Vector2f(1.0f, 0.5f));
		mSprite->setCropOrigin(700/1500.0f, 550/1600.0f);
		break;
	case 0x1B:
	case 0x2B:
		//Inner lower left
		pts.push_back(sf::Vector2f(1.0f, 0.0f));
		pts.push_back(sf::Vector2f(0.0f, 0.0f));
		pts.push_back(sf::Vector2f(0.0f, 0.5f));
		pts.push_back(sf::Vector2f(0.5f, 1.0f));
		pts.push_back(sf::Vector2f(1.0f, 1.0f));
		mSprite->setCropOrigin(650/1500.0f, 550/1600.0f);
		break;
	case 0x1C:
	case 0x2C:
		//Inner top left
		pts.push_back(sf::Vector2f(1.0f, 0.0f));
		pts.push_back(sf::Vector2f(0.5f, 0.0f));
		pts.push_back(sf::Vector2f(0.0f, 0.5f));
		pts.push_back(sf::Vector2f(0.0f, 1.0f));
		pts.push_back(sf::Vector2f(1.0f, 1.0f));
		mSprite->setCropOrigin(650/1500.0f, 500/1600.0f);
		break;
	case 0x1D:
	case 0x2D:
		//Inner top right
		pts.push_back(sf::Vector2f(1.0f, 0.5f));
		pts.push_back(sf::Vector2f(0.5f, 0.0f));
		pts.push_back(sf::Vector2f(0.0f, 0.0f));
		pts.push_back(sf::Vector2f(0.0f, 1.0f));
		pts.push_back(sf::Vector2f(1.0f, 1.0f));
		mSprite->setCropOrigin(700/1500.0f, 500/1600.0f);
		break;
	case 0x1F:
	case 0x2F:
		pts.push_back(sf::Vector2f(1.0f, 0.0f));
		pts.push_back(sf::Vector2f(0.0f, 0.0f));
		pts.push_back(sf::Vector2f(0.0f, 1.0f));
		pts.push_back(sf::Vector2f(1.0f, 1.0f));
		mSprite->setCropOrigin(650/1500.0f, 600/1600.0f);
		break;
	}
	mColl->setCollision(pts);
}