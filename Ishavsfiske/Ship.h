//Version: 0.1.1
//Author: Jakob Pipping
//Contributors:

#ifndef INC_SHIP_H
#define INC_SHIP_H

#ifdef ISHAV_0_1_1

#include <Angler\Node.h>
#include "IshavsfiskeGame.h"
#include <Angler\Translation.h>
#include <Angler\Rotation.h>

namespace Ishavsfiske
{
	class Ship
		: public Angler::Node
	{
	public:
		Ship(unsigned long id, Angler::Node *parent, sf::Texture *tx, Ishavsfiske::IshavsfiskeGame *owner);
		Ship(unsigned long id, sf::Texture *tx, Ishavsfiske::IshavsfiskeGame *owner);

		void move(float x, float y);
		void rotate(float r);

		void update(Angler::Game *context, float time, float deltaTime);
	private:
		sf::Texture *mTX;
		Ishavsfiske::IshavsfiskeGame *mOwner;
		Angler::Nodes::Translation *mTransl;
		Angler::Nodes::Rotation *mRotation, *mRotationA, *mRotationB;
	};
}

#else
#error Ishavsfiske.h: Wrong version 0.1.1
#endif

#endif