//Version: 0.1.5
//Author: Sihao Li
//Contributors:

#ifndef INC_SEAGULL_H
#define INC_SEAGULL_H

#ifdef ISHAV_0_1_5


#include "Animal.h"

namespace Ishavsfiske
{
	class Seagull
		: public Animal
	{
	public:
		Seagull(unsigned long id, Angler::Node *parent, Angler::Game *owner);
		Seagull(unsigned long id, Angler::Game *owner);

		virtual ~Seagull();

		void update(Angler::Game* context, float time, float deltaTime, bool changed);

		virtual void attack();
	protected:
		virtual void mInit();
	private:
	};
}

#else
#error Seagull.h: Wrong version 0.1.5
#endif

#endif