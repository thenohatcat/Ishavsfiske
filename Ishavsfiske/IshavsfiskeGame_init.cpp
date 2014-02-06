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

	mShip = new Ship(0x10000, mSceneRoot, mTXShip, mTXCrane, this);

	Angler::Nodes::Translation *t1 = new Angler::Nodes::Translation(0, mSceneRoot, 0.5, 0.15);
	Angler::Nodes::Rotation *r1 = new Angler::Nodes::Rotation(0, t1, 45);
	mWreck1 = new Wreck(0x20000, r1, mTXWreck);

	Angler::Nodes::Translation *t2 = new Angler::Nodes::Translation(0, mSceneRoot, 0.7, 0.5);
	Angler::Nodes::Rotation *r2 = new Angler::Nodes::Rotation(0, t2, 90);
	mWreck2 = new Wreck(0x30000, r2, mTXWreck);

	Angler::Nodes::Translation *t3 = new Angler::Nodes::Translation(0, mSceneRoot, 0.3, 0.7);
	Angler::Nodes::Rotation *r3 = new Angler::Nodes::Rotation(0, t3, 0);
	mWreck3 = new Wreck(0x40000, r3, mTXWreck);

	mFrame = new std::vector<sf::Vector2f>();
	mFrame->push_back(sf::Vector2f(14/10.0, 0));
	mFrame->push_back(sf::Vector2f(2/10.0, 0));
	mFrame->push_back(sf::Vector2f(2/10.0, 1));
	mFrame->push_back(sf::Vector2f(14/10.0, 1));
}