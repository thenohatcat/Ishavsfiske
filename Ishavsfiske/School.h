//Version: 0.1.5
//Author: Marcus Persson
//Contributors: 

#ifndef INC_SCHOOL_H
#define INC_SCHOOL_H

#ifdef ISHAV_0_1_5

#include <Angler/Node.h>
#include <Angler/Translation.h>
#include <Angler/CollisionNode.h>

namespace Ishavsfiske
{
	class IshavsfiskeGame;

	class School
		: public Angler::Node
	{
	public:
		School(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner);
		School(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner);

		virtual ~School();

		void move(float x, float y);

		sf::Vector2f getPosition();
		void setPosition(float x, float y);

		int fish(int ammount);

		int getAmmount();

		int getType();

		virtual void update(Angler::Game *context, float time, float deltaTime, bool changed);
	protected:
		Angler::Game *mOwner;

		virtual void mInit();

		float mStartX, mStartY;

		bool scaredDistance(sf::Vector2f pos);
		void scaredByBoat(sf::Vector2f shipPos, float deltaTime, bool fast);

		int mType;

		Angler::Node *mSchoolRoot;
	private:
		Angler::Nodes::Translation *mRootTranslation;

		int mAmmount;
	};
}
#else
#error School.h: Wrong version 0.1.5
#endif

#endif