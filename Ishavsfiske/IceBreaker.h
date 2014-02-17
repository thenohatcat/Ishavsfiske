//Version: 0.1.3
//Author: Jakob Pipping
//Contributors:

#ifndef INC_ICEBREAKER_H
#define INC_ICEBREAKER_H

#ifdef ISHAV_0_1_3

#include "Ship.h"

namespace Ishavsfiske
{
	class IceBreaker
		: public Ship
	{
	public:
		IceBreaker(unsigned long id, Angler::Node *parent,
			Ishavsfiske::IshavsfiskeGame *owner);
		IceBreaker(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner);

		void update(Angler::Game *context, float time, float deltaTime, bool changed);

	protected:
		virtual void mInit();
	private:
	};
}

#else
#error IceBreaker.h: Wrong version 0.1.3
#endif

#endif