//Version: 0.1.5
//Author: Jakob Pipping
//Contributors:

#ifndef INC_HARBOURMODE_H
#define INC_HARBOURMODE_H

#ifdef ISHAV_0_1_5

#include <Angler\Game.h>
#include <Angler\Node.h>
#include <Angler\Translation.h>

#include "MsgBox.h"

namespace Ishavsfiske
{
	class HarbourMode
		: public Angler::Node
	{
	public:
		HarbourMode(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner);
		HarbourMode(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner);

		void draw(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime);
		void endDraw(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime);
		void update(Angler::Game* context, float time, float deltaTime, bool changed = false);

		void init();
		void loadContent();

	protected:
		void mEnable(bool enabled);

	private:
		void mShowRoom(int ind);

		void mUpdateHarbourMode(Angler::Game* context, float time, float deltaTime);
		void mUpdateRoom(Angler::Game* context, float time, float deltaTime);

		void mDrawHarbourRoom(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime);
		void mDrawRoom(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime);

		void mDrawTrade(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime);

		int mRoom;

		int mRadioCh;

		Font *mFont;

		sf::Texture *mTXBarHO, *mTXWorkshopHO, *mTXMarketHO, *mTXUI, *mTXBackButton, *mTXCursor, *mTXButton, *mTXFont;
		std::vector<sf::Vector2f> mBarMOS, mWorkshopMOS, mMarketMOS, mMenuButtonMOS, mRadioMOS, mBackButtonMOS,
			mSellButtonMOS;
		bool mBarIsMO, mWorkshopIsMO, mMarketIsMO, mMenuButtonIsMO, mRadioIsMO, mBackButtonIsMO, mSellButtonIsMO;
		bool mOldBarIsMO, mOldWorkshopIsMO, mOldMarketIsMO, mOldMenuButtonIsMO, mOldRadioIsMO, mOldBackButtonIsMO, mOldSellButtonIsMO;
		float mMenuButtonRot;

		float mRadioTime;

		sf::Texture *mTXHarbour;
		sf::Texture 
			*mTXBarInside, *mTXBarInsideHO, 
			*mTXWorkshopInside, *mTXWorkshopInsideHO,
			*mTXMarketInside, *mTXMarketInsideHO;

		std::vector<sf::Vector2f> mInsideMOS;
		bool mInsideIsMO;

		bool mTrading;

		sf::Sound *mClick;
		sf::SoundBuffer *mClickBuffer;

		sf::Sound *mRadioSound;
		sf::SoundBuffer *mRadioBuffer;
		sf::Sound *mMusic[5];
		sf::SoundBuffer *mMusicBuffer[5];

		sf::Sound *mSHarbour, *mSBar, *mSBarO, *mSWorkshop, *mSWorkshopO, *mSMarket, *mSMarketO;
		sf::SoundBuffer *mSBHarbour, *mSBBar, *mSBBarO, *mSBWorkshop, *mSBWorkshopO, *mSBMarket, *mSBMarketO;

		Ishavsfiske::IshavsfiskeGame *mOwner;
	};
}

#else
#error HarbourMode.h: Wrong version 0.1.5
#endif

#endif