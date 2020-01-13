#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

int Entity::attack() {
	return 0;
}

void Entity::takeDamage(int damage) {
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}


bool Entity::isAlive()
{
	return health != 0;
}
