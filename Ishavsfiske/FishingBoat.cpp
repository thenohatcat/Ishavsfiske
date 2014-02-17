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
		mShipRoot, 2.5/20, 2.5/20);
	new Angler::Nodes::DrawNode(getID() + 0x0101, s, 1, 0.5, 0.5);

	std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(1.5/2.5*(-0.5 + (37.5 / 75.0)), -0.5 + (-2 / 125.0)));
	pts.push_back(sf::Vector2f(1.5/2.5*(-0.5 + (29 / 75.0)), -0.5 + (2 / 125.0)));
	pts.push_back(sf::Vector2f(1.5/2.5*(-0.5 + (23 / 75.0)), -0.5 + (8 / 125.0)));
	pts.push_back(sf::Vector2f(1.5/2.5*(-0.5 + (12 / 75.0)), -0.5 + (32 / 125.0)));
	pts.push_back(sf::Vector2f(1.5/2.5*(-0.5 + (12 / 75.0)), -0.5 + (69 / 125.0)));
	pts.push_back(sf::Vector2f(1.5/2.5*(-0.5 + (17 / 75.0)), -0.5 + (103 / 125.0)));
	pts.push_back(sf::Vector2f(1.5/2.5*(-0.5 + (18 / 75.0)), -0.5 + (125 / 125.0)));

	pts.push_back(sf::Vector2f(1.5/2.5*(-0.5 + (56 / 75.0)), -0.5 + (125 / 125.0)));
	pts.push_back(sf::Vector2f(1.5/2.5*(-0.5 + (57 / 75.0)), -0.5 + (103 / 125.0)));
	pts.push_back(sf::Vector2f(1.5/2.5*(-0.5 + (62 / 75.0)), -0.5 + (69 / 125.0)));
	pts.push_back(sf::Vector2f(1.5/2.5*(-0.5 + (62 / 75.0)), -0.5 + (32 / 125.0)));
	pts.push_back(sf::Vector2f(1.5/2.5*(-0.5 + (51 / 75.0)), -0.5 + (8 / 125.0)));
	pts.push_back(sf::Vector2f(1.5/2.5*(-0.5 + (45 / 75.0)), -0.5 + (2 / 125.0)));
	/*pts.push_back(sf::Vector2f(-(2/3.5 * 0.5), -0.5));
	pts.push_back(sf::Vector2f(2/3.5 * 0.5, -0.5));
	pts.push_back(sf::Vector2f(2/3.5 * 0.5, 0.5));
	pts.push_back(sf::Vector2f(-(2/3.5 * 0.5), 0.5));*/
	new Angler::Nodes::CollisionNode(getID() + 0x0102, s, pts, 0);

	Angler::Nodes::Translation *craneT = new Angler::Nodes::Translation(getID() + 0x0103, mShipRoot, 
		2.5/20 * 1.5/2.5*(-0.5+0.506), 2.5/20 * (-0.5+0.672));
	Angler::Nodes::Scale *craneS = new Angler::Nodes::Scale(getID() + 0x0104, craneT, 1.0/20, 1.0/20);
	mCraneRotation = new Angler::Nodes::Rotation(getID() + 0x0105, craneS, 0);
	new Angler::Nodes::DrawNode(getID() + 0x0106, mCraneRotation, 2, 2/3.0*0.075, 0.5);

	Angler::Nodes::Translation *lampT = new Angler::Nodes::Translation(getID() + 0x0103, mShipRoot, 
		2.5/20 * 1.5/2.5 * (-0.5+0.586), 2.5/20 * (-0.5+0.304));
	Angler::Nodes::Scale *lampS = new Angler::Nodes::Scale(getID() + 0x0104, lampT, 1.0/40, 1.0/40);
	mLampRotation = new Angler::Nodes::Rotation(getID() + 0x0105, lampS, 0);
	new Angler::Nodes::DrawNode(getID() + 0x0106, mLampRotation, 2, 0.5, 0.5);
}

void FishingBoat::update(Angler::Game *context, float time, float deltaTime, bool changed)
{
	mCraneRotation->setRotation(45*sin(time));
	mLampRotation->setRotation(90*sin(time));

	Ship::update(context, time, deltaTime, changed);
}