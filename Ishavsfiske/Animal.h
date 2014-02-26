//Version: 0.1.4
//Author: Sihao Li
//Contributors:

#ifndef INC_ANIMAL_H
#define INC_ANIMAL_H

#ifdef ISHAV_0_1_4

#include <Angler\Node.h>
#include <Angler\Translation.h>
#include <Angler\Rotation.h>
#include <Angler\CollisionNode.h>

class isHavsFiskeGame;

class Animal
	: public Angler::Node
{
public:
	Animal(unsigned long id, Angler::Node *parent, Angler::Game *owner);
	Animal(unsigned long id, Angler::Game *owner);

	/*virtual void move(float x, float y);
	virtual void attack();*/

	void update(Angler::Game *context, float time, float deltaTime, bool changed);
protected:
	Angler::Game *mOwner;

	virtual void mInit();

	float mStartX, mStartY;

	Angler::Node *mAnimalRoot;
private:
	/*Angler::Nodes::SpriteNode *mBearSprite;*/

	Angler::Nodes::Translation *mRootTranslation;
	Angler::Nodes::Rotation *mRootRotation;
};


#else
#error Animal.h: Wrong version 0.1.4
#endif

#endif