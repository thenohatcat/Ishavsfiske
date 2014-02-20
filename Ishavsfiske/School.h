//Version: 0.1.4
//Author: Marcus Persson
//Contributors: 

#ifndef INC_SCHOOL_H
#define INC_SCHOOL_H

#ifdef ISHAV_0_1_4

#include <Angler/Node.h>
#include <Angler/Translation.h>
#include <Angler/Rotation.h>
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

		void move(float x, float y);
		void getPosition();
		void setPosition(float x, float y);
		int fish(int ammount);
	protected:
		Angler::Game *mOwner;

		virtual void mInit();

		float mStartX, mStartY;

		Angler::Node *mSchoolRoot;
	private:
		Angler::Nodes::Translation *mRootTranslation;
		Angler::Nodes::Rotation *mRootRotation;

		sf::Vector2f mVel;
	};
}
#else
#error Font.h: Wrong version 0.1.4
#endif

#endif