//Version: 0.1.2
//Author: Jakob Pipping
//Contributors:

#ifndef INC_SHIP_H
#define INC_SHIP_H

#ifdef ISHAV_0_1_2

#include <Angler\Node.h>
#include "IshavsfiskeGame.h"
#include <Angler\Translation.h>
#include <Angler\Rotation.h>
#include <Angler\CollisionNode.h>

namespace Ishavsfiske
{
	class Ship
		: public Angler::Node
	{
	public:
		Ship(unsigned long id, Angler::Node *parent, sf::Texture *txShip, sf::Texture *txCrane, Ishavsfiske::IshavsfiskeGame *owner);
		Ship(unsigned long id, sf::Texture *txShip, sf::Texture *txCrane, Ishavsfiske::IshavsfiskeGame *owner);

		void move(float x, float y);
		void rotate(float r);

		void throttle(float vx, float vy);

		void update(Angler::Game *context, float time, float deltaTime);
		Angler::Nodes::CollisionNode getCol();

		void revert();
	private:
		void mInit();

		sf::Texture *mTXShip, *mTXCrane;
		Ishavsfiske::IshavsfiskeGame *mOwner;
		Angler::Nodes::Translation *mTransl;
		Angler::Nodes::Rotation *mRotation, *mRotationA;
		Angler::Nodes::CollisionNode *mCol;

		sf::Vector2f mVel;

		float mLR;
		sf::Vector2f mLT;
	};
}

#else
#error Ship.h: Wrong version 0.1.2
#endif

#endif