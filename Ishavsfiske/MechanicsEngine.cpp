#include "MechanicsEngine.h"

MechanicsEngine::MechanicsEngine(IshavsfiskeGame *game)
	: mParent(game)
{

}

MechanicsEngine::~MechanicsEngine()
{

}

void MechanicsEngine::doCollide(Node *node)
{
	std::vector<Node*> nds = Angler::HelpFunctions::getDescendants(node);
	//std::vector<Node*> nxt;

	for(int i = 0; i < nds.size(); i++)
	{
		for(int k = i + 1; k < nds.size(); k++)
		{
			if(typeid(*nds[i]) == typeid(Angler::Nodes::CollisionNode) && typeid(*nds[k]) == typeid(Angler::Nodes::CollisionNode))
				if(((Angler::Nodes::CollisionNode*) nds[i]) -> isColliding((Angler::Nodes::CollisionNode*) nds[k]) ==1)
					mParent->collide(nds[i], nds[k]);
		}
	}
}