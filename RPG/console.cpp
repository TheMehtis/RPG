#include "console.h"
bool Console::DEVELOPER = true;

void Console::query()
{
	std::cout << ">> ";
	std::string line;

	std::getline(std::cin, line);

	std::vector<std::string> lineSplit = split(line, ' ');

	//COMMAND: Quit game
	if (lineSplit[0] == "exit")
	{
		exit(0);
	}

	//COMMAND: Start a battle
	else if (lineSplit[0] == "battle")
	{
		//Allow combat only when not in combat
		if (!Player::control->inCombat)
		{
			if (lineSplit.size() < 2)
			{
				std::cout << "You need to type second parameter for entity that will fight you.\n";
			}
			else if (getIntFromString(lineSplit[1]) < 0 || getIntFromString(lineSplit[1]) >= Entity::npcList.size())
			{
				std::cout << "NPC id out of range\n";
			}
			else
			{


				Player::control->enterCombat();

				//Setup enemy data
				int theNpc = getIntFromString(lineSplit[1]);
				int npc_id = getIntFromString(Entity::npcList[theNpc][0]);
				const char* npc_name = Entity::npcList[theNpc][1].c_str();
				int npc_health = getIntFromString(Entity::npcList[theNpc][2]);;
				int npc_mana = getIntFromString(Entity::npcList[theNpc][3]);;

				//Make NPC
				Entity *ent = new Entity(npc_id, npc_name, npc_health, npc_mana);
				ent->enterCombat();

				//Setup battle
				Battle::newTurn();
			}
		}
		else
		{
			std::cout << "You are already in combat!\n";
		}
		
		

	}

	//COMMAND: List entities
	else if (lineSplit[0] == "list")
	{
		for (unsigned int i = 0; i < Entity::entList.size(); i++)
		{

			std::cout <<
			"______________________________________\n"
			"Name: " << Entity::entList[i].name <<
			"\nTarget: " << Entity::entList[i].target->uid << " " << Entity::entList[i].target->name <<
			"\nHealth: " << Entity::entList[i].health <<
			"\nMana: " << Entity::entList[i].mana <<
			"\n";

		}
	}

	//COMMAND: Lists all Entities of the initiative order
	
	else if (lineSplit[0] == "order")
	{	
		//Only when not in a battle; initiative order empty
		if (Battle::initiative.size() > 0)
		{	
			for (unsigned int i = 0; i < Battle::initiative.size(); i++)
			{
				std::cout << "[" << Battle::initiative[i]->uid << "]" << Battle::initiative[i]->name << "\n";
			}
		}
		else
		{
			std::cout << "Initiative order is empty, or you are not in a battle!\n";
		}
		
	}
	
	//COMMAND: Show stats of the player controlled entity
	else if (lineSplit[0] == "me")
	{
		std::cout <<
		"Name: " <<     Player::control->name <<
		"\nTarget: " << "[" << Player::control->target->uid << "]" << Player::control->target->name << 
		"\nHealth: " << Player::control->health <<
		"\nMana: " <<   Player::control->mana <<
		"\n";
	}

	//COMMAND: List all NPCs in the game
	else if (lineSplit[0] == "npclist")
	{
		Console::npclist();
	}

	//COMMAND: List commands
	else if (lineSplit[0] == "help")
	{
	std::cout <<
		"me: Lists player information such as your target, health, and other stats\n" <<
		"attack: Attack your enemy with your melee weapon\n" <<
		"order: List initiative order\n";
	}

	//COMMAND: Test function
	else if (lineSplit[0] == "test")
	{
		//std::cout << Battle::initiative[1]->name;
	}

	//COMMAND: Attack with your melee weapon
	else if (lineSplit[0] == "attack")
	{
	std::cout << "Attempting to perform a melee attack...\n";
		Player::control->attack(8, 0);

	}

	//COMMAND: End your turn, and pass it to next in initiative order
	else if (lineSplit[0] == "endturn")
	{
	std::cout << "Your turn ended.\n";

	}

	//COMMAND: Used when enemy has to end their turn
	else if (lineSplit[0] == "continue")
	{

	}

	//Print invalid command if nothing else will match
	else
	{
		std::cout << "Invalid command. Type 'help' to see commands.\n";
	}

}


void Console::npclist()
{
	std::cout << "Listing all available NPCs...\n";
	std::cout << "ID\u0009Name\u0009\u0009Health\n";
	for (int i = 0; i < Entity::npcList.size(); i++)
	{
		std::cout << Entity::npcList[i][0] << "\u0009" << Entity::npcList[i][1] << "\u0009\u0009" << Entity::npcList[i][2] << " " << Entity::npcList[i][3] << "\n";
	}
}