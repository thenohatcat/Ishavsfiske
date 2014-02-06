//Version: 0.1.2
//Author: Jakob Pipping
//Contributors:

#ifndef INC_ISHAVSFISKEGAME_H
#define INC_ISHAVSFISKEGAME_H

#ifdef ISHAV_0_1_2

#include <Angler\Game.h>
#include <Angler\Node.h>
#include <Angler\CollisionNode.h>

namespace Ishavsfiske
{
	class Ship;

	class Wreck;

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
		void mInput(float time, float deltaTime);

		sf::Texture *mTXShip, *mTXCrane, *mTXWreck;

		sf::Texture *mTXSea;

		sf::Texture *mUIbackground1, *mUIbackground2, *mUIFishCount, *mUIMoneyCount, *mUITimeCount;
		sf::Texture *mUIMenuButton, *mUIWindFlag, *mUIStatusBar, *mUIUpgrade;

		Ship *mShip;
		Wreck *mWreck1, *mWreck2, *mWreck3;

		//Angler::Nodes::CollisionNode *mFrameCol;
		std::vector<sf::Vector2f> *mFrame;
	};
}

#else
#error IshavsfiskeGame.h: Wrong version 0.1.2
#endif

#endif