//Version: 0.1.2
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_2
#error IshavsfiskeGame_init.cpp: Wrong version 0.1.2
#endif

#include "IshavsfiskeGame.h"

#include "Ship.h"
#include "Wreck.h"

void Ishavsfiske::IshavsfiskeGame::mLoadContent()
{
	mTXShip->loadFromFile("boat_fishing_1.png");
	mTXWreck->loadFromFile("boat_icebreaker_1.png");
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
}

void Ishavsfiske::IshavsfiskeGame::mInit()
{
	mTXShip = new sf::Texture();
	mTXWreck = new sf::Texture();
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

	mShip = new Ship(0x10000, new Angler::Node(0, mSceneRoot), mTXShip, mTXCrane, this);
	mWreck = new Wreck(0, new Angler::Node(0, mSceneRoot), mTXWreck);
}