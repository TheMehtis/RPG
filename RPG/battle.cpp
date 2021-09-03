#include "battle.h"

int Battle::turn = 0;
std::vector<Entity*> Battle::initiative;

void Battle::newTurn()
{
	Battle::turn++;
	std::cout << "Turn: " << Battle::turn << "\n";
}

void Battle::setup()
{
	/*
	Battle::initiative.clear();
	int numOfEntities = Entity::entList.size();

	//Loop through all entities, and set all entities into initiative order
	for (int i = 0; i < numOfEntities; i++)
	{
		Battle::initiative.push_back(&Entity::entList[i]);
	}
	std::cout << Battle::initiative[0]->health;
	*/
}