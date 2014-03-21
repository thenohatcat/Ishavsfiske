//Version: 0.1.5
//Author: Sihao Li
//Contributors:

#ifndef INC_ARNE_H
#define INC_ARNE_H

#ifdef ISHAV_0_1_5


#include "Animal.h"

namespace Ishavsfiske
{
	class IshavsfiskeGame;

	class Arne
		: public Animal
	{
	public:
		Arne(unsigned long id, Angler::Node *parent, Angler::Game *owner);
		Arne(unsigned long id, Angler::Game *owner);

		virtual ~Arne();

		void update(Angler::Game *context, float time, float deltaTime, bool changed);

		virtual void attack();

		virtual void collide();
	protected:
		virtual void mInit();
	private:
		void throttle(float vx, float vy);
		sf::Vector2f mVel, mShipIceBDis;

		sf::Vector2f mIceBPos;
		bool mAtShip(), mLookAtShip();
		float mCalcRotation(float angle);
		float mRotToShip;

		bool mScared;
	};
}

#else
#error Arne.h: Wrong version 0.1.5
#endif

#endif