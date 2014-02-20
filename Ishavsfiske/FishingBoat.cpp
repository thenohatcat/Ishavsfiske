//Version: 0.1.4
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_4
#error FishingBoat.cpp: Wrong version 0.1.4
#endif

#include "FishingBoat.h"

#include <Angler\DrawNode.h>
#include <Angler\Scale.h>

using namespace Ishavsfiske;

FishingBoat::FishingBoat(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner)
			: Ship(id, parent, owner)
{
	mInit();
}

FishingBoat::FishingBoat(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
			: Ship(id, owner)
{
	mInit();
}

void FishingBoat::mInit()
{
	mStartX = 0.5;
	mStartY = 0.5;

	Ship::mInit();

	Angler::Nodes::Scale *s = new Angler::Nodes::Scale(getID() + 0x0100,
		mShipRoot, 2.5f/20, 2.5f/20);
	new Angler::Nodes::DrawNode(getID() + 0x0101, s, 1, 0.5f, 0.5f);

	std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(1.5f/2.5f*(-0.5f + (37.5f / 75.0f)), -0.5f + (-2 / 125.0f)));
	pts.push_back(sf::Vector2f(1.5f/2.5f*(-0.5f + (29 / 75.0f)), -0.5f + (2 / 125.0f)));
	pts.push_back(sf::Vector2f(1.5f/2.5f*(-0.5f + (23 / 75.0f)), -0.5f + (8 / 125.0f)));
	pts.push_back(sf::Vector2f(1.5f/2.5f*(-0.5f + (12 / 75.0f)), -0.5f + (32 / 125.0f)));
	pts.push_back(sf::Vector2f(1.5f/2.5f*(-0.5f + (12 / 75.0f)), -0.5f + (69 / 125.0f)));
	pts.push_back(sf::Vector2f(1.5f/2.5f*(-0.5f + (17 / 75.0f)), -0.5f + (103 / 125.0f)));
	pts.push_back(sf::Vector2f(1.5f/2.5f*(-0.5f + (18 / 75.0f)), -0.5f + (125 / 125.0f)));

	pts.push_back(sf::Vector2f(1.5f/2.5f*(-0.5f + (56 / 75.0f)), -0.5f + (125 / 125.0f)));
	pts.push_back(sf::Vector2f(1.5f/2.5f*(-0.5f + (57 / 75.0f)), -0.5f + (103 / 125.0f)));
	pts.push_back(sf::Vector2f(1.5f/2.5f*(-0.5f + (62 / 75.0f)), -0.5f + (69 / 125.0f)));
	pts.push_back(sf::Vector2f(1.5f/2.5f*(-0.5f + (62 / 75.0f)), -0.5f + (32 / 125.0f)));
	pts.push_back(sf::Vector2f(1.5f/2.5f*(-0.5f + (51 / 75.0f)), -0.5f + (8 / 125.0f)));
	pts.push_back(sf::Vector2f(1.5f/2.5f*(-0.5f + (45 / 75.0f)), -0.5f + (2 / 125.0f)));
	new Angler::Nodes::CollisionNode(getID() + 0x0102, s, pts, 0);

	Angler::Nodes::Translation *craneT = new Angler::Nodes::Translation(getID() + 0x0103, mShipRoot, 
		2.5f/20.0f * 1.5f/2.5f*(-0.5f+0.506f), 2.5f/20.0f * (-0.5+0.672f));
	Angler::Nodes::Scale *craneS = new Angler::Nodes::Scale(getID() + 0x0104, craneT, 1/20.0f, 1/20.0f);
	mCraneRotation = new Angler::Nodes::Rotation(getID() + 0x0105, craneS, 0);
	new Angler::Nodes::DrawNode(getID() + 0x0106, mCraneRotation, 2, 2.0f/3.0f*0.075f, 0.5);

	Angler::Nodes::Translation *lampT = new Angler::Nodes::Translation(getID() + 0x0103, mShipRoot, 
		2.5f/20.0f * 1.5f/2.5f * (-0.5f+0.586f), 2.5f/20.0f * (-0.5f+0.304f));
	Angler::Nodes::Scale *lampS = new Angler::Nodes::Scale(getID() + 0x0104, lampT, 1.0f/40.0f, 1.0f/40.0f);
	mLampRotation = new Angler::Nodes::Rotation(getID() + 0x0105, lampS, 0);
	new Angler::Nodes::DrawNode(getID() + 0x0106, mLampRotation, 2, 0.5f, 0.5f);
}

void FishingBoat::update(Angler::Game *context, float time, float deltaTime, bool changed)
{
	mCraneRotation->setRotation(90-45*sin(time));
	mLampRotation->setRotation(90*sin(time));

	Ship::update(context, time, deltaTime, changed);
}