//Version: 0.1.2
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_2
#error IshavsfiskeGame_rot.cpp: Wrong version 0.1.2
#endif

#include "IshavsfiskeGame.h"

std::vector<Angler::Node*> Ishavsfiske::getChildren(Angler::Node *node)
{
	std::vector<Angler::Node*> nds;

	std::vector<Angler::Node*> nxt;
	nxt.push_back(node);

	Angler::Node *n;
	while (nxt.size() > 0)
	{
		n = nxt.back();
		nxt.pop_back();

		nds.push_back(n);

		//Extremely dirt trick, DON'T use this
		std::vector<Angler::Node*> v = *((std::vector<Angler::Node*>*)((char*)n + 12));
		for (int i = 0; i < v.size(); i++)
		{
			nxt.push_back(v.at(v.size() - 1 - i));
		}
	}

	return nds;
}

Ishavsfiske::IshavsfiskeGame::IshavsfiskeGame()
	: Game()
{
	mTitle = "Ishavsfiske v0.1.2";
	mNumLayers = 8;
	mWidth = 1089;
	mHeight = 687;
}