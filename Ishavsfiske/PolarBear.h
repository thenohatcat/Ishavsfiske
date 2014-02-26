//Version: 0.1.4
//Author: Sihao Li
//Contributors:

#ifndef INC_POLARBEAR_H
#define INC_POLARBEAR_H

#ifdef ISHAV_0_1_4


#include "Animal.h"

class PolarBear
	: public Animal
{
public:
	PolarBear(unsigned long id, Angler::Node *parent, Angler::Game *owner);
	PolarBear(unsigned long id, Angler::Game *owner);

	void update(Angler::Game* context, float time, float deltaTime, bool changed);

	/*virtual void move(float x, float y);
	virtual void attack();*/
protected:
	virtual void mInit();
private:
	sf::Texture *mTXBear;
};



#else
#error PolarBear.h: Wrong version 0.1.4
#endif

#endif