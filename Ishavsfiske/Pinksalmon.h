//Version: 0.1.4
//Author: Marcus Persson
//Contributors:

#ifndef INC_PINKSALMON_H
#define INC_PINKSALMON_H

#include "School.h"

namespace Ishavsfiske
{
	class Pinksalmon
		: public School
	{
	public:
		Pinksalmon(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner);
		Pinksalmon(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner);

		virtual ~Pinksalmon();

		void update(Angler::Game *context, float time, float deltaTime, bool changed);
	protected:
		virtual void mInit();
	};
}

#endif