//Version: 0.1.5
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_5
#error FishingMode_init.cpp: Wrong version 0.1.5
#endif

#include "FishingMode.h"

#include "IshavsfiskeGame.h"

#include <SFML\Audio.hpp>

#include <Angler\DrawNode.h>
#include <Angler\SpriteNode.h>
#include <Angler\Scale.h>

#include "Ship.h"
#include "FishingBoat.h"
#include "IceBreaker.h"
#include "Map.h"

#include "School.h"
#include "Font.h"

using namespace Ishavsfiske;

void FishingMode::loadContent()
{
	mTXMap->loadFromFile("env_sea1.png");

	mTXSchool->loadFromFile("Sea_Layer.png");
	mTXUI->loadFromFile("Sheet_1.png");
	mUIFont->loadFromFile("font.png");

	mTXGameOver->loadFromFile("game_over__.png");	
	mTXSeagull->loadFromFile("FlyGull_animation_spritesheet.png");
	mTXBackButton->loadFromFile("knappsheet.png");
	mTXCursor->loadFromFile("cursor_hand_sheet.png");
	mTXSeaLayer->loadFromFile("Sea_Layer.png");

	mCollFishingBuff->loadFromFile("Fishingboat_Vs_Boat_01.ogg");
	mCollFishingSound->setBuffer(*mCollFishingBuff);

	mCollBreakerBuff->loadFromFile("Icebreaker_Vs_Boat_01.ogg");
	mCollBreakerSound->setBuffer(*mCollBreakerBuff);

	mCollIceBuff->loadFromFile("Ice_backup.ogg");
	mCollIceSound->setBuffer(*mCollIceBuff);

	mFishingBuff->loadFromFile("Fishingboat_fishing.ogg");
	mFishing->setBuffer(*mFishingBuff);

	mRepairBuff->loadFromFile("Repair.ogg");
	mRepair->setBuffer(*mRepairBuff);

	mBreakerEngineBuff->loadFromFile("Motor_icebreaker.ogg");
	mBreakerEngineSound->setBuffer(*mBreakerEngineBuff);
	
	mSeaAmbientBuff->loadFromFile("Hav.ogg");
	mSeaAmbient->setBuffer(*mSeaAmbientBuff);

	mMusicFishingBuff->loadFromFile("Sea_theme.ogg");

	mMusic->setBuffer(*mMusicFishingBuff);

	//Menu button
	for (int i = 0; i < 32; i++)
	{
		mMenuButtonMOS.push_back(sf::Vector2f(11/40.0f + 3/40.0f * cos(-i/16.0f * 3.1415f), 37/40.0f + 3/40.0f * sin(-i/16.0f * 3.1415f)));
	}

	//Back button
	for (int i = 0; i < 32; i++)
	{
		mBackButtonMOS.push_back(sf::Vector2f(55/40.0f + 1/40.0f * cos(-i/16.0f * 3.1415f), 39/40.0f + 1/40.0f * sin(-i/16.0f * 3.1415f)));
	}
}

void FishingMode::init()
{
	mCollBreakerSound = new sf::Sound();
	mCollBreakerBuff = new sf::SoundBuffer();

	mCollFishingSound = new sf::Sound();
	mCollFishingBuff = new sf::SoundBuffer();

	mCollIceSound = new sf::Sound();
	mCollIceBuff = new sf::SoundBuffer();

	mFishing = new sf::Sound();
	mFishingBuff = new sf::SoundBuffer();

	mRepair = new sf::Sound();
	mRepairBuff = new sf::SoundBuffer();

	mBreakerEngineSound = new sf::Sound();
	mBreakerEngineBuff = new sf::SoundBuffer();

	mFishingEngineSound = new sf::Sound();
	mFishingEngineBuff = new sf::SoundBuffer();

	mSeaAmbient = new sf::Sound();
	mSeaAmbientBuff = new sf::SoundBuffer();

	mMusicFishingBuff = new sf::SoundBuffer();

	mMusic = new sf::Sound();

	mTXMap = new sf::Texture();
	mTXSchool = new sf::Texture();
	mTXUI = new sf::Texture();
	mUIFont = new sf::Texture();
	mTXGameOver = new sf::Texture();
	mTXSeagull = new sf::Texture();
	mTXBackButton = new sf::Texture();
	mTXCursor = new sf::Texture();
	mTXSeaLayer = new sf::Texture();

	mShipFishing = new FishingBoat(0x10000, this, mOwner);
	mShipBreaker = new IceBreaker(0x20000, this, mOwner);

	/*mSeagull = new Seagull(0x40000000, this, mOwner);*/
	mArne = new Arne(0x60000000, this, mOwner);

	mMap = new Map(0x80000000, this, mOwner);

	mFishBase = new Angler::Nodes::Translation(0, this, 2/10.0f, 0);
	mSeagullBase = new Angler::Nodes::Translation(0, this, 0, 0);

	mFont = new Font();
}

