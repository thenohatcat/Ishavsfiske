//Version: 0.1.4
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_4
#error Tutorial.cpp: Wrong version 0.1.4
#endif

#include "MsgBox.h"

#include "IshavsfiskeGame.h"

using namespace Ishavsfiske;

MsgBox::MsgBox(unsigned long id, Angler::Node *parent, IshavsfiskeGame *owner)
	: Node(id, parent), mText(""), mTime(0), mCurTime(0), mOwner(owner)
{
	
}

MsgBox::MsgBox(unsigned long id, IshavsfiskeGame *owner)
	: Node(id), mText(""), mTime(0), mCurTime(0), mOwner(owner)
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
				glScalef(1/20.0, 1/20.0f, 1);

				glPushMatrix();
					graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
					glTranslatef(1, 0, 0);
					for (int i = 0; i < 18; i++)
					{
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
					}
					graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
				glPopMatrix();
				glTranslatef(0, 1, 0);

				glPushMatrix();
					//Last row
					graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 50/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
					glTranslatef(1, 0, 0);
					for (int i = 0; i < 18; i++)
					{
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 50/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
					}
					graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 50/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
				glPopMatrix();
				glTranslatef(0, 1, 0);

				glPushMatrix();
					//Last row
					graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
					glTranslatef(1, 0, 0);
					for (int i = 0; i < 18; i++)
					{
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
					}
					graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
				glPopMatrix();
			glPopMatrix();

			glScalef(1/20.0, 1/20.0f, 1);
				glTranslatef(0.25f, 0.25f, 0);
			glScalef(20.0, 20.0f, 1);

			std::string tmp = "";
			for (int i = 0; i < mText.size(); i++)
			{
				if (mText.at(i) != '\n')
				{
					tmp.push_back(mText.at(i));
				}
				else
				{
					mFont->drawString(graphics, tmp, 7, 0.8f);
					glScalef(1/40.0f, 1/40.0f, 1);
						glTranslatef(0, 0.8f, 0);
					glScalef(40.0f, 40.0f, 1);
					tmp.clear();
				}
			}
			mFont->drawString(graphics, tmp, 7, 0.8f);
		glPopMatrix();
	}
}

void MsgBox::loadContent()
{
	mBuffer->loadFromFile("Tutorial_Signalljud_2_Wav.wav");
	mSound->setBuffer(*mBuffer);
}

void MsgBox::show(std::string text, float time)
{
	mText = std::string(text);
	mTime = time;
	mCurTime = 0;
	mOwner->getSound()->playSound(mSound, false, -1, -1, false);
	enable(true);
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