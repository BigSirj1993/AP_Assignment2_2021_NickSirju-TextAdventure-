#include "Player.h"

//Done

Player::Player() // Player definition 
{
	this->distanceWalked = 0;

	this->gold = 0;

	this->name = "";
	this->level = 0;
	this->exp = 0;
	this->expNext = 0;
	this->health = 0;
	this->healthMax = 0;
	this->stamina = 0;
	this->staminaMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->aim = 0;
	this->attack = 0;
	this->defense = 0;
	this->vitality = 0;
	this->mind = 0;
	this->willpower = 0;

	this->statPoints = 0;
	
}

Player::Player(string name, int distanceWalked, int gold, int level, int exp, int attack, int vitality, int dexterity, int mind, int willpower, int health, int stamina, int statPoints)
{
	this->distanceWalked = distanceWalked;
	this->gold = gold;
	this->name = name;
	this->exp = exp;
	this->expNext = 0;

	this->attack = attack;
	this->vitality = vitality;
	this->dexterity = dexterity;
	this->mind = mind;
	this->willpower = willpower;


	this->health = health;
	this->healthMax = 0;
	this->stamina = stamina;
	this->staminaMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defense = 0;
	
	this->statPoints = statPoints;

}



Player::~Player()
{


}

//Functions
void Player :: initialize(const string name)
{
	this->distanceWalked = 0;

	this->gold = 200;

	this->name = name;
	this->level = 1;
	this->exp = 0;
	
	

	this->attack = 5;
	this->vitality = 5;
	this->dexterity = 5;
	this->mind = 5;
	this->willpower = 5;
	this->health = 20;
	this->healthMax = 20;
	this->stamina = 20;
	this->staminaMax = 20;
	this->aim = 20;

	this->statPoints = 1;

	this->updateStats();


}

void Player::printStats() const
{
	cout << " = Player Sheet = " << endl;
	cout << " = Name:  " << this->name << endl;
	cout << " = Level: " << this->level << endl;
	cout << " = Exp: " << this->exp << endl;
	cout << " = Exp To Next Level: " << this->expNext << endl;
	cout << " = Stat Points" << this->statPoints << "\n";
	

	cout << " = Attack: " << this->attack << endl;
	cout << " = Defense: " << this->defense << endl;
	cout << " = Vitality: " << this->vitality << endl;
	cout << " = Dexerity: " << this->dexterity << endl;
	cout << " = Mind: " << this->mind << endl;
	cout << " = Willpower: " << this->willpower << endl;
	


	cout << " = Health: " << this->health << "/" << this->healthMax << endl;
	cout << " = Stamina: " << this->stamina << "/" << this->staminaMax << endl;
	cout << " = Damage: " << this->damageMin << " - " << this->damageMax << endl;
	cout << " = Defense: " << this->defense << "( + " << to_string(this->getAddedDefense()) << ")" << "\n";
	
	cout << " = Distance Walked: " << this->distanceWalked << "\n ";
	cout << " = Gold: " << this->gold << "\n";

	cout << " = Weapon: " << this->weapon.getName()
		<< " = Level: " << this->weapon.getLevel()
		<< " = Damage: " << this->weapon.getDamageMin() << " - " << this->weapon.getDamageMax() << "\n";
	
	cout << " = Armour Head: " << this->armour_head.getName()
		<< " = Level: " << this->armour_head.getLevel()
		<< " = Defence: " << this->armour_head.getDefense() << "\n";
	
	cout << " = Armour Chest: " << this->armour_chest.getName() << "\n"
		<< " = Level: " << this->armour_chest.getLevel()
		<< " = Defence: " << this->armour_chest.getDefense() << "\n";
	
	cout << " = Armour Arms: " << this->armour_arms.getName() << "\n"
		<< " = Level: " << this->armour_arms.getLevel()
		<< " = Defence: " << this->armour_arms.getDefense() << "\n";

	cout << " = Armour Legs: " << this->armour_legs.getName() << "\n"
		<< " = Level: " << this->armour_legs.getLevel()
		<< " = Defence: " << this->armour_legs.getDefense() << "\n";
}



string Player::getAsString() const
{
	return name + " "
		+ to_string(distanceWalked) + " "
		+ to_string(gold) + " "
		+ to_string(level) + " "
		+ to_string(exp) + " "
		+ to_string(attack) + " "
		+ to_string(vitality) + " "
		+ to_string(dexterity) + " "
		+ to_string(health) + "  "
		+ to_string(mind) + " "
		+ to_string(willpower) + " "
		+ to_string(stamina) + " "
		+ to_string(statPoints) + " "
		+ this->weapon.toStringSave()
		+ this->armour_head.toStringSave()
		+ this->armour_chest.toStringSave()
		+ this->armour_arms.toStringSave()
		+ this->armour_legs.toStringSave();
		
}


string Player::getBackPackAsString(bool store)
{
	string bp;

	for (size_t i = 0; i < this->backpack.size(); i++)
	{
		if (store)
		{
			bp += to_string(i) + ": " + this->backpack[i].toString() + "\n" + " - Sell Value: "
				+ to_string(this->backpack[i].getSellValue()) + "\n";
		}
		else
		{
			bp += to_string(i) + ": " + this->backpack[i].toString() + "\n";
		}
	}

	return bp;

}

string Player::getBackPackAsStringSave()
{

	string bp;

	for (size_t i = 0; i < this->backpack.size(); i++)
	{
		if (this->backpack[i].getItemType() == itemTypes::ARMOUR)
			bp += this->backpack[i].toStringSave();
	}

	return bp;
}



void Player :: levelUp()
{
	if (this->exp >= this->expNext)
	{
		this-> exp -= this-> expNext;
		this-> level++;
		this->expNext = static_cast<int>((50 / 3) * ((pow(level, 3)
			- 6 * pow(level, 2))
			+ 17 * level - 12)) + 100;

		this->statPoints++;
		
		this->updateStats();

		cout << "YOU HAVE INCREASED YOUR TO LEVEL TO " << this->level << "! " << "\n\n";
	}
	else
	{
	cout << "YOU DON'T HAVE ENOUGH EXP!" << "\n";
	}
}

void Player::updateStats()
{
	this->expNext = static_cast<int>(
		(50 / 3) * ((pow(level, 3)
			- 6 * pow(level, 2))
			+ 17 * level - 12)) + 100;

	this->healthMax = (this->vitality * 5) + (this->attack) + this->level * 5;
	this->staminaMax = this->vitality + (this->attack / 2) + (this->dexterity / 3);
	this->stamina = this->staminaMax;
	this->damageMin = this->attack;
	this->damageMax = this->attack + 2;
	this->mind = this->mind + 2;
	this->willpower = this->willpower + 2;
	this->defense = this->dexterity + (this->willpower / 2);
	this->health = this->healthMax;

}


void Player::addToStats(int stat, int value)
{
	if (this->statPoints < value)
		cout << "NOT ENOUGH STAT POINTS!" << "\n";
	else
	{
		switch (stat)
		{
		case 0:
			this->attack += value;
			cout << "ATTACK WENT UP!" << "\n";
			
			break;

		case 1:
			this->vitality += value;
			cout << "VITALITY WENT UP!" << "\n";

			break;

		case 2:
			this->dexterity += value;
			cout << "DEXTERITY WENT UP!" << "\n";

			break;

		case 3:
			this->mind += value;
			cout << "MIND WENT UP!" << "\n";

			break;

		case 4:
			this->willpower += value;
			cout << "WILLPOWER WENT UP!" << "\n";

			break;

		default:
			cout << "NO EXISTING STAT!" << "\n";
			break;
		}

		this->statPoints -= value;
		this->updateStats();
	}
}

void Player::equipItem(unsigned index)
{
	if (index < 0 || index >= this->backpack.size())
	{
		cout << "ITEM HASN'T BEEN SELECTED YET!" << "\n\n";
	}
	else
	{
		Weapon* w = nullptr;
		w = dynamic_cast<Weapon*>(&this->backpack[index]);

		Armour* a = nullptr;
		a = dynamic_cast<Armour*>(&this->backpack[index]);

		//Is weapon
		if (w != nullptr)
		{
			if (this->weapon.getRarity() >= 0)
				this->backpack.addItem(this->weapon);
			this->weapon = *w;
			this->backpack.removeItem(index);
		}
		else if (a != nullptr)
		{
			switch (a->getType())
			{
			case armourType::HEAD:
				if (this->armour_head.getRarity() >= 0)
					this->backpack.addItem(this->armour_head);
				this->armour_head = *a;
				this->backpack.removeItem(index);
				break;
			case armourType::CHEST:
				if (this->armour_chest.getRarity() >= 0)
					this->backpack.addItem(this->armour_chest);
				this->armour_chest = *a;
				this->backpack.removeItem(index);
				break;
			case armourType::ARMS:
				if (this->armour_arms.getRarity() >= 0)
					this->backpack.addItem(this->armour_arms);
				this->armour_arms = *a;
				this->backpack.removeItem(index);
				break;
			case armourType::LEGS:
				if (this->armour_legs.getRarity() >= 0)
					this->backpack.addItem(this->armour_legs);
				this->armour_legs = *a;
				this->backpack.removeItem(index);
				break;
			default:
				cout << "NOT VALID ARMOUR TYPE!" << "\n\n";
				break;
			}
		}
		else
		{
			cout << "ITEM IS NOT ARMOR OR WEAPON!";
		}
	}
}

void Player::removeItem(const int index)
{
	if (index < 0 || index >= this->backpack.size())
		cout << "NOT POSSIBLE TO REMOVE ITEM!" << "\n\n";
	else
	{
		this->backpack.removeItem(index);
	}
}

const Item& Player::getItem(const int index)
{
	if (index < 0 || index >= this->backpack.size())
	{
		cout << "CANNOT REMOVE ITEM!" << "\n\n";
		throw("ERROR OUT OF BOUNDS, GETITEM CHARACTER");
	}

	return this->backpack[index];
}

void Player::takeDamage(const int damage)
{
	this->health -= damage;

	if (this->health <= 0)
	{
		this->health = 0;
	}
}