//Version: 0.1.4
//Author: Jakob Pipping
//Contributors:

#ifndef INC_TUTORIAL_H
#define INC_TUTORIAL_H

#ifdef ISHAV_0_1_4

#include <Angler\Node.h>
#include <SFML\Audio.hpp>

#include "Font.h"

namespace Ishavsfiske
{
	class IshavsfiskeGame;

	class MsgBox
		: public Angler::Node
	{
	public:
		MsgBox(unsigned long id, Angler::Node *parent, IshavsfiskeGame *owner);
		MsgBox(unsigned long id, IshavsfiskeGame *owner);

		void update(Angler::Game *context, float time, float deltaTime, bool changed);
		void draw(Angler::Game *context, Angler::Graphics::GraphicsEngine *graphics, float time, float deltaTime);

		void show(std::string text, float time = 5.0f);
		void hide();

		void loadContent();

		void init();
	private:
		std::string mText;
		float mTime, mCurTime;

		sf::Sound *mSound;
		sf::SoundBuffer *mBuffer;

		IshavsfiskeGame *mOwner;

		Font *mFont;
	};
}

#else
#error IceBreaker.h: Wrong version 0.1.4
#endif

#endif