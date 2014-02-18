//Version: 0.1.4
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_4
#error IshavsfiskeGame_init.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"

#include <SFML\Audio.hpp>

#include <Angler\DrawNode.h>
#include <Angler\SpriteNode.h>
#include <Angler\Scale.h>

#include "Ship.h"
#include "FishingBoat.h"
#include "IceBreaker.h"

#include "Font.h"

void Ishavsfiske::IshavsfiskeGame::mLoadContent()
{
	mTXShips->loadFromFile("boat_icebreaker_1.png");
	mTXMap->loadFromFile("env_sea1.png");
	mTXUI->loadFromFile("ui_background1.png");
	mUIFont->loadFromFile("font_bitmap.png");

	mCollFishingBuff->loadFromFile("Fiskebåt_Kollision_01.wav");
	mCollFishingSound->setBuffer(*mCollFishingBuff);

	mCollBreakerBuff->loadFromFile("Isbrytare_Kollision_01.wav");
	mCollBreakerSound->setBuffer(*mCollBreakerBuff);

	mCollIceBuff->loadFromFile("Ice_FirstCollision.wav");
	mCollIceSound->setBuffer(*mCollIceBuff);

	mEngineBuff->loadFromFile("Motor_Collage_Test.wav");
	mEngineSound->setBuffer(*mEngineBuff);
	
	mSound->playSound(mEngineSound, false, 0, 1.0f, true);

	mGraphics->getLayer(0)->setTexture(mTXMap);
	mGraphics->getLayer(1)->setTexture(mTXShips);
	mGraphics->getLayer(2)->setTexture(mTXShips);
	mGraphics->getLayer(3)->setTexture(mTXUI);
	mGraphics->getLayer(4)->setTexture(mUIFont);
}

void Ishavsfiske::IshavsfiskeGame::mInit()
{
	mTXMap = new sf::Texture();
	mTXShips = new sf::Texture();
	mTXUI = new sf::Texture();
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
	leftBox.push_back(sf::Vector2f(2/10.0f, 0));
	leftBox.push_back(sf::Vector2f(1/10.0f, 0));
	leftBox.push_back(sf::Vector2f(1/10.0f, 1));
	leftBox.push_back(sf::Vector2f(2/10.0f, 1));
	new Angler::Nodes::CollisionNode(0x100000, mSceneRoot, leftBox, 1);

	std::vector<sf::Vector2f> rightBox;
	rightBox.push_back(sf::Vector2f(15/10.0f, 0));
	rightBox.push_back(sf::Vector2f(14/10.0f, 0));
	rightBox.push_back(sf::Vector2f(14/10.0f, 1));
	rightBox.push_back(sf::Vector2f(15/10.0f, 1));
	new Angler::Nodes::CollisionNode(0x100001, mSceneRoot, rightBox, 1);

	std::vector<sf::Vector2f> topBox;
	topBox.push_back(sf::Vector2f(15/10.0f, -1/10.0f));
	topBox.push_back(sf::Vector2f(1/10.0f, -1/10.0f));
	topBox.push_back(sf::Vector2f(1/10.0f, 0));
	topBox.push_back(sf::Vector2f(15/10.0f, 0));
	new Angler::Nodes::CollisionNode(0x100002, mSceneRoot, topBox, 1);

	std::vector<sf::Vector2f> bottomBox;
	bottomBox.push_back(sf::Vector2f(15/10.0f, 1));
	bottomBox.push_back(sf::Vector2f(1/10.0f, 1));
	bottomBox.push_back(sf::Vector2f(1/10.0f, 11/10.0f));
	bottomBox.push_back(sf::Vector2f(15/10.0f, 11/10.0f));
	new Angler::Nodes::CollisionNode(0x100003, mSceneRoot, bottomBox, 1);

	mFont = new Font();

	/*mFrame = new std::vector<sf::Vector2f>();
	mFrame->push_back(sf::Vector2f(14/10.0, 0));
	mFrame->push_back(sf::Vector2f(2/10.0, 0));
	mFrame->push_back(sf::Vector2f(2/10.0, 1));
	mFrame->push_back(sf::Vector2f(14/10.0, 1));*/
}