//Version: 0.1.3
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_3
#error FishingBoat.cpp: Wrong version 0.1.3
#endif

#include "FishingBoat.h"

#include <Angler\DrawNode.h>
#include <Angler\Scale.h>

using namespace Ishavsfiske;

FishingBoat::FishingBoat(unsigned long id, Angler::Node *parent,
			sf::Texture *textureShip, sf::Texture *textureCrane, 
			Ishavsfiske::IshavsfiskeGame *owner)
			: Ship(id, parent, owner), mTextureCrane(textureCrane), mTextureShip(textureShip)
{
	mInit();
}

FishingBoat::FishingBoat(unsigned long id, sf::Texture *textureShip, 
			sf::Texture *textureCrane, Ishavsfiske::IshavsfiskeGame *owner)
			: Ship(id, owner), mTextureCrane(textureCrane), mTextureShip(textureShip)
{
	mInit();
}

void FishingBoat::mInit()
{
	mStartX = 0.5;
	mStartY = 0.5;

	Ship::mInit();

	Angler::Nodes::Scale *s = new Angler::Nodes::Scale(getID() + 0x0100,
		mShipRoot, 3.5/20, 3.5/20);
	new Angler::Nodes::DrawNode(getID() + 0x0101, s, 1, mTextureShip, 0.5, 0.5);

	std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(-(2/3.5 * 0.5), -0.5));
	pts.push_back(sf::Vector2f(2/3.5 * 0.5, -0.5));
	pts.push_back(sf::Vector2f(2/3.5 * 0.5, 0.5));
	pts.push_back(sf::Vector2f(-(2/3.5 * 0.5), 0.5));
	new Angler::Nodes::CollisionNode(getID() + 0x0102, s, pts);

	Angler::Nodes::Translation *craneT = new Angler::Nodes::Translation(getID() + 0x0103, mShipRoot, 0, 0);
	Angler::Nodes::Scale *craneS = new Angler::Nodes::Scale(getID() + 0x0104, craneT, 1.0/20, 1.0/20);
	mCraneRotation = new Angler::Nodes::Rotation(getID() + 0x0105, craneS, 0);
	new Angler::Nodes::DrawNode(getID() + 0x0106, mCraneRotation, 2, mTextureCrane, 0.175, 0.5);
}

void FishingBoat::update(Angler::Game *context, float time, float deltaTime)
{
	Ship::update(context, time, deltaTime);
	
	mCraneRotation->setRotation(45*sin(time));
}