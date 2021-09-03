#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "entity.h"
#include "common.h"
#include "battle.h"
#include "player.h"


class Console
{
public:
	static bool DEVELOPER;
	static void query();
	static void npclist();
};