//Version: 0.1.3
//Author: Marcus Persson
//Contributors: 

#include "Font.h"

void Font::drawString(Angler::Graphics::GraphicsEngine* graphics, std::string st, sf::Texture *tx, float size)
{
	loadDistance();
	glPushMatrix();
	glScalef(size*(1/40.0), size*(1/40.0), 1);
	for(std::string::size_type i = 0; i < st.length(); i++)
	{
		graphics->draw(3, tx, sf::Vector2f(leftDistance[st[i]], 0), sf::Vector2f(((st[i]%16)*(1/16.0)),((st[i]/16)*(1/16.0))), sf::Vector2f((1/16.0),(1/16.0)));
		glTranslated(rightDistance[st[i]], 0, 0);
	}
	glPopMatrix();
}

void Font::loadDistance()
{
	for(int i = 0; i < 256; i++)
	{
		if(i == 116)
			leftDistance[i] = 0.2;
		else
			leftDistance[i] = 0;
	}
	for(int k = 0; k < 256; k++)
	{
		if(k == 116)
			rightDistance[k] = 0.7;
		else
			rightDistance[k] = 1;
	}
}