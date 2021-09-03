#include "game.h"
#include "calculator.h"
using namespace std;

void game_init()
{

	//Load NPCs
	ifstream npcstream;
	npcstream.open("npc.txt");
	string out;

	while (!npcstream.eof())
	{
		std::getline(npcstream, out);
		Entity::npcList.push_back(split(out, ','));
	}
	npcstream.close();
	std::cout << "Loaded " << Entity::npcList.size() << " NPCs.\n";


	//Intro
	std::cout << "Welcome to Mehtis RPG game!\n";
	char name[30];
	const char* namep;

	//Print GM mode
	if (Console::DEVELOPER)
	{
		namep = "Mehtis";
		std::cout << "GM mode is: ON\n";
	}
	else
	{
		//Ask for character name
		cout << "What is your name?\n>>";
		namep = name;
		cin.getline(name, 30);
	}




	Player::name = namep;
	Player::baseHealth = 50;
	Player::baseMana = 65;

	Entity* P = new Entity(Player::name, Player::baseHealth, Player::baseMana);
	Player::control = P;
	P->name = namep;
	std::cout << "Type 'help' to get more information about commands.\n";



	gameLoop();
}

void gameLoop()
{

	for (int i = 0; i < INFINITY; i++)
	{
		Console::query();
	}
}