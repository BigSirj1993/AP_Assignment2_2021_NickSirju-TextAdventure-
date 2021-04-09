#pragma once

#include "STLINCLUDE.h"
#include "Item.h"

//Done

using namespace std;

enum armourType {HEAD = 0, CHEST, ARMS, LEGS};

class Armour : public Item
{
public:
	Armour();
	Armour(int level, int rarity);
	Armour(int type, int defense, string name, int level, int buyValue, int sellValue, int rarity);
	virtual ~Armour();

	

	// Pure Virtual
	virtual Armour* clone() const;

	//Function
	string toString() const;
	string toStringSave() const;

	//Accessors
	inline int getDefense()const 
	{ 
		return this->defense; 
	}
	inline int getType()const 
	{ 
		return this->type;
	}

	//Static 
	static dArr<string> names;
	static void initNames();

private:
	int type;
	string typeStr;
	int defense;

};























/*class Armour : public Item
{
private:
	int type; // Type of armour like breastplate, legs, arms, helmet
	int defense; // how much defense

public:
	Armour(int type = 0, int defense = 0, string name = "NONE", int level = 0, int buyValue = 0, int sellValue = 0, int rarity = 0);
	virtual ~Armour();


	//Pure Virtual
	virtual Armour* clone() const;

	//Functions
	string toString();
};*/

