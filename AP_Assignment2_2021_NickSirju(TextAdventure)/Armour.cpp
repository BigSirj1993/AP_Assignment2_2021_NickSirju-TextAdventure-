#include "Armour.h"

//Done

dArr<string> Armour::names;

void Armour::initNames()
{
	Armour::names.push("Asura's Punishment");
	Armour::names.push("Lowly Rags");
	Armour::names.push("Kali's Wrath");
	Armour::names.push("Blessed Spirit");
	Armour::names.push("Heavy Steer");
	Armour::names.push("Aurora's Benevolence");
		
}

Armour::Armour():Item()
{
	this->type = -1;
	this->defense = 1;

}

Armour::Armour(int level, int rarity) : Item(itemTypes::ARMOUR, level, rarity)
{
	

	this->defense = 1 + rand() % 5;
	
	this->type = rand() % 4;

	switch (this->type)
	{
	case armourType::HEAD:
		
		this->typeStr = "Head";
		break;
	
	case armourType::CHEST:
		this->typeStr = "Chest";
		break;
	
	case armourType::ARMS:
		this->typeStr = "Arms";
		break;
	
	case armourType::LEGS:
		this->typeStr = "Legs";
		break;
	
	default:
		this->typeStr = "ERROR INVALID!";
		break;
	}
	
	//this->setName(Armour::names[rand() % Armour::names.size()]);

	if (rarity == 3)
		this->defense += level * 5;
	else if (rarity == 4)
		this->defense += level * 10;

}

Armour::Armour(int type, int defense, string name, int level, int buyValue, int sellValue, int rarity) 
	: Armour(level, rarity)
{
	this->type = type;
	this->defense = defense;
	//this->names[0] = name;
	this->buyValue = buyValue;
	this->sellValue = sellValue;
	this->rarity = rarity;
	
}

Armour::~Armour()
{


}


Armour* Armour::clone()const
{
	return new Armour(*this);
}

string Armour::toString()const
{
	string str =
		this->getName()
		+ "| Type: "
		+ this->typeStr
		+ "| Level: "
		+ to_string(this->getLevel())
		+ "| Rarity: "
		+ to_string(this->getRarity())
		+ "| Defense: "
		+ to_string(this->defense);


	return str;


}

string Armour::toStringSave()const
{
	string str =
		to_string(this->getItemType())
		+ "   "
		+ this->getName()
		+ "   "
		+ to_string(this->getLevel())
		+ "   "
		+ to_string(this->getRarity())
		+ "   "
		+ to_string(this->getBuyValue())
		+ "   "
		+ to_string(this->getSellValue())
		+ "   "
		+ to_string(this->defense)
		+ "   "
		+ to_string(this->type)
		+ "   ";

	return str;
}