//Version: 0.1.3
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_3
#error IshavsfiskeGame_init.cpp: Wrong version 0.1.3
#endif

#include "IshavsfiskeGame.h"

#include <SFML\Audio.hpp>

#include "Ship.h"
#include "FishingBoat.h"
#include "IceBreaker.h"
#include "Wreck.h"

void Ishavsfiske::IshavsfiskeGame::mLoadContent()
{
	mTXFishing->loadFromFile("boat_fishing_1.png");
	mTXBreaker->loadFromFile("boat_icebreaker_1.png");
	mTXCrane->loadFromFile("boat_fishing_crane_1.png");
	mTXSea->loadFromFile("env_sea1.png");
	mUIbackground1->loadFromFile("ui_background1.png");
	mUIbackground2->loadFromFile("ui_background2.png");
	mUIFishCount->loadFromFile("ui_counter_fish1.png");
	mUITimeCount->loadFromFile("ui_counter_time1.png");
	mUIMoneyCount->loadFromFile("ui_counter_money1.png");
	mUIMenuButton->loadFromFile("ui_button_mainmenu_1.png");
	mUIWindFlag->loadFromFile("ui_windflag1.png");
	mUIStatusBar->loadFromFile("ui_statusbar_1.png");
	mUIUpgrade->loadFromFile("ui_upgrade1.png");

	//mCollShipBuff->loadFromFile("");
	//mCollShipSound->setBuffer(*mCollShipBuff);
}

void Ishavsfiske::IshavsfiskeGame::mInit()
{
	mTXFishing = new sf::Texture();
	mTXBreaker = new sf::Texture();
	mTXCrane = new sf::Texture();
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

	//mCollShipSound = new sf::Sound();
	//mCollShipBuff = new sf::SoundBuffer();

	mShipFishing = new FishingBoat(0x10000, mSceneRoot, mTXFishing, mTXCrane, this);
	mShipBreaker = new IceBreaker(0x20000, mSceneRoot, mTXBreaker, this);

	/*Angler::Nodes::Translation *t1 = new Angler::Nodes::Translation(0, mSceneRoot, 0.5, 0.15);
	Angler::Nodes::Rotation *r1 = new Angler::Nodes::Rotation(0, t1, 45);
	mWreck1 = new Wreck(0x20000, r1, mTXWreck);

	Angler::Nodes::Translation *t2 = new Angler::Nodes::Translation(0, mSceneRoot, 0.7, 0.5);
	Angler::Nodes::Rotation *r2 = new Angler::Nodes::Rotation(0, t2, 90);
	mWreck2 = new Wreck(0x30000, r2, mTXWreck);

	Angler::Nodes::Translation *t3 = new Angler::Nodes::Translation(0, mSceneRoot, 0.3, 0.7);
	Angler::Nodes::Rotation *r3 = new Angler::Nodes::Rotation(0, t3, 0);
	mWreck3 = new Wreck(0x40000, r3, mTXWreck);*/

	//Map Collisions

	std::vector<sf::Vector2f> leftBox;
	leftBox.push_back(sf::Vector2f(2/10.0, 0.001));
	leftBox.push_back(sf::Vector2f(1/10.0, 0.001));
	leftBox.push_back(sf::Vector2f(1/10.0, 9.999));
	leftBox.push_back(sf::Vector2f(2/10.0, 9.999));
	new Angler::Nodes::CollisionNode(0x100000, mSceneRoot, leftBox);

	std::vector<sf::Vector2f> rightBox;
	rightBox.push_back(sf::Vector2f(15/10.0, 0.001));
	rightBox.push_back(sf::Vector2f(14/10.0, 0.001));
	rightBox.push_back(sf::Vector2f(14/10.0, 9.999));
	rightBox.push_back(sf::Vector2f(15/10.0, 9.999));
	new Angler::Nodes::CollisionNode(0x100001, mSceneRoot, rightBox);

	std::vector<sf::Vector2f> topBox;
	topBox.push_back(sf::Vector2f(15/10.0, -1/10.0));
	topBox.push_back(sf::Vector2f(1/10.0, -1/10.0));
	topBox.push_back(sf::Vector2f(1/10.0, 0));
	topBox.push_back(sf::Vector2f(15/10.0, 0));
	new Angler::Nodes::CollisionNode(0x100002, mSceneRoot, topBox);

	std::vector<sf::Vector2f> bottomBox;
	bottomBox.push_back(sf::Vector2f(15/10.0, 1));
	bottomBox.push_back(sf::Vector2f(1/10.0, 1));
	bottomBox.push_back(sf::Vector2f(1/10.0, 11/10.0));
	bottomBox.push_back(sf::Vector2f(15/10.0, 11/10.0));
	new Angler::Nodes::CollisionNode(0x100003, mSceneRoot, bottomBox);

	/*mFrame = new std::vector<sf::Vector2f>();
	mFrame->push_back(sf::Vector2f(14/10.0, 0));
	mFrame->push_back(sf::Vector2f(2/10.0, 0));
	mFrame->push_back(sf::Vector2f(2/10.0, 1));
	mFrame->push_back(sf::Vector2f(14/10.0, 1));*/
}