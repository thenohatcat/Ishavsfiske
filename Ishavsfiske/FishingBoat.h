//Version: 0.1.4
//Author: Jakob Pipping
//Contributors:

#ifndef INC_FISHINGBOAT_H
#define INC_FISHINGBOAT_H

#ifdef ISHAV_0_1_4

#include "Ship.h"

namespace Ishavsfiske
{
	class FishingBoat
		: public Ship
	{
	public:
		FishingBoat(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner);
		FishingBoat(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner);

		void update(Angler::Game *context, float time, float deltaTime, bool changed);

		void setFishing(int);

	protected:
		virtual void mInit();
	private:
		Angler::Nodes::Rotation *mCraneRotation, *mLampRotation;
	};
}

#else
#error FishingBoat.h: Wrong version 0.1.4
#endif

#endif