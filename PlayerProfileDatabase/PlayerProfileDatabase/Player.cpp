#include "player.h"

Player::Player() {
	health = 0;
	attack = 0;
}
Player::Player(int h, int a, std::string n) {
	health = h;
	attack = a;
	name = n;
}
Player::~Player() {

}
void Player::addHealth(int h) {
	health += h;
}
void Player::addAttack(int a) {
	attack += a;
}
int Player::getHealth() {
	return health;
}
int Player::getAttack() {
	return attack;
}
std::string Player::getName() {
	return name;
}
void Player::setHealth(int h) {
	health = h;
}
void Player::setAttack(int a) {
	attack = a;
}
void Player::setName(std::string s) {
	name = s;
}