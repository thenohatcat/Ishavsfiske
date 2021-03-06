//Version: 0.1.4
//Author: Jakob Pipping
//Contributors:

#ifndef INC_FISHINGMODE_H
#define INC_FISHINGMODE_H

#ifdef ISHAV_0_1_4

#include <Angler\Game.h>
#include <Angler\Node.h>
#include <Angler\Translation.h>

#include "IceBreaker.h"
#include "FishingBoat.h"
#include "Map.h"
#include "School.h"

#include "MsgBox.h"

namespace Ishavsfiske
{
	class FishingMode
		: public Angler::Node
	{
	public:
		FishingMode(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner);
		FishingMode(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner);

		void collide(Node *nodeA, Node *nodeB);

		void input(float time, float deltaTime);

		void loadContent();
		void init();

		IceBreaker *getIceBreaker();
		FishingBoat *getShipFishing();

		void draw(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime);
		void update(Angler::Game* context, float time, float deltaTime, bool changed = false);

		void fish(int dir, School* school);

		void repair(int dir);

		void breakIce();

	protected:
		void mEnable(bool enabled);

	private:
		sf::Sound *mCollFishingSound, *mCollBreakerSound, *mCollIceSound, *mEngineSound;
		sf::SoundBuffer *mCollFishingBuff, *mCollBreakerBuff, *mCollIceBuff, *mEngineBuff;

		sf::Texture *mTXMap, *mTXUI, *mTXSchool, *mUIFont, *mTXGameOver;

		sf::Sound *mRepair;
		sf::SoundBuffer *mRepairBuff;

		sf::Sound *mMusic;
		sf::SoundBuffer *mMusicFishingBuff;

		sf::Sound *mSeaAmbient;
		sf::SoundBuffer *mSeaAmbientBuff;

		sf::Sound *mTutorialSound;
		sf::SoundBuffer *mTutorialBuff;

		Angler::Nodes::Translation *mFishBase;

		void mMoveFrame(float fishingDX, float fishingDY, float breakerDX, float breakerDY, bool fishingX, bool fishingY, bool moveMapX, bool moveMapY);

		int mSchoolID;
		std::vector<School*> mSchools;

		Map *mMap;
		
		Ship *mShipFishing, *mShipBreaker;

		Ishavsfiske::IshavsfiskeGame *mOwner;

		void mUpdateTutorial(Angler::Game* context, float time, float deltaTime);

		bool mDoRepair;
		bool mDoFish;

		MsgBox *mMsgBox;

		Font *mFont;

		int mTutorialStage;
		float mTutorialStageTime;

		bool mShowTimer;
		bool mShowCounter;

		bool mCanRepair;
		bool mCanFish;
		bool mMapFrozen;
		bool mSpawnFish;

		bool mRunTimer;
		float mTimer;
	};
}
	

#else
#error FishingMode.h: Wrong version 0.1.4
#endif

#endif