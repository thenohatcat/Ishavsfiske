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

		Angler::Nodes::Translation *mRootTranslation;
		Angler::Nodes::Rotation *mRootRotation;

		int mDirection(sf::Vector2f position);

		bool mBlocked;

		std::vector<float> mOldRotations;
		std::vector<sf::Vector2f> mOldTranslations;
		float mTimeDiff;
	private:
	};
}

#else
#error Animal.h: Wrong version 0.1.5
#endif

#endif