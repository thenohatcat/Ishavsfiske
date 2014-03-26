//Version: 0.1.5
//Author: Jakob Pipping
//Contributors:

#ifndef INC_TUTORIAL_H
#define INC_TUTORIAL_H

#ifdef ISHAV_0_1_5

#include <Angler\Node.h>
#include <SFML\Audio.hpp>

#include "Font.h"

namespace Ishavsfiske
{
	class IshavsfiskeGame;

	class MsgBox;

	class MsgBoxMessage
	{
		friend class MsgBox;
	public:
		MsgBoxMessage(unsigned long id, std::string msg, float time)
			: mID(id), mMSG(msg), mTime(time)
		{ }

	private:
		unsigned long mID;
		std::string mMSG;
		float mTime;
	};

	class MsgBox
		: public Angler::Node
	{
	public:
		MsgBox(unsigned long id, Angler::Node *parent, IshavsfiskeGame *owner);
		MsgBox(unsigned long id, IshavsfiskeGame *owner);

		void update(Angler::Game *context, float time, float deltaTime, bool changed);
		void draw(Angler::Game *context, Angler::Graphics::GraphicsEngine *graphics, float time, float deltaTime);

		void show(std::string text, int bgLayer, int textLayer, float time = 5.0f);
		void show(unsigned long id, int bgLayer, int textLayer);
		void hide();

		void loadContent();

		void addState(unsigned long id, std::string msg, float time);

		void loadStates(std::string file);

		void init();
	private:
		std::string mText;
		float mTime, mCurTime;

		sf::Sound *mSound;
		sf::SoundBuffer *mBuffer;

		IshavsfiskeGame *mOwner;

		int mBGLayer, mTXTLayer;

		std::vector<MsgBoxMessage*> mMessages;
		std::vector<MsgBoxMessage*>::iterator mGetState(unsigned long id);

		Font *mFont;
	};
}

#else
#error IceBreaker.h: Wrong version 0.1.5
#endif

#endif