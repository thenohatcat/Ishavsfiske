//Version: 0.1.4
//Author: Jakob Pipping
//Contributors:

#ifndef INC_ISHAVSFISKEGAME_H
#define INC_ISHAVSFISKEGAME_H

#ifdef ISHAV_0_1_4

#include <SFML\Audio.hpp>

#include <Angler\Game.h>
#include <Angler\Node.h>
#include <Angler\CollisionNode.h>
#include <Angler\Mechanics.h>
#include <Angler\Sound.h>
#include <Angler\SpriteNode.h>

class Font;

namespace Ishavsfiske
{
	class Ship;

	class Wreck;

	class IshavsfiskeGame
		: public Angler::Game
	{
	public:
		IshavsfiskeGame();
		~IshavsfiskeGame();

		void collide(Angler::Node *nodeA, Angler::Node *nodeB);

		void throwEvent(int type, ... );

	protected:
		virtual void mDraw(float time, float deltaTime);
		virtual void mUpdate(float time, float deltaTime);

		virtual void mLoadContent();

		virtual void mInit();
	private:
		void mInput(float time, float deltaTime);

		void mDrawUI(float time, float deltaTime);

		Angler::Mechanics::MechanicsEngine *mMechanics;
		Angler::Sound::SoundEngine *mSound;

		sf::Texture *mTXBreaker, *mTXFishing, *mTXCrane, *mTXLamp;

		sf::Texture *mTXSea;

		sf::Texture *mUIbackground1, *mUIbackground2, *mUIFishCount, *mUIMoneyCount, *mUITimeCount;
		sf::Texture *mUIMenuButton, *mUIWindFlag, *mUIStatusBar, *mUIUpgrade, *mUIFont;

		Ship *mShipFishing, *mShipBreaker;
		
		sf::Sound *mCollFishingSound, *mCollBreakerSound, *mCollIceSound, *mEngineSound;
		sf::SoundBuffer *mCollFishingBuff, *mCollBreakerBuff, *mCollIceBuff, *mEngineBuff;

		Angler::Nodes::SpriteNode *mTiles[24*20];

		Font *mFont;
	};
}

#else
#error IshavsfiskeGame.h: Wrong version 0.1.4
#endif

#endif