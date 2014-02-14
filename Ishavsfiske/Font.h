//Version: 0.1.3
//Author: Marcus Persson
//Contributors: 

#ifndef INC_FONT_H
#define INC_FONT_H

#include <Angler\Graphics.h>

#include <string>

class Font
{
public:
	void drawString(Angler::Graphics::GraphicsEngine* graphics, std::string st, sf::Texture *tx, float size);
private:
	void loadDistance();
	float rightDistance[256];
	float leftDistance[256];
};

#endif