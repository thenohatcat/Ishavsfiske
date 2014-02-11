//Version: 0.1.3
//Author: Jakob Pipping
//Contributors:

#ifndef INC_SHIP_H
#define INC_SHIP_H

#ifdef ISHAV_0_1_3

#include <Angler\Node.h>
#include <Angler\Translation.h>
#include <Angler\Rotation.h>
#include <Angler\CollisionNode.h>

namespace Ishavsfiske
{
	class IshavsfiskeGame;

	class Ship
		: public Angler::Node
	{
	public:
		Ship(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner);
		Ship(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner);

		void move(float x, float y);
		void rotate(float r);

		void throttle(float vx, float vy);

		void update(Angler::Game *context, float time, float deltaTime);

		void revert();
	protected:
		Angler::Game *mOwner;

		virtual void mInit();

		float mStartX, mStartY;

		Angler::Node *mShipRoot;
	private:
		Angler::Nodes::Translation *mRootTranslation;
		Angler::Nodes::Rotation *mRootRotation;

		sf::Vector2f mVel;

		float mLR;
		sf::Vector2f mLT;
	};
}

#else
#error Ship.h: Wrong version 0.1.3
#endif

#endif