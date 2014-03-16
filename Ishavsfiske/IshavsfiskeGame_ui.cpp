//Version: 0.1.5
//Author: 
//Contributors: 

#ifndef ISHAV_0_1_5
#error IshavsfiskeGame_draw.cpp: Wrong version 0.1.5
#endif

#include "IshavsfiskeGame.h"

#include "Ship.h"
#include "FishingBoat.h"

#include <glm\glm.hpp>

#include <Angler\Node.h>
#include <Angler\Transformation.h>
#include <Angler\HelpFunctions.h>

#include "Font.h"

using namespace Ishavsfiske;

float avd;
unsigned int frmd;
float fps;

void IshavsfiskeGame::mDrawUI(float time, float deltaTime)
{
	float ar = mGraphics->getWidth() / (float)mGraphics->getHeight();

	if (frmd < 50)
	{
		frmd++;
		avd += deltaTime;
	}
	else
	{
		fps = frmd/avd;
		frmd = 0;
		avd = 0;
	}

	//Draw UI
	glPushMatrix();
		char s[32];
		sprintf_s(s, 32, "FPS: %03.0f", fps);
		//mFont->drawString(mGraphics, "Ishavsfiske 0.1.4", 6, 1);
		glTranslatef(0, 1/40.0f, 0);
		//mFont->drawString(mGraphics, std::string(s), 6, 1);
	glPopMatrix();
}