//Version: 0.1.3
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_3
#error IshavsfiskeGame_init.cpp: Wrong version 0.1.3
#endif

#include "IshavsfiskeGame.h"

#include <SFML\Audio.hpp>

#include <Angler\DrawNode.h>
#include <Angler\SpriteNode.h>
#include <Angler\Scale.h>

#include "Ship.h"
#include "FishingBoat.h"
#include "IceBreaker.h"
#include "Wreck.h"

#include "Font.h"

void Ishavsfiske::IshavsfiskeGame::mLoadContent()
{
	mTXFishing->loadFromFile("boat_fishing_1.png");
	mTXBreaker->loadFromFile("boat_icebreaker_1.png");
	mTXCrane->loadFromFile("boat_fishing_crane_1.png");
	mTXLamp->loadFromFile("boat_fishing_light_1.png");
	mTXSea->loadFromFile("env_sea1.png");
	mUIbackground1->loadFromFile("ui_background1.png");
	mUIbackground2->loadFromFile("ui_background2.png");
	mUIFishCount->loadFromFile("ui_counter_fish1.png");
	mUITimeCount->loadFromFile("ui_counter_time1.png");
	mUIMoneyCount->loadFromFile("ui_counter_money1.png");
	mUIMenuButton->loadFromFile("ui_button_mainmenu_1.png");
	mUIWindFlag->loadFromFile("ui_windflag1.png");
	mUIStatusBar->loadFromFile("ui_statusbar_1.png");
	mUIUpgrade->loadFromFile("ui_upgradetemplate.png");
	mUIFont->loadFromFile("font_bitmap.png");

	mCollFishingBuff->loadFromFile("Fiskeb�t_Kollision_01.wav");
	mCollFishingSound->setBuffer(*mCollFishingBuff);

	mCollBreakerBuff->loadFromFile("Isbrytare_Kollision_01.wav");
	mCollBreakerSound->setBuffer(*mCollBreakerBuff);

	mCollIceBuff->loadFromFile("Ice_FirstCollision.wav");
	mCollIceSound->setBuffer(*mCollIceBuff);

	mEngineBuff->loadFromFile("Motor_Collage_Test.wav");
	mEngineSound->setBuffer(*mEngineBuff);
	mEngineSound->setLoop(true);
	mEngineSound->play();

	mGraphics->getLayer(0)->setTexture(mTXSea);
	mGraphics->getLayer(1)->setTexture(mTXBreaker);
	mGraphics->getLayer(2)->setTexture(mTXCrane);
	mGraphics->getLayer(3)->setTexture(mUIbackground1);
	mGraphics->getLayer(4)->setTexture(mUIFont);
}

void Ishavsfiske::IshavsfiskeGame::mInit()
{
	mTXFishing = new sf::Texture();
	mTXBreaker = new sf::Texture();
	mTXCrane = new sf::Texture();
	mTXLamp = new sf::Texture();
	mTXSea = new sf::Texture();
	mUIbackground1 = new sf::Texture();
	mUIbackground2 = new sf::Texture();
	mUIFishCount = new sf::Texture();
	mUITimeCount = new sf::Texture();
	mUIMoneyCount = new sf::Texture();
	mUIMenuButton = new sf::Texture();
	mUIWindFlag = new sf::Texture();
	mUIStatusBar = new sf::Texture();
	mUIUpgrade = new sf::Texture();
	mUIFont = new sf::Texture();

	mCollBreakerSound = new sf::Sound();
	mCollBreakerBuff = new sf::SoundBuffer();

	mCollFishingSound = new sf::Sound();
	mCollFishingBuff = new sf::SoundBuffer();

	mCollIceSound = new sf::Sound();
	mCollIceBuff = new sf::SoundBuffer();

	mEngineSound = new sf::Sound();
	mEngineBuff = new sf::SoundBuffer();

	mGraphics->addLayer(512);
	mGraphics->addLayer(128);
	mGraphics->addLayer(128);
	mGraphics->addLayer(64);
	mGraphics->addLayer(512);

	mShipFishing = new FishingBoat(0x10000, mSceneRoot, this);
	mShipBreaker = new IceBreaker(0x20000, mSceneRoot, this);

	//Map Collisions
	std::vector<sf::Vector2f> leftBox;
	leftBox.push_back(sf::Vector2f(2/10.0, 0));
	leftBox.push_back(sf::Vector2f(1/10.0, 0));
	leftBox.push_back(sf::Vector2f(1/10.0, 1));
	leftBox.push_back(sf::Vector2f(2/10.0, 1));
	new Angler::Nodes::CollisionNode(0x100000, mSceneRoot, leftBox, 1);

	std::vector<sf::Vector2f> rightBox;
	rightBox.push_back(sf::Vector2f(15/10.0, 0));
	rightBox.push_back(sf::Vector2f(14/10.0, 0));
	rightBox.push_back(sf::Vector2f(14/10.0, 1));
	rightBox.push_back(sf::Vector2f(15/10.0, 1));
	new Angler::Nodes::CollisionNode(0x100001, mSceneRoot, rightBox, 1);

	std::vector<sf::Vector2f> topBox;
	topBox.push_back(sf::Vector2f(15/10.0, -1/10.0));
	topBox.push_back(sf::Vector2f(1/10.0, -1/10.0));
	topBox.push_back(sf::Vector2f(1/10.0, 0));
	topBox.push_back(sf::Vector2f(15/10.0, 0));
	new Angler::Nodes::CollisionNode(0x100002, mSceneRoot, topBox, 1);

	std::vector<sf::Vector2f> bottomBox;
	bottomBox.push_back(sf::Vector2f(15/10.0, 1));
	bottomBox.push_back(sf::Vector2f(1/10.0, 1));
	bottomBox.push_back(sf::Vector2f(1/10.0, 11/10.0));
	bottomBox.push_back(sf::Vector2f(15/10.0, 11/10.0));
	new Angler::Nodes::CollisionNode(0x100003, mSceneRoot, bottomBox, 1);

	mFont = new Font();

	/*mFrame = new std::vector<sf::Vector2f>();
	mFrame->push_back(sf::Vector2f(14/10.0, 0));
	mFrame->push_back(sf::Vector2f(2/10.0, 0));
	mFrame->push_back(sf::Vector2f(2/10.0, 1));
	mFrame->push_back(sf::Vector2f(14/10.0, 1));*/
}