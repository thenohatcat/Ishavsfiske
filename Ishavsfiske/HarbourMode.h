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
		void showRoom(int ind);

		sf::Texture *mTXBarHO, *mTXWorkshopHO, *mTXMarketHO, *mTXUI;
		std::vector<sf::Vector2f> mBarMOS, mWorkshopMOS, mMarketMOS, mMenuButtonMOS;
		bool mBarIsMO, mWorkshopIsMO, mMarketIsMO;
		float mMenuButtonRot;

		sf::Texture *mTXHarbour;

		sf::Sound *mSSea, *mSBar, *mSWorkshop, *mSMarket;
		sf::SoundBuffer *mSBSea, *mSBBar, *mSBWorkshop, *mSBMarket;

		Ishavsfiske::IshavsfiskeGame *mOwner;
	};
}

#else
#error HarbourMode.h: Wrong version 0.1.5
#endif

#endif