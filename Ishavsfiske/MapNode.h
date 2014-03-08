//Version: 0.1.4
//Author: Sihao Li
//Contributors:

#ifndef INC_MAPNODE_H
#define INC_MAPNODE_H

#ifdef ISHAV_0_1_4

#include <Angler\Game.h>
#include <Angler\Graphics.h>
#include <Angler\Node.h>
#include <Angler\CollisionNode.h>
#include <Angler\SpriteNode.h>

class MapNode
	: public Angler::Node
{
public:
	MapNode(unsigned long id, Angler::Node *parent, Angler::Game *owner, int tile);
	MapNode(unsigned long id, Angler::Game *owner, int tile);
	
	virtual ~MapNode();

	virtual void draw(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime);

	int getTile();
	void setTile(int tileID);
protected:
	virtual void mInit();
private:
	Angler::Nodes::SpriteNode *mSprite; 
	Angler::Nodes::CollisionNode *mColl;
	int mTile;
};

#else
#error MapNode.h: Wrong version 0.1.4
#endif

#endif