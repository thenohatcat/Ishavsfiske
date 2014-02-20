//Version: 0.1.4
//Author: Marcus Persson
//Contributors: 

#include "Font.h"

#ifndef ISHAV_0_1_4
#error Font.cpp: Wrong version 0.1.4
#endif

Font::Font()
{
	loadDistance();
}

void Font::drawString(Angler::Graphics::GraphicsEngine* graphics, std::string st, int layer, float size)
{
	glPushMatrix();
	glScalef(size*(1/40.0f), size*(1/40.0f), 1);
	for(std::string::size_type i = 0; i < st.length(); i++)
	{
		graphics->draw(layer, sf::Vector2f(leftDistance[st[i]], 0), 
			sf::Vector2f(((st[i]%16)*(1/16.0f)),((st[i]/16)*(1/16.0f))), sf::Vector2f((1/16.0f),(1/16.0f)));
		glTranslated(rightDistance[st[i]], 0, 0);
	}
	glPopMatrix();
}

void Font::loadDistance()
{
	for(int i = 0; i < 256; i++)
	{
		if(i == 'i')
			leftDistance[i] = 0.2f;
		else
			leftDistance[i] = 0;
	}
	for(int k = 0; k < 256; k++)
	{
		if(k == 'i')
			rightDistance[k] = 0.7f;
		else
			rightDistance[k] = 1;
	}
}

float Font::getWidth(char c)
{
	return rightDistance[c] - leftDistance[c];
}

float Font::getWidth(std::string s)
{
	float width = 0.0f;

	for(unsigned int i = 0; i < s.length(); i++)
	{
		width += getWidth(s[i]);
	}

	return width;
}