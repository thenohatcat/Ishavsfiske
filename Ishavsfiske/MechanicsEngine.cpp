#include "MechanicsEngine.h"

#include "IshavsfiskeGame.h"

using namespace Angler;
using namespace Ishavsfiske;
using namespace Angler::Nodes;
using namespace Angler::HelpFunctions;

MechanicsEngine::MechanicsEngine(IshavsfiskeGame *game)
	: mParent(game)
{

}

MechanicsEngine::~MechanicsEngine()
{

}

void MechanicsEngine::doCollide(Node *node)
{
	std::vector<Node*> nds = getDescendants(node);

	for(int i = 0; i < nds.size(); i++)
	{
		for(int k = i + 1; k < nds.size(); k++)
		{
			if(typeid(*nds[i]) == typeid(CollisionNode) && 
				typeid(*nds[k]) == typeid(CollisionNode))
				if(((CollisionNode*)nds[i])->isColliding((CollisionNode*)nds[k]) == 1)
					mParent->collide(nds[i], nds[k]);
		}
	}
}