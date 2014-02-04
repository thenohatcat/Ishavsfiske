//Version: 0.1.2
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_2
#error Main.cpp: Wrong version 0.1.2
#endif

#include "IshavsfiskeGame.h"

int main()
{
	Ishavsfiske::IshavsfiskeGame g;
	g.init();
	g.loadContent();
	g.run();

	return 0;
}