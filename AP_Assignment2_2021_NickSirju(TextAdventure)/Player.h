#pragma once

#include "STLINCLUDE.h"
#include "BackPack.h"

//Done

using namespace std;



class Player // Creating player
{
public:
	Player();
	Player(string name, int distanceWalked, int gold, int level, int exp, int attack, int vitality, int dexterity, int mind, int willpower, int health, int stamina, int statPoints);
	virtual ~Player();

	// Functions 
	void initialize(const string name);
	void printStats() const;
	string getAsString() const;
	string getBackPackAsString(bool shop = false);
	string getBackPackAsStringSave();
	void levelUp();
	void updateStats();
	void addToStats(int stat, int value);
	void equipItem(unsigned index);
	inline void resetHealth()
	{
		this->health = this->healthMax;
	}
	void addItem(const Item& item)
	{
		this->backpack.addItem(item);
	}
	void removeItem(const int index);
	const Item& getItem(const int index);

	//Accessors(getters)
	inline const int& getDistanceWalked() const { return this->distanceWalked; }
	inline const string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getExp() const { return this->exp; }
	inline const int& getExpNext() const { return this->expNext; }
	inline const int& getStatPoints() const { return this->statPoints; }
	inline const int& getHealth() const { return this->health; }
	inline const int& getMaxHealth() const { return this->healthMax; }
	inline const bool isAlive() const { return this->health > 0; }
	inline const int& getStamina() const { return this->stamina; }
	inline const int& getDamageMin() const { return this->damageMin; }
	inline const int& getDamageMax() const { return this->damageMax; }
	inline const int getDamage() const { return rand() % (this->damageMax + this->weapon.getDamageMax()) + (this->damageMin + this->weapon.getDamageMin()); }
	inline const int& getDefense() const { return this->defense; }
	inline const int& getAim() const { return this->aim; }
	inline const int& getAddedDefense() const { return this->armour_arms.getDefense() + this->armour_chest.getDefense() + this->armour_legs.getDefense() + this->armour_head.getDefense(); }
	inline const int& getGold() const { return this->gold; }
	inline const int& getBackPackSize() const { return this->backpack.size(); }

	// Modifiers(setters)
	inline void setWeapon(Weapon weapon) { this->weapon = weapon; }
	inline void setArmourHead(Armour armor_head) { this->armour_head = armor_head; }
	inline void setArmourChest(Armour armor_chest) { this->armour_chest = armor_chest; }
	inline void setArmourArms(Armour armor_arms) { this->armour_arms = armor_arms; }
	inline void setArmourLegs(Armour armor_legs) { this->armour_legs = armor_legs; }
	inline void setDistanceWalked(const int& distance) { this->distanceWalked = distance; }
	inline void walked() { this->distanceWalked++; }
	inline void gainExp(const int exp) { this->exp += exp; }
	inline void gainGold(const int gold) { this->gold += gold; }
	inline void payGold(const int gold) { this->gold -= gold; }
	void takeDamage(const int damage);


private:
	
	int distanceWalked;

	BackPack backpack;
	Weapon weapon;
	Armour armour_head;
	Armour armour_chest;
	Armour armour_arms;
	Armour armour_legs;
	int gold;


	
	string name;
	int level = 1;
	int exp;
	int expNext;

	int attack; // Physical attack
	int defense; // Physical defense
	int vitality; // How much health one player has
	int dexterity; // How skilled a player is
	int mind; // Magical attack
	int willpower; // Magical defense
	int aim; // Accuracy

	int health;
	int healthMax;
	int stamina;
	int staminaMax;
	int damageMin;
	int damageMax;
	


	int statPoints; // Checking stats points
	

};
