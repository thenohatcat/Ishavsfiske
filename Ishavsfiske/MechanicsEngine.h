#ifndef INC_MECHANICSENGINE_H
#define INC_MECHANICSENGINE_H

#include <vector>
#include <glm\glm.hpp>

#include <Angler\Node.h>
#include <Angler\Transformation.h>
#include <Angler\CollisionNode.h>
#include <Angler\HelpFunctions.h>

namespace Ishavsfiske
{
	class IshavsfiskeGame;
}

class MechanicsEngine
{
public:
	MechanicsEngine(Ishavsfiske::IshavsfiskeGame *game);
	~MechanicsEngine();
	void doCollide(Angler::Node *node);
private:
	Ishavsfiske::IshavsfiskeGame *mParent;
};

#endif