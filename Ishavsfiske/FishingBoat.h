//Version: 0.1.5
//Author: Jakob Pipping
//Contributors:

#ifndef INC_FISHINGBOAT_H
#define INC_FISHINGBOAT_H

#ifdef ISHAV_0_1_5

#include "Ship.h"
#include "School.h"

#include <Angler\AnimatedNode.h>

namespace Ishavsfiske
{
	class FishingBoat
		: public Ship
	{
	public:
		FishingBoat(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner);
		FishingBoat(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner);

		virtual ~FishingBoat();

		void update(Angler::Game *context, float time, float deltaTime, bool changed);

		void setFishing(int, School*);

		void setRepair(int);

		bool getRepairing();

		int *getAmmount();

		sf::Vector2f getLampPos();

	protected:
		virtual void mInit();
	private:
		Angler::Nodes::Rotation *mCraneRotation, *mLampRotation;
		School *mSchool;
		int mAmmount[4];
		bool mFishing;
		float mFishTime;
		bool mRepairing;
		float mRepairTime;

		Angler::Nodes::AnimatedNode *mLeftNet, *mRightNet;
	};
}

#else
#error FishingBoat.h: Wrong version 0.1.5
#endif

#endif