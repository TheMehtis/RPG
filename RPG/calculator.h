#pragma once
#include "entity.h"

class Calculator
{
public:
	Calculator();
	static int* dCalc(Entity& attacker, Entity& victim, int d, int t);
};