//Version: 0.1.4
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_4
#error Main.cpp: Wrong version 0.1.4
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