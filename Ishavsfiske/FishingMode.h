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

	protected:
		void mEnable(bool enabled);

	private:
		sf::Sound *mCollFishingSound, *mCollBreakerSound, *mCollIceSound, *mEngineSound;
		sf::SoundBuffer *mCollFishingBuff, *mCollBreakerBuff, *mCollIceBuff, *mEngineBuff;

		sf::Texture *mTXMap, *mTXUI, *mTXSchool, *mUIFont;

		sf::Sound *mMusic;
		sf::SoundBuffer *mMusicFishingBuff;

		void mMoveFrame(float dx, float dy);

		int mSchoolID;
		std::vector<School*> mSchools;

		Map *mMap;
		
		Ship *mShipFishing, *mShipBreaker;

		Ishavsfiske::IshavsfiskeGame *mOwner;
	};
}
	

#else
#error FishingMode.h: Wrong version 0.1.4
#endif

#endif