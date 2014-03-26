//Version: 0.1.5
//Author: Jakob Pipping
//Contributors:

#ifndef INC_SHIP_H
#define INC_SHIP_H

#ifdef ISHAV_0_1_5

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

		virtual ~Ship();

		void move(float x, float y, bool global = false, bool forced = false);
		void rotate(float r);

		void throttle(float vx, float vy);

		void update(Angler::Game *context, float time, float deltaTime, bool changed);

		void revert();

		void setPosition(sf::Vector2f v);
		void setRotation(float r);

		sf::Vector2f getPosition();
		float getRotation();

		sf::Vector2f getVelocity();
		sf::Vector2f getGlobalVelocity();

		virtual void collide();

		void block();
	protected:
		Angler::Game *mOwner;

		virtual void mInit();

		float mStartX, mStartY;

		Angler::Node *mShipRoot;

		Angler::Nodes::Translation *mRootTranslation;
		Angler::Nodes::Rotation *mRootRotation;

		bool mBlocked;
	private:

		sf::Vector2f mVel;

		std::vector<float> mOldRotations;
		std::vector<sf::Vector2f> mOldTranslations;

		float mTimeDiff;
	};
}

#else
#error Ship.h: Wrong version 0.1.5
#endif

#endif