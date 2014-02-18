//Version: 0.1.3
//Author: Marcus Persson
//Contributors: 

#ifndef INC_FONT_H
#define INC_FONT_H

#ifdef ISHAV_0_1_3

#include <Angler\Graphics.h>

#include <string>

class Font
{
public:
	Font();

	void drawString(Angler::Graphics::GraphicsEngine* graphics, std::string st, int layer, float size);
private:
	void loadDistance();
	float rightDistance[256];
	float leftDistance[256];
	float getWidth(char c);
	float getWidth(std::string s);
};

#else
#error Font.h: Wrong version 0.1.3
#endif

#endif