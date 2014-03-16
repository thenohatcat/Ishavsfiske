//Version: 0.1.5
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_5
#error Main.cpp: Wrong version 0.1.5
#endif

#include "IshavsfiskeGame.h"

#include <SFML\Audio.hpp>
#include <Angler\Sound.h>

#include <iostream>

int main()
{
	Ishavsfiske::IshavsfiskeGame g;
	g.init();
	g.loadContent();
	g.run();

	return 0;
}