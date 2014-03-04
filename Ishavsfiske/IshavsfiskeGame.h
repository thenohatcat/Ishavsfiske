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
#include "School.h"

class Font;

namespace Ishavsfiske
{
	class Ship;

	class IceBreaker;
	class FishingBoat;

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

	protected:
		virtual void mDraw(float time, float deltaTime);
		virtual void mUpdate(float time, float deltaTime);

		virtual void mLoadContent();

		virtual void mInit();
	private:
		void mInput(float time, float deltaTime);

		void mDrawUI(float time, float deltaTime);

		void mMoveFrame(float dx, float dy);

		sf::Texture *mTXMap;
		sf::Texture *mTXUI;
		sf::Texture *mTXSchool;
		sf::Texture *mUIFont;

		Ship *mShipFishing, *mShipBreaker;
		
		Angler::Node *mUIRoot, *mObjectsRoot;

		int mSchoolID;
		std::vector<School*> mSchools;

		sf::Sound *mCollFishingSound, *mCollBreakerSound, *mCollIceSound, *mEngineSound;
		sf::SoundBuffer *mCollFishingBuff, *mCollBreakerBuff, *mCollIceBuff, *mEngineBuff;
		
		sf::Sound *mMusic;
		sf::SoundBuffer *mMusicFishingBuff;

		Map *mMap;

		Font *mFont;
	};
}

#else
#error IshavsfiskeGame.h: Wrong version 0.1.4
#endif

#endif