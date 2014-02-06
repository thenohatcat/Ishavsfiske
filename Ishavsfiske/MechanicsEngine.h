#ifndef INC_MECHANICSENGINE_H
#define INC_MECHANICSENGINE_H

#include <Angler\Node.h>
#include <Angler\Transformation.h>
#include <glm\glm.hpp>
#include <Angler\HelpFunctions.h>
#include <Angler\CollisionNode.h>
#include <vector>
#include <Ishavsfiske\IshavsfiskeGame.h>

using namespace Angler;
using namespace Ishavsfiske;

class MechanicsEngine
{
public:
	MechanicsEngine(IshavsfiskeGame *game);
	~MechanicsEngine();
	void doCollide(Node *node);
private:
	IshavsfiskeGame *mParent;
};

#endif