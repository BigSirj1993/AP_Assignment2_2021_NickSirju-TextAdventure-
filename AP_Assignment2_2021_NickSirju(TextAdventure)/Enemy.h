#pragma once

#include "STLINCLUDE.h"

// Done

class Enemy
{
private:
	int level;
	int health;
	int healthMax;
	int damageMin = 1;
	int damageMax = 2;
	float dropChance;
	int defense;
	int aim;


public:
	Enemy(int level = 0);
	virtual ~Enemy();

	inline bool isAlive()	{return this->health > 0;}
	string getAsString() const;
	void takeDamage(int damage);

	inline int getLevel()const { return this->level; }
	inline int getDamageMin()const { return this->damageMin; }
	inline int getDamageMax()const { return this->damageMax; }
	inline int getDamage()const { return rand() % this->damageMax + this->damageMin; }
	inline int getExp()const { return this->level * 100; }
	inline int getHealth()const { return this->health; }
	inline int getHealthMax()const { return this->healthMax; }
	inline int getDefense()const { return this->defense; }
	inline int getAim()const { return this->aim; }


};
