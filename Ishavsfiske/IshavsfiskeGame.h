//Version: 0.1.5
//Author: Jakob Pipping
//Contributors:

#ifndef INC_ISHAVSFISKEGAME_H
#define INC_ISHAVSFISKEGAME_H

#ifdef ISHAV_0_1_5

#include <SFML\Audio.hpp>

#include <Angler\Game.h>
#include <Angler\Node.h>
#include <Angler\CollisionNode.h>
#include <Angler\Mechanics.h>
#include <Angler\Sound.h>
#include <Angler\SpriteNode.h>

#include "Map.h"
#include "School.h"
#include "FishingMode.h"
#include "StartScreen.h"
#include "GameOverScreen.h"
#include "HarbourMode.h"

class Font;

namespace Ishavsfiske
{
	class Ship;

	class IceBreaker;
	class FishingBoat;
	class Arne;

	class IshavsfiskeGame
		: public Angler::Game
	{
	public:
		IshavsfiskeGame();
		~IshavsfiskeGame();

		void collide(Angler::Node *nodeA, Angler::Node *nodeB);

		void throwEvent(int type, ... );

		void pause(bool paused);
		bool getPaused();

		IceBreaker *getIceBreaker();
		FishingBoat *getShipFishing();
		Arne *getArne(); // Getting Arne

		FishingMode *getFishingMode();

		void clearGraphicsLayers();

		void setupGraphicsLayers(int numLayers, int layerSizes[], sf::Texture *layerTextures[]);

		int *getFishCount();

		int getWallet();

		void addToWallet(int i);

		MsgBox *getMSGBox();

		typedef enum
		{
			Collide = Game::Events::Collide,
			Fishing, Repairing, Breaking,
			StartScreenShow,
			StartScreenHide,
			GameOverScreenShow,
			GameOverScreenHide,
			FishingModeShow,
			FishingModeHide,
			FishingModeDisable,
			FishingModeEnable,
			HarbourModeShow,
			HarbourModeHide,
			HarbourModeDisable,
			HarbourModeEnable
		} Events;

	protected:
		virtual void mDraw(float time, float deltaTime);
		virtual void mUpdate(float time, float deltaTime);

		virtual void mLoadContent();

		virtual void mInit();
	private:
		void mInput(float time, float deltaTime);

		void mDrawUI(float time, float deltaTime);

		int mFishCount[4];

		int mWallet;

		FishingMode *mFishingMode;
		StartScreen *mStartScreen;
		GameOverScreen *mGameOverScreen;
		HarbourMode *mHarbourMode;
		
		Angler::Node *mUIRoot, *mObjectsRoot;

		MsgBox *mMSGBox;

		Font *mFont;
	};
}

#else
#error IshavsfiskeGame.h: Wrong version 0.1.5
#endif

#endif