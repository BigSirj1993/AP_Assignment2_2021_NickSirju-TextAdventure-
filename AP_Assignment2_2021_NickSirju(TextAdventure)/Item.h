#pragma once

#include "STLINCLUDE.h"




// Done

enum itemTypes {WEAPON = 0, ARMOUR};

class Item
{
public:
	Item();
	Item(int itemType, int level, int rarity);
	Item(int itemType, string name, int level, int buyValue, int sellValue, int rarity);
	virtual ~Item();

	inline string debugPrint() const
	{
		return this->name;
	}
	virtual Item* clone() const = 0;
	virtual string toString()const = 0;
	virtual string toStringSave()const = 0;


	// Accessors
	inline const string& getName() const	{ return this->name; }
	inline const int& getLevel() const		{ return this->level;}
	inline const int& getBuyValue() const	{ return this->buyValue;}
	inline const int& getSellValue() const	{ return this->sellValue;}
	inline const int& getRarity() const		{ return this->rarity;}
	inline const int& getItemType() const	{ return this->itemType;}


	//Modifiers
	inline void setName(string name)
	{
		this->name = name;
	}



private:
	int itemType;
	string name;
	int level;
	

protected:
	int buyValue;
	int sellValue;
	int rarity;


};

enum rarity {COMMON = 0, UNCOMMON, RARE, LEGENDARY, EPIC};




















/*class Item
{
public:
	Item(string name = "NONE", int level = 0, int buyValue = 0, int sellValue = 0, int rarity = 0); 
	virtual ~Item();
	//inline void debugPrint() const;
	string debugPrint() const
	{
		return this->name;
	}
	virtual Item* clone()const = 0;



	//ACCESSORS
	const string& getName() const	{return this->name;}
	const int& getLevel() const		{return this->level;}
	const int& buyValue() const		{return this->buyValue;}
	const int& sellValue() const	{return this->sellValue;}
	const int& getRarity() const	{return this->rarity;}
	
	//MODIFIERS
	

private:
	string name;
	int level;
	int buyValue;
	int sellValue;
	int rarity;

};*/

