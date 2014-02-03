//Version: 0.1.0
//Author: Jakob Pipping
//Contributors:

#ifndef INC_ISHAVSFISKEGAME_H
#define INC_ISHAVSFISKEGAME_H

#ifdef ISHAV_0_1_0

#include <Angler\Game.h>
#include <Angler\Node.h>

namespace Ishavsfiske
{
	class Ship;

	class IshavsfiskeGame
		: public Angler::Game
	{
	public:
		IshavsfiskeGame();

		void collide(Angler::Node *nodeA, Angler::Node *nodeB);

	protected:
		virtual void mDraw(float time, float deltaTime);
		virtual void mUpdate(float time, float deltaTime);

		virtual void mLoadContent();

		virtual void mInit();
	private:
		void input(float time, float deltaTime);

		sf::Texture *tx;

		Ship *mShip;
	};
}

#else
#error Ishavsfiske.h: Wrong version 0.1.0
#endif

#endif