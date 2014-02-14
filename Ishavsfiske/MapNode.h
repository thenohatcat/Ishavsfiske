//Version: 0.1.3
//Author: Sihao Li
//Contributors:

#ifndef INC_MAPNODE_H
#define INC_MAPNODE_H

#ifdef ISHAV_0_1_3

#include "IshavsfiskeGame.h"

#include <Angler\Graphics.h>
#include <Angler\Node.h>
#include <Angler\SpriteNode.h>

class MapNode
	: public Angler::Node
{
public:
	MapNode(unsigned long id, Angler::Node *parent, sf::Texture *textureMap, Angler::Game *owner, int tile);
	MapNode(unsigned long id, sf::Texture *textureMap, Angler::Game *owner, int tile);
	
	virtual void draw(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime);

	virtual void update(Angler::Game* context, float time, float deltaTime);

	int getTile();
	void setTile(int tileID);
protected:
	virtual void mInit();
private:
	sf::Texture *mTXMap;
	Angler::Nodes::SpriteNode *mSprite; 
	int mTile;
};

#else
#error MapNode.h: Wrong version 0.1.3
#endif

#endif