//Version: 0.1.4
//Author: Marcus Persson
//Contributors:

#ifndef INC_Perch_H
#define INC_Perch_H

#include "School.h"

namespace Ishavsfiske
{
	class Perch
		: public School
	{
	public:
		Perch(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner);
		Perch(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner);

		virtual ~Perch();

		void update(Angler::Game *context, float time, float deltaTime, bool changed);
	protected:
		virtual void mInit();
	};
}

#endif