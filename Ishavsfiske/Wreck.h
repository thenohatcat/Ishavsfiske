//Version: 0.1.2
//Author: Jakob Pipping
//Contributors:

#ifndef INC_WRECK_H
#define INC_WRECK_H

#ifdef ISHAV_0_1_2

#include <Angler\Node.h>

namespace Ishavsfiske
{
	class Wreck
		: public Angler::Node
	{
	public:
		Wreck(unsigned long id, Node *parent, sf::Texture *tx);
		Wreck(unsigned long id, sf::Texture *tx);

	private:
		sf::Texture *mTX;

		void mInit();
	};
}

#else
#error Wreck.h: Wrong version 0.1.2
#endif

#endif