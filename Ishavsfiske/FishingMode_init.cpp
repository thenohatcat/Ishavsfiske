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

	mCollFishingBuff->loadFromFile("Fiskebåt_Kollision_01.wav");
	mCollFishingSound->setBuffer(*mCollFishingBuff);

	mCollBreakerBuff->loadFromFile("Isbrytare_Kollision_01.wav");
	mCollBreakerSound->setBuffer(*mCollBreakerBuff);

	mCollIceBuff->loadFromFile("Ice_FirstCollision.wav");
	mCollIceSound->setBuffer(*mCollIceBuff);

	mFishingBuff->loadFromFile("Fishingboat_fishing.ogg");
	mFishing->setBuffer(*mFishingBuff);

	mRepairBuff->loadFromFile("Repair.ogg");
	mRepair->setBuffer(*mRepairBuff);

	mEngineBuff->loadFromFile("Motor_Collage_Test.wav");
	mEngineSound->setBuffer(*mEngineBuff);
	
	mSeaAmbientBuff->loadFromFile("Hav.wav");
	mSeaAmbient->setBuffer(*mSeaAmbientBuff);

	mMusicFishingBuff->loadFromFile("Sea_theme.ogg");

	mMusic->setBuffer(*mMusicFishingBuff);

	//Menu button
	for (int i = 0; i < 32; i++)
	{
		mMenuButtonMOS.push_back(sf::Vector2f(11/40.0f + 3/40.0f * cos(-i/16.0f * 3.1415f), 37/40.0f + 3/40.0f * sin(-i/16.0f * 3.1415f)));
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

	mEngineSound = new sf::Sound();
	mEngineBuff = new sf::SoundBuffer();

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

	mShipFishing = new FishingBoat(0x10000, this, mOwner);
	mShipBreaker = new IceBreaker(0x20000, this, mOwner);

	mSeagull = new Seagull(0x40000000, this, mOwner);

	mMap = new Map(0x80000000, this, mOwner);

	mFishBase = new Angler::Nodes::Translation(0, this, 2/10.0f, 0);

	mFont = new Font();

	//Back button
	for (int i = 0; i < 32; i++)
	{
		mBackButtonMOS.push_back(sf::Vector2f(55/40.0f + 1/40.0f * cos(-i/16.0f * 3.1415f), 39/40.0f + 1/40.0f * sin(-i/16.0f * 3.1415f)));
	}

	////Map Collisions
	//std::vector<sf::Vector2f> leftBox;
	//leftBox.push_back(sf::Vector2f(2/10.0f, 0));
	//leftBox.push_back(sf::Vector2f(1/10.0f, 0));
	//leftBox.push_back(sf::Vector2f(1/10.0f, 1));
	//leftBox.push_back(sf::Vector2f(2/10.0f, 1));
	//new Angler::Nodes::CollisionNode(0x70000000, this, leftBox, 1);

	//std::vector<sf::Vector2f> rightBox;
	//rightBox.push_back(sf::Vector2f(15/10.0f, 0));
	//rightBox.push_back(sf::Vector2f(14/10.0f, 0));
	//rightBox.push_back(sf::Vector2f(14/10.0f, 1));
	//rightBox.push_back(sf::Vector2f(15/10.0f, 1));
	//new Angler::Nodes::CollisionNode(0x70000001, this, rightBox, 1);

	//std::vector<sf::Vector2f> topBox;
	//topBox.push_back(sf::Vector2f(15/10.0f, -1/10.0f));
	//topBox.push_back(sf::Vector2f(1/10.0f, -1/10.0f));
	//topBox.push_back(sf::Vector2f(1/10.0f, 0));
	//topBox.push_back(sf::Vector2f(15/10.0f, 0));
	//new Angler::Nodes::CollisionNode(0x70000002, this, topBox, 1);

	//std::vector<sf::Vector2f> bottomBox;
	//bottomBox.push_back(sf::Vector2f(15/10.0f, 1));
	//bottomBox.push_back(sf::Vector2f(1/10.0f, 1));
	//bottomBox.push_back(sf::Vector2f(1/10.0f, 11/10.0f));
	//bottomBox.push_back(sf::Vector2f(15/10.0f, 11/10.0f));
	//new Angler::Nodes::CollisionNode(0x70000003, this, bottomBox, 1);
}

