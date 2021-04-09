#include "Enemy.h"

//Done

Enemy::Enemy(int level)
{
	this->level = level;
	this->healthMax = rand() % (level * 10) + (level * 2);
	this->health = this->healthMax;
	this->damageMax + this->level * 2;
	this->damageMin + this->level * 1;
	this->dropChance = rand() % 100 + 1;
	this->defense = rand() % level * 5 + 1;
	this->aim = rand() % level * 5 + 1;

}

Enemy::~Enemy()
{


}

string Enemy::getAsString()const
{
	return "Level: " + to_string(this->level) + "\n" +
		"Health: " + to_string(this->health) + " / " + to_string(this->healthMax) + "\n" +
		"Damage: " + to_string(this->damageMin) + " - " + to_string(this->damageMax) + "\n" +
		"Defense: " + to_string(this->defense) + "\n" +
		"Aim" + to_string(this->aim) + "\n" +
		"Drop chance: " + to_string(this->dropChance) + "\n";

}


void Enemy::takeDamage(int damage)
{
	this->health -= damage;

	if (this->health <= 0)
	{
		this->health = 0;
	}

}