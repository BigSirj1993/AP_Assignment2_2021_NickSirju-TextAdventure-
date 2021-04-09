#pragma once

#include "STLINCLUDE.h"
#include "Item.h"

//Done

class Weapon : public Item
{

public:
	Weapon();
	Weapon(int level, int rarity);
	Weapon(int damageMin, int damageMax, string name, int level, int buyValue, int sellValue, int rarity);
	virtual ~Weapon();

	//Pure virtual
	virtual Weapon* clone() const;


	//Functions
	string toString()const;
	string toStringSave()const;

	//Accessors
	inline int getDamageMin() const
	{
		return this->damageMin;
	}
	inline int getDamageMax() const
	{
		return this->damageMax;
	}

	//Static
	static dArr<string> name;
	static void initName();

private:
	int damageMin;
	int damageMax;
};


















































/*class Weapon : public Item
{
public:
	Weapon(int damageMin = 0, int damangeMax = 0, string name = "NONE", int level = 0, int buyValue = 0, int sellValue = 0, int rarity = 0);
	virtual ~Weapon();

	// Functions
	string toString();


	// Pure virtual
	virtual Weapon* clone() const;


private:
	int damageMin;
	int damageMax;

};*/

