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

#include "School.h"
#include "Font.h"

void Ishavsfiske::IshavsfiskeGame::mLoadContent()
{
	mTXMap->loadFromFile("env_sea1.png");
	mTXSchool->loadFromFile("Swim_Capelin_spritesheet.png");
	mTXUI->loadFromFile("Sheet_2.png");
	mUIFont->loadFromFile("font_bitmap.png");

	mCollFishingBuff->loadFromFile("Fiskebåt_Kollision_01.wav");
	mCollFishingSound->setBuffer(*mCollFishingBuff);

	mCollBreakerBuff->loadFromFile("Isbrytare_Kollision_01.wav");
	mCollBreakerSound->setBuffer(*mCollBreakerBuff);

	mCollIceBuff->loadFromFile("Ice_FirstCollision.wav");
	mCollIceSound->setBuffer(*mCollIceBuff);

	mEngineBuff->loadFromFile("Motor_Collage_Test.wav");
	mEngineSound->setBuffer(*mEngineBuff);
	
	mSound->playSound(mEngineSound, false, 0, 1.46f, true);

	mGraphics->getLayer(0)->setTexture(mTXUI);
	mGraphics->getLayer(1)->setTexture(mTXUI);
	mGraphics->getLayer(2)->setTexture(mTXSchool);
	mGraphics->getLayer(3)->setTexture(mTXUI);
	mGraphics->getLayer(4)->setTexture(mTXUI);
	mGraphics->getLayer(5)->setTexture(mTXUI);
	mGraphics->getLayer(6)->setTexture(mUIFont);
}

void Ishavsfiske::IshavsfiskeGame::mInit()
{
	mTXMap = new sf::Texture();
	mTXSchool = new sf::Texture();
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
	mGraphics->addLayer(512);
	mGraphics->addLayer(32);
	mGraphics->addLayer(64);
	mGraphics->addLayer(64);
	mGraphics->addLayer(64);
	mGraphics->addLayer(512);

	mShipFishing = new FishingBoat(0x10000, mSceneRoot, this);
	mShipBreaker = new IceBreaker(0x20000, mSceneRoot, this);

	mMap = new Map(0x80000000, mSceneRoot, this);

	School *s = new School(0x20000000, mSceneRoot, this);
	s->setPosition(0.7, 0.5);

	//Map Collisions
	std::vector<sf::Vector2f> leftBox;
	leftBox.push_back(sf::Vector2f(2/10.0f, 0));
	leftBox.push_back(sf::Vector2f(1/10.0f, 0));
	leftBox.push_back(sf::Vector2f(1/10.0f, 1));
	leftBox.push_back(sf::Vector2f(2/10.0f, 1));
	new Angler::Nodes::CollisionNode(0x70000000, mSceneRoot, leftBox, 1);

	std::vector<sf::Vector2f> rightBox;
	rightBox.push_back(sf::Vector2f(15/10.0f, 0));
	rightBox.push_back(sf::Vector2f(14/10.0f, 0));
	rightBox.push_back(sf::Vector2f(14/10.0f, 1));
	rightBox.push_back(sf::Vector2f(15/10.0f, 1));
	new Angler::Nodes::CollisionNode(0x70000001, mSceneRoot, rightBox, 1);

	std::vector<sf::Vector2f> topBox;
	topBox.push_back(sf::Vector2f(15/10.0f, -1/10.0f));
	topBox.push_back(sf::Vector2f(1/10.0f, -1/10.0f));
	topBox.push_back(sf::Vector2f(1/10.0f, 0));
	topBox.push_back(sf::Vector2f(15/10.0f, 0));
	new Angler::Nodes::CollisionNode(0x70000002, mSceneRoot, topBox, 1);

	std::vector<sf::Vector2f> bottomBox;
	bottomBox.push_back(sf::Vector2f(15/10.0f, 1));
	bottomBox.push_back(sf::Vector2f(1/10.0f, 1));
	bottomBox.push_back(sf::Vector2f(1/10.0f, 11/10.0f));
	bottomBox.push_back(sf::Vector2f(15/10.0f, 11/10.0f));
	new Angler::Nodes::CollisionNode(0x70000003, mSceneRoot, bottomBox, 1);

	mFont = new Font();
}