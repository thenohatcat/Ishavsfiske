//Version: 0.1.2
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_2
#error IshavsfiskeGame_draw.cpp: Wrong version 0.1.2
#endif

#include "IshavsfiskeGame.h"

#include <Angler\Node.h>

void Ishavsfiske::IshavsfiskeGame::mDraw(float time, float deltaTime)
{
	mGraphics->begin();
	//Draw UI
	//...

	//Draw SceneRoot
	mSceneRoot->draw(this, mGraphics, time, deltaTime);
	mGraphics->end();
}