//Version: 0.1.5
//Author: Sihao Li
//Contributors:

#ifndef INC_MAP_H
#define INC_MAP_H

#ifdef ISHAV_0_1_5

#include <Angler\Game.h>
#include <Angler\Node.h>
#include <Angler\Translation.h>

#include "MapNode.h"

namespace Ishavsfiske
{
	class Map
		: public Angler::Node
	{
	public:
		Map(unsigned long id, Angler::Node *parent, Angler::Game *owner);
		Map(unsigned long id, Angler::Node *parent, Angler::Game *owner, int lvl);
	
		int getTile(int index);
		void setTile(int index, int tile);

		void setPos(sf::Vector2i pos);
		sf::Vector2i getPos();

		void move(sf::Vector2f diff);

		void genMap(int lvl);

		void revert();

		void update(Angler::Game* context, float time, float deltaTime, bool changed);

		void updateMap();

		void load(int num, std::string file);

	protected:
		virtual void mInit();
	private:
		void mSetTranslation(float x, float y);

		int mMap [48 * 40];

		int lMap [8][48 * 40];

		Angler::Game *mParent;
		sf::Vector2i mPos;
		sf::Vector2i mOldPos, mLPos;
		sf::Vector2f mOldTransPos, mLTransPos;
		void mUpdateMap();
		bool mIsEdge(int x, int y);
		bool mIsWater(int x, int y), mIsWaterTop(int x, int y), mIsWaterRight(int x, int y), mIsWaterLeft(int x, int y), mIsWaterBot(int x, int y),
			mIsWaterTopLeft(int x, int y), mIsWaterTopRight(int x, int y), mIsWaterBotLeft(int x, int y), mIsWaterBotRight(int x, int y);
		int mIsIceDir(int x, int y);
		bool mIsIceLeft(int x, int y), mIsIceRight(int x, int y), mIsIceTop(int x, int y), mIsIceBot(int x, int y),
			mIsIceBotLeft(int x, int y), mIsIceBotRight(int x, int y), mIsIceTopLeft(int x, int y), mIsIceTopRight(int x, int y);
		bool mOutsideMap(int x, int y);

		Angler::Nodes::Translation *mMapPosition;

		MapNode *mMapNodes[26 * 22];
	};
}

#else
#error Map.h: Wrong version 0.1.5
#endif

#endif