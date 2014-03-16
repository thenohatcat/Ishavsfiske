//Version: 0.1.4
//Author: Marcus Persson
//Contributors:

#ifndef INC_CAPELIN_H
#define INC_CAPELIN_H

#include "School.h"

namespace Ishavsfiske
{
	class Capelin
		: public School
	{
	public:
		Capelin(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner);
		Capelin(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner);

		virtual ~Capelin();

		void update(Angler::Game *context, float time, float deltaTime, bool changed);
	protected:
		virtual void mInit();
	};
}

#endif