//Version: 0.1.3
//Author: Jakob Pipping
//Contributors:

#ifndef INC_FISHINGBOAT_H
#define INC_FISHINGBOAT_H

#ifdef ISHAV_0_1_3

#include "Ship.h"

namespace Ishavsfiske
{
	class FishingBoat
		: public Ship
	{
	public:
		FishingBoat(unsigned long id, Angler::Node *parent,
			sf::Texture *textureShip, sf::Texture *textureCrane, 
			sf::Texture *textureLamp, Ishavsfiske::IshavsfiskeGame *owner);
		FishingBoat(unsigned long id, sf::Texture *textureShip, 
			sf::Texture *textureCrane, sf::Texture *textureLamp, 
			Ishavsfiske::IshavsfiskeGame *owner);

		void update(Angler::Game *context, float time, float deltaTime, bool changed);

	protected:
		virtual void mInit();
	private:
		sf::Texture *mTextureShip, *mTextureCrane, *mTextureLamp;

		Angler::Nodes::Rotation *mCraneRotation, *mLampRotation;
	};
}

#else
#error FishingBoat.h: Wrong version 0.1.3
#endif

#endif