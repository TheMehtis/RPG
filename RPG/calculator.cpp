#include "calculator.h"

Calculator::Calculator()
{

}


int* Calculator::dCalc(Entity& attacker, Entity& victim, int d, int t)
{
	double reductionPct = (double)victim.armor / (victim.armor + 400 + 85 * 10);
	int damage = d + attacker.strength;
	int reducedDamage;

	//Physical
	if (t == 0)
	{
		reducedDamage = damage * reductionPct;
		damage = damage - reducedDamage;

		/*
		std::cout << "Reduction %: " << reductionPct << "\n";
		std::cout << "Reduced damage: " << reducedDamage << "\n";
		std::cout << "Damage: " << damage << "\n";
		*/
	}

	int* damageArr = new int[2];
	damageArr[0] = damage;
	damageArr[1] = (int)reducedDamage;
	return damageArr;
	
}

