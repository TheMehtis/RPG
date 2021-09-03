#include "entity.h"
#include "battle.h"
#include "calculator.h"

int Entity::entCounter = 0;
std::vector<Entity> Entity::entList;
std::vector<std::vector<std::string>> Entity::npcList;

Entity::Entity(int npc_id, const char* npc_name, int npc_health, int npc_mana) :
	uid(Entity::entCounter),
	id(npc_id),
	name(npc_name),
	health(npc_health),
	mana(npc_mana),
	target(this)

{


	Entity::entList.push_back(*this);
	std::cout << this->name << " spawned!\n";
	Entity::entCounter++;

}

Entity::Entity(const char* N, int health, int mana) : uid(Entity::entCounter), team(1), id(0), name(N) ,level(1), health(health), mana(mana)
{
	std::cout << "Player " << this->name << " entered the world!\n";
	this->setTarget(*this);
	Entity::entCounter++;
	Entity::entList.push_back(*this);
}

void Entity::setTarget(Entity& ent)
{
	this->target = &ent;

}

Entity& Entity::getTarget()
{
	return *this->target;
}

void Entity::spawn(const char* N)
{


}

int Entity::getHealth()
{
	return this->health;
}

int Entity::getMana()
{
	return this->mana;
}

void Entity::enterCombat()
{
	this->inCombat = true;
	this->AP = maxAP;
	std::cout << this->name << " entered combat!\n";
	Battle::initiative.push_back(this);
}

void Entity::takeDamage(Entity& attacker, int d, char t)
{
	int* damage = Calculator::dCalc(attacker, *this, d, t);


	this->health = this->getHealth() - damage[0];
	std::cout << attacker.name << " hit " << this->name << " for " << damage[0] << " damage (" << damage[1] << " reduced).\n";

	delete[] damage;
}

void Entity::attack(int d, char t)
{
	if (this->AP >= 4 || !this->inCombat)
	{
		this->target->takeDamage(*this, d, 0);
		if (this->inCombat) { this->AP -= 4; };
		std::cout << "AP is now: " << this->AP << "\n";
	}
	else
	{
		std::cout << "Not enough Action points!\n";
	}

}