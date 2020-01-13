#pragma once
class Entity
{
public:
	Entity();
	~Entity();

	virtual int attack();
	virtual void takeDamage(int damage);
	bool isAlive();

private:
	int health;
	friend class Marine;
	friend class Zergling;
	int maxHealth;
};

