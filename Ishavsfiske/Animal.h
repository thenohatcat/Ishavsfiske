//Version: 0.1.5
//Author: Sihao Li
//Contributors:

#ifndef INC_ANIMAL_H
#define INC_ANIMAL_H

#ifdef ISHAV_0_1_5

#include <Angler\Node.h>
#include <Angler\Translation.h>
#include <Angler\Rotation.h>
#include <Angler\CollisionNode.h>

namespace Ishavsfiske
{
	class IshavsfiskeGame;

	class Animal
		: public Angler::Node
	{
	public:
		Animal(unsigned long id, Angler::Node *parent, Angler::Game *owner);
		Animal(unsigned long id, Angler::Game *owner);

		virtual ~Animal();

		void move(float x, float y);
		void rotate(float r);

		virtual void attack();

		void update(Angler::Game *context, float time, float deltaTime, bool changed);

		virtual void collide();
	protected:
		Angler::Game *mOwner;

		virtual void mInit();

		float mStartX, mStartY;
	
		Angler::Node *mAnimalRoot;
	private:
		/*Angler::Nodes::SpriteNode *mBearSprite;*/

		Angler::Nodes::Translation *mRootTranslation;
		Angler::Nodes::Rotation *mRootRotation;

		sf::Vector2f mVel, mShipFishDis, mShipIceBDis;

		sf::Vector2f mFishPos, mIceBPos; // Fishingboat and IceBreaker position
		bool mAtShip(), mLookAtShip();
		float mCalcRotation(float angle);
		float mRotToShip;

		int mDirection(sf::Vector2f position);

		void mSetSpeed(float vx, float vy);

		bool mScared;
	};
}

#else
#error Animal.h: Wrong version 0.1.5
#endif

#endif