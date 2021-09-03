#pragma once
#include <iostream>
#include <vector>
#include "common.h"



class Entity
{
public:
	Entity(int npc_id, const char* npc_name, int npc_health, int npc_mana);
	Entity(const char* N, int health, int mana);

	static std::vector<int> ids;
	static int entCounter;
	static std::vector<Entity> entList;
	static std::vector<std::vector<std::string>> npcList;

	int id;
	int uid;
	const char* name;
	int level;
	int health;
	int mana;
	short AP;
	short maxAP = 10;

	short strength = 10;
	short agility = 10;
	short intellect = 10;
	short armor = 1000;

	char team;
	bool inCombat;
	Entity* target;
		
	void takeDamage(Entity& attacker, int d, char t);
	void attack(int d, char t);
	int getHealth();
	int getMana();
	void setTarget(Entity& ent);
	Entity& getTarget();
	void enterCombat();
	static void spawn(const char* N);
};
