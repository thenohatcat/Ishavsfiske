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

#include "Map.h"

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

		sf::Texture *mTXShips;

		sf::Texture *mTXMap;

		sf::Texture *mTXUI;
		sf::Texture *mUIFont;

		Ship *mShipFishing, *mShipBreaker;
		
		sf::Sound *mCollFishingSound, *mCollBreakerSound, *mCollIceSound, *mEngineSound;
		sf::SoundBuffer *mCollFishingBuff, *mCollBreakerBuff, *mCollIceBuff, *mEngineBuff;

		Map *mMap;

		Font *mFont;
	};
}

#else
#error IshavsfiskeGame.h: Wrong version 0.1.4
#endif

#endif