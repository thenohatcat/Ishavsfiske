//Version: 0.1.5
//Author: Jakob Pipping
//Contributors:

#ifndef INC_GAMEOVERSCREEN_H
#define INC_GAMEOVERSCREEN_H

#ifdef ISHAV_0_1_5

#include <Angler\Game.h>
#include <Angler\Node.h>
#include <Angler\Translation.h>

namespace Ishavsfiske
{
	class IshavsfiskeGame;

	class GameOverScreen
		: public Angler::Node
	{
	public:
		GameOverScreen(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner);
		GameOverScreen(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner);

		void input(float time, float deltaTime);

		void loadContent();
		void init();

		void draw(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime);
		void update(Angler::Game* context, float time, float deltaTime, bool changed = false);

	protected:
		void mEnable(bool enabled);

	private:
		Ishavsfiske::IshavsfiskeGame *mOwner;
	};
}

#else
#error StartScreen.h: Wrong version 0.1.5
#endif

#endif