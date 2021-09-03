#pragma once
#include <vector>
#include "common.h"
#include "entity.h"

class Battle
{
public:
	//static bool active;
	static int weather;
	static int turn;
	static std::vector<Entity*> initiative;

	static void newTurn();
	static void setup();

};