#include "Zergling.h"



Zergling::Zergling()
{
	health = 30;
	maxHealth = health;
}


Zergling::~Zergling()
{
}

int Zergling::attack()
{
	return 10;
}

void Zergling::takeDamage(int damage)
{
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}
