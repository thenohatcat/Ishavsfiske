//Version: 0.1.4
//Author: Marcus Persson
//Contributors: 

#ifndef ISHAV_0_1_4
#error School.cpp: Wrong version 0.1.4
#endif

#include <Angler\Scale.h>
#include <Angler\AnimatedNode.h>

#include "IshavsfiskeGame.h"
#include "School.h"

using namespace Angler::Nodes;

Ishavsfiske::School::School(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id, parent), mOwner(owner), mStartX(0.5f), mStartY(0.5f), mAmmount(10)
{
	mInit();
}

Ishavsfiske::School::School(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mOwner(owner), mStartX(0.5f), mStartY(0.5f), mAmmount(10)
{
	mInit();
}

void Ishavsfiske::School::mInit()
{
	mRootTranslation = new Translation(getID() + 0x2000, this, mStartX, mStartY);
	Angler::Nodes::Scale *s = new Angler::Nodes::Scale(getID() + 0x3000, mRootTranslation, 1/20.0f, 1/20.0f);
	mSchoolRoot = new Node(getID() + 0x0004, s);

	std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(1, 0));
	pts.push_back(sf::Vector2f(0, 0));
	pts.push_back(sf::Vector2f(0, 1));
	pts.push_back(sf::Vector2f(1 ,1));

	new Angler::Nodes::CollisionNode(getID() + 0x5000, mSchoolRoot, pts, 0);

	std::vector<sf::Vector2f> anim;
	anim.push_back(sf::Vector2f(0, 0));
	anim.push_back(sf::Vector2f(1/16.0f, 0));
	anim.push_back(sf::Vector2f(2/16.0f, 0));
	anim.push_back(sf::Vector2f(3/16.0f, 0));
	anim.push_back(sf::Vector2f(4/16.0f, 0));
	anim.push_back(sf::Vector2f(5/16.0f, 0));
	anim.push_back(sf::Vector2f(6/16.0f, 0));
	anim.push_back(sf::Vector2f(7/16.0f, 0));
	anim.push_back(sf::Vector2f(8/16.0f, 0));
	anim.push_back(sf::Vector2f(9/16.0f, 0));
	anim.push_back(sf::Vector2f(10/16.0f, 0));
	anim.push_back(sf::Vector2f(11/16.0f, 0));
	anim.push_back(sf::Vector2f(12/16.0f, 0));
	anim.push_back(sf::Vector2f(13/16.0f, 0));
	anim.push_back(sf::Vector2f(14/16.0f, 0));
	anim.push_back(sf::Vector2f(15/16.0f, 0));
	new Angler::Nodes::AnimatedNode(getID() + 0x1000, mSchoolRoot, 2, anim, 1/8.0f, 0.5f, 0.5f, 1/16.0f, 1);
}

void Ishavsfiske::School::move(float x, float y)
{
	mRootTranslation->translate(sf::Vector2f(5*x, 5*y));
}

sf::Vector2f Ishavsfiske::School::getPosition()
{
	return mRootTranslation->getTranslation();
}

void Ishavsfiske::School::setPosition(float x, float y)
{
	mRootTranslation->setTranslation(sf::Vector2f(x, y));
}

int Ishavsfiske::School::fish(int ammount)
{
	if(ammount <= mAmmount)
	{
		mAmmount -= ammount;
		return ammount;
	}
	else
	{
		ammount = mAmmount;
		mAmmount = 0;
		return ammount;
	}
}

void Ishavsfiske::School::update(Angler::Game *context, float time, float deltaTime, bool changed)
{
	mChanged |= changed;

	mUpdateChildren(context, time, deltaTime);
}