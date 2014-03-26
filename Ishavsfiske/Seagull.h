//Version: 0.1.5
//Author: Sihao Li
//Contributors:

#ifndef INC_SEAGULL_H
#define INC_SEAGULL_H

#ifdef ISHAV_0_1_5


#include "Animal.h"

namespace Ishavsfiske
{
	class IshavsfiskeGame;

	class Seagull
		: public Animal
	{
	public:
		Seagull(unsigned long id, Angler::Node *parent, Angler::Game *owner);
		Seagull(unsigned long id, Angler::Game *owner);

		virtual ~Seagull();

		void update(Angler::Game *context, float time, float deltaTime, bool changed);

		virtual void collide();

		void setPosition(float x, float y);

		void revert();
		void getPush();
		bool collided();
		bool isClose();
		void startColTimer();
	protected:
		virtual void mInit();
	private:
		sf::Vector2f mVel, mShipFishDis;

		sf::Vector2f mFishPos;
		bool mAtShip(), mLookAtShip();
		float mCalcRotation(float angle);
		float mRotToShip;
		bool mScared;
		float recoverTime;
		int LR;

		std::vector<float> mOldRotations;
		std::vector<sf::Vector2f> mOldTranslations;

		float mTimeDiff;
		float mColTimeRec;
		float mDTime;
	};
}

#else
#error Seagull.h: Wrong version 0.1.5
#endif

#endif