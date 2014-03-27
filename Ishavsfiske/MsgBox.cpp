//Version: 0.1.5
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_5
#error Tutorial.cpp: Wrong version 0.1.5
#endif

#include <fstream>
#include <sstream>

#include "MsgBox.h"

#include "IshavsfiskeGame.h"

using namespace Ishavsfiske;

MsgBox::MsgBox(unsigned long id, Angler::Node *parent, IshavsfiskeGame *owner)
	: Node(id, parent), mText(""), mTime(0), mCurTime(0), mOwner(owner), mBGLayer(0), mTXTLayer(0)
{
	
}

MsgBox::MsgBox(unsigned long id, IshavsfiskeGame *owner)
	: Node(id), mText(""), mTime(0), mCurTime(0), mOwner(owner), mBGLayer(0), mTXTLayer(0)
{
	
}

void MsgBox::update(Angler::Game *context, float time, float deltaTime, bool changed)
{
	if (!mPaused)
	{
		mChanged |= changed;

		if (mCurTime >= mTime)
		{
			enable(false);
		}

		mCurTime += deltaTime;

		mUpdateChildren(context, time, deltaTime);
	}
}

void MsgBox::draw(Angler::Game *context, Angler::Graphics::GraphicsEngine *graphics, float time, float deltaTime)
{
	if (mVisible)
	{
		glPushMatrix();

			glTranslatef(0.35f, 0.85f, 0);

			glPushMatrix();
				//First Row
				glScalef(1/20.0f, 1/20.0f, 1);

				glPushMatrix();
					graphics->draw(mBGLayer, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
					glTranslatef(1, 0, 0);
					for (int i = 0; i < 18; i++)
					{
						graphics->draw(mBGLayer, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
					}
					graphics->draw(mBGLayer, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
				glPopMatrix();
				glTranslatef(0, 1, 0);

				glPushMatrix();
					//Last row
					graphics->draw(mBGLayer, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 50/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
					glTranslatef(1, 0, 0);
					for (int i = 0; i < 18; i++)
					{
						graphics->draw(mBGLayer, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 50/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
					}
					graphics->draw(mBGLayer, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 50/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
				glPopMatrix();
				glTranslatef(0, 1, 0);

				glPushMatrix();
					//Last row
					graphics->draw(mBGLayer, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
					glTranslatef(1, 0, 0);
					for (int i = 0; i < 18; i++)
					{
						graphics->draw(mBGLayer, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
					}
					graphics->draw(mBGLayer, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
				glPopMatrix();
			glPopMatrix();

			glScalef(1/20.0f, 1/20.0f, 1);
				glTranslatef(0.25f, 0.25f, 0);
			glScalef(20.0, 20.0f, 1);

			std::string tmp = "";
			for (unsigned int i = 0; i < mText.size(); i++)
			{
				if (mText.at(i) != '\n')
				{
					tmp.push_back(mText.at(i));
				}
				else
				{
					mFont->drawString(graphics, tmp, mTXTLayer, 1.0f);
					glScalef(1/40.0f, 1/40.0f, 1);
						glTranslatef(0, 0.8f, 0);
					glScalef(40.0f, 40.0f, 1);
					tmp.clear();
				}
			}
			mFont->drawString(graphics, tmp, mTXTLayer, 1.0f);
		glPopMatrix();
	}
}

void MsgBox::loadContent()
{

}

void MsgBox::show(std::string text, int bgLayer, int txtLayer, float time)
{
	mText = std::string(text);
	mTime = time;
	mCurTime = 0;
	mBGLayer = bgLayer;
	mTXTLayer = txtLayer;
	enable(true);
}

void MsgBox::show(unsigned long id, int bgLayer, int txtLayer)
{
	std::vector<MsgBoxMessage*>::iterator state = mGetState(id);

	if (state != mMessages.end())
	{
		show((*state)->mMSG, bgLayer, txtLayer, (*state)->mTime);
	}
}

void MsgBox::hide()
{
	enable(false);
}

void MsgBox::init()
{
	mFont = new Font();
	mBuffer = new sf::SoundBuffer();
	mSound = new sf::Sound();
	hide();
}

void MsgBox::addState(unsigned long id, std::string msg, float time)
{
	if (mGetState(id) == mMessages.end())
		mMessages.push_back(new MsgBoxMessage(id, msg, time));
}

std::vector<MsgBoxMessage*>::iterator MsgBox::mGetState(unsigned long id)
{
	for (std::vector<MsgBoxMessage*>::iterator i = mMessages.begin(); i != mMessages.end(); i++)
	{
		if ((*i)->mID == id)
			return i;
	}
	return mMessages.end();
}

void MsgBox::loadStates(std::string file)
{
	std::string content = "";
	std::ifstream fileS(file);

	if (fileS.is_open())
	{
		std::string row = "";
		while (!fileS.eof())
		{
			char c;
			c = fileS.get();

			if (c == '\n' || c == '\r')
			{
				if (row.find('#') == std::string::npos && row.size() > 0)
					content += row + '\n';
				row = "";
			}
			else
			{
				row += c;
			}
		}
	}

	std::stringstream stream(content);	

	unsigned long id;
	char dl;
	std::string msg;
	float time;

	while (!stream.eof())
	{
		stream >> std::hex >> id;
		stream >> dl;

		char im;
		stream >> im;
		if (im == '\"')
		{
			stream >> std::noskipws >> im;
			while (im != '\"')
			{
				msg += im;
				stream >> std::noskipws >> im;
			}
		}

		unsigned int pos = 0;
		while (pos < msg.length() && pos != std::string::npos)
		{
			pos = msg.find("\\\\n", pos);
			if (pos != std::string::npos)
			{
				msg.erase(pos, 3);
				msg.insert(pos, "\n");
			}
		}

		stream >> std::skipws >> time;

		addState(id, msg, time);

		msg = "";
	}
}