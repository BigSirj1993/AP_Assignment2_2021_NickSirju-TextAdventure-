#include "Weapon.h"

//Done


dArr<string> Weapon::name;



void Weapon::initName()
{
	Weapon::name.push("Long Sword");
	Weapon::name.push("Twin Swords");
	Weapon::name.push("Halberd");
	Weapon::name.push("Katana");
	Weapon::name.push("Mystic Dagger");
	Weapon::name.push("Broad Sword");

}

Weapon::Weapon() : Item()
{
	this->damageMax = 0;
	this->damageMin = 0;
}

Weapon::Weapon(int level, int rarity) : Item(itemTypes::WEAPON, level, rarity)
{
	this->damageMax = rand() % level * (rarity + 1);
	this->damageMax += (rarity + 1) * 5;
	this->setName(Weapon::name[rand() % Weapon::name.size()]);

	if (rarity == 3)
		this->damageMax += level * 5;
	else if (rarity == 4)
		this->damageMax += level * 10;

	this->damageMin = this->damageMax / 2;
}


Weapon::Weapon(int damageMin, int damageMax, string name, int level, int buyValue, int sellValue, int rarity) : Item(itemTypes::WEAPON, name, level, buyValue, sellValue, rarity)
{
	this->damageMin = damageMin;
	this->damageMax = damageMax;
}

Weapon::~Weapon()
{

}


Weapon* Weapon::clone() const
{
	return new Weapon(*this);
}

string Weapon::toString()const
{
	string str =
		this->getName() + " | Level: " +
		to_string(this->getLevel()) + " | Rarity: " +
		to_string(this->getRarity()) + " | Damage: " +
		to_string(this->getDamageMin()) + " - " +
		to_string(this->getDamageMax());

	return str;
}

string Weapon::toStringSave()const
{
	string str =
		to_string(this->getItemType()) + " " + this->getName() + "  " +
		to_string(this->getLevel()) + "  " +
		to_string(this->getRarity()) + "   " +
		to_string(this->getBuyValue()) + "   " +
		to_string(this->getSellValue()) + "   " +
		to_string(this->damageMin) + "    " +
		to_string(this->damageMax) + "    ";
		
	return str;
}




































/*Weapon::Weapon(int damageMin, int damageMax, string name, int level, int buyValue, int sellValue, int rarity) : Item(name, level, buyValue, sellValue, rarity)
{
	this->damageMin = damageMin;
	this->damageMax = damageMax;
}

Weapon::~Weapon()
{

}

Weapon* Weapon::clone()const
{
	return new Weapon(*this); 
}

string Weapon::toString()
{
	string str = to_string(this->damageMin) + " " + to_string(this->damageMax);

	return str;
}*/