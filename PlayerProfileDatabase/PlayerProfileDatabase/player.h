#pragma once
#include <string>

class Player {
public:
	Player();
	Player(int h, int a,std::string n);
	void addHealth(int h);
	void addAttack(int a);
	int getHealth();
	int getAttack();
	std::string getName();
	void setHealth(int h);
	void setAttack(int a);
	void setName(std::string n);
	~Player();
private:
	std::string name;
	int health;
	int attack;
	friend int main();
};