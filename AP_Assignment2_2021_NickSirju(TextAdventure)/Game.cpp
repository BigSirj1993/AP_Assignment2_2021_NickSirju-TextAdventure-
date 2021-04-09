#include "Game.h"

//Done

Game::Game()
{
	choice = 0;
	running = true;
	activePlayer = 0;
	fileName = "player.txt";

}


Game::~Game()
{


}

/*void Game::defaultPlayer()
{

}*/

// Functions
void Game::initGame()
{
	ifstream in;
	in.open("player.txt");

	Weapon::initName();
	Armour::initNames();

	if (in.is_open())
		this->loadPlayer();
	else
	{
		createNewPlayer();
		this->savePlayer();
	}

	in.close();

}


void Game::gameMenu()
{
	cout << "Enter to continue..." << "\n";
	cin.get();
	system("CLS");

	if (this->player[activePlayer].isAlive())
	{
		if (this->player[activePlayer].getExp() >=
			this->player[activePlayer].getExpNext())
		{
			cout << "Level Up Available! \n\n";
		}

		cout << "= Main Menu =" << "\n" << "\n";

		cout << "= Current Player: " <<
			this->player[activePlayer].getName() << "Nr:" <<
			this->activePlayer + 1 << "/" << this->player.size() <<
			" =" << "\n" << "\n";

		cout << "0: Quit" << "\n";
		cout << "1: Travel" << "\n";
		cout << "2: Level Up" << "\n";
		cout << "3: Rest" << "\n";
		cout << "4: Player Sheet" << "\n";
		cout << "5: Create a New Player" << "\n";
		cout << "6: Select Player" << "\n";
		cout << "7: Save Player" << "\n";
		cout << "8: Load Player" << "\n";

		cout << "\n";

		cout << "\n" << "Choice: ";
		cin >> this->choice;

		while (cin.fail() || this->choice > 9)
		{
			cout << "Wrong Input!" << "\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "\n" << "Choice (0 - 8):";
			cin >> this->choice;
		}

		cin.ignore(100, '\n');
		cout << "\n";

		switch (this->choice)
		{
		case 0: //Quit
			running = false;
			this->savePlayer();

			break;

		case 1: //Walking
			walk();

			break;

		case 2: //Level up
			this->levelUpPlayer();

			break;


		case 3: // Rest
			rest();

			break;

		case 4: // Player Sheet
			this->playerMenu();

			break;

		case 5: // Create New Player
			createNewPlayer();
			savePlayer();

			break;

		case 6: // Select Player
			selectPlayer();

			break;

		case 7: // Save Player
			savePlayer();

			break;

		case 8: // Load Player
			loadPlayer();

			break;

		default:
			break;


		}

	}

	else
	{
		cout << "= You Dead! Do You Wish To Load? =" << "\n" << "\n";
		cout << "0: Yes || 1: No" << "\n";
		cin >> this->choice;

		while (cin.fail() || this->choice < 0 || this->choice > 1)
		{
			cout << "Wrong Input!" << "\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "0: Yes, 1: No" << "\n";
			cin >> this->choice;

		}

		cin.ignore(100, '\n');
		cout << "\n";

		if (this->choice == 0)
			this->loadPlayer();
		else
			running = false;
	}
}

void Game::createNewPlayer()
{
	string name = " ";
	cout << "Player Name: ";
	getline(cin, name);

	for (size_t i = 0; i < this->player.size(); i++)
	{
		while (name == this->player[i].getName())
		{
			cout << "Error! Player Already Exists!" << "\n";
			cout << "Player Name: ";
			getline(cin, name);
		}

	}

	player.push_back(Player());
	activePlayer = player.size() - 1;
	player[activePlayer].initialize(name);

}

void Game::levelUpPlayer()
{
	this->player[activePlayer].levelUp();

	if (this->player[activePlayer].getStatPoints() > 0)
	{
		cout << "You have available Stat Points to use!" << "\n";

		cout << "Stats to increase: " << "\n";
		cout << "0: Attack " << "\n";
		cout << "1: Vitality " << "\n";
		cout << "2: Dexterity " << "\n";
		cout << "3: Mind " << "\n";
		cout << "4: Willpower" << "\n";

		cin >> this->choice;

		while (cin.fail() || this->choice > 3)
		{
			cout << "Wrong Input!" << "\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "Stats to increase: " << "\n";
			cin >> this->choice;
		}

		cin.ignore(100, '\n');
		cout << "\n";

		switch (this->choice)
		{
		case 0: // Attack
			this->player[activePlayer].addToStats(0, 1);
			break;

		case 1: // Vitality
			this->player[activePlayer].addToStats(1, 1);
			break;

		case 2: // Dexterity
			this->player[activePlayer].addToStats(2, 1);
			break;

		case 3: // Mind
			this->player[activePlayer].addToStats(3, 1);
			break;

		case 4: // Willpower
			this->player[activePlayer].addToStats(4, 1);
			break;


		default:
			break;
		}
	}
}

void Game::playerMenu()
{
	do
	{
		system("CLS");
		cout << gui::game_menu_title("Player Menu");

		cout << gui::game_menu_divider();

		player[activePlayer].printStats();

		cout << gui::game_menu_divider();

		cout << "= Menu =" << "\n";
		cout << gui::game_menu_item(0, "Back");
		cout << gui::game_menu_item(1, "Print Backpack");
		cout << gui::game_menu_item(2, "Equip Item");
		cout << "\n";
		cout << "Choice: ";

		cin >> this->choice;

		while (cin.fail() || this->choice < 0 || this->choice > 2)
		{
			cout << "Wrong Input!" << "\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "= Menu =" << "\n";
			cout << "0: Back" << "\n";
			cout << "1: Print Backpack" << "\n";
			cout << "2: Equip Item" << "\n";
			cout << "\n";
			cout << "Choice: ";
			cin >> this->choice;
		}

		cin.ignore(100, '\n');
		cout << "\n";

		switch (this->choice)
		{
		case 1:
			cout << this->player[this->activePlayer].getBackPackAsString();
			break;

		case 2:
			cout << this->player[this->activePlayer].getBackPackAsString();

			cout << "Item Index: ";
			cin >> this->choice;

			while (cin.fail() || this->choice < 0 || this->choice >= this->player[this->activePlayer].getBackPackSize())
			{
				cout << "Wrong Input!" << "\n";
				cin.clear();
				cin.ignore(100, '\n');

				cout << "Item Index: ";
				cin >> this->choice;
			}

			cin.ignore(100, '\n');
			cout << "\n";

			this->player[this->activePlayer].equipItem(this->choice);

			break;

		default:
			break;

		}

		if (this->choice > 0)
		{
			cout << "Enter to proceed... " << "\n";
			cin.get();
		}

	} while (this->choice > 0);

}

void Game::savePlayer()
{
	ofstream outFile(fileName);

	if (outFile.is_open())
	{
		for (size_t i = 0; i < this->player.size(); i++)
		{
			outFile << this->player[i].getAsString() << "\n";
			outFile << this->player[i].getBackPackAsStringSave() << "\n";
		}
	}

	outFile.close();
}

void Game::loadPlayer()
{
	ifstream inFile(fileName);

	this->player.clear();

	string name = "";
	int distanceWalked = 0;
	int gold = 0;
	int level = 0;
	int exp = 0;
	int attack = 0;
	int vitality = 0;
	int dexterity = 0;
	int mind = 0;
	int willpower = 0;
	int health = 0;
	int stamina = 0;
	int statPoints = 0;

	//Item
	int itemType = 0;
	int defense = 0;
	int type = 0;
	int damageMin = 0;
	int damageMax = 0;
	//Name
	//Level
	int buyValue = 0;
	int sellValue = 0;
	int rarity = 0;

	BackPack tempItems;

	string line = "";
	stringstream str;
	

	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			str.str(line);
			str >> name;
			str >> distanceWalked;
			str >> gold;
			str >> level;
			str >> exp;
			str >> attack;
			str >> vitality;
			str >> dexterity;
			str >> mind;
			str >> willpower;
			str >> health;
			str >> stamina;
			str >> statPoints;

			// Create Player
			Player temp(name, distanceWalked, gold, level, exp, attack, vitality, dexterity, mind, willpower, health, stamina, statPoints);


			//Weapon
			str >> itemType >> name >> level >> rarity >> buyValue >> sellValue >> damageMin >> damageMax;

			Weapon weapon(damageMin, damageMax, name, level, buyValue, sellValue, rarity);


			// Armour head
			str >> itemType >> name >> level >> rarity >> buyValue >> sellValue >> defense >> type;

			Armour armour_head(type, defense, name, level, buyValue, sellValue, rarity);

			// Armour Chest
			str >> itemType >> name >> level >> rarity >> buyValue >> sellValue >> defense >> type;

			Armour armour_chest(type, defense, name, level, buyValue, sellValue, rarity);

			// Armour Arms
			str >> itemType >> name >> level >> rarity >> buyValue >> sellValue >> defense >> type;

			Armour armour_arms(type, defense, name, level, buyValue, sellValue, rarity);

			// Armour Legs
			str >> itemType >> name >> level >> rarity >> buyValue >> sellValue >> defense >> type;

			Armour armour_legs(type, defense, name, level, buyValue, sellValue, rarity);


			temp.setWeapon(weapon);
			temp.setArmourHead(armour_head);
			temp.setArmourChest(armour_chest);
			temp.setArmourArms(armour_arms);
			temp.setArmourLegs(armour_legs);

			// Add BackPack Items
			str.clear();
			line.clear();
			getline(inFile, line);

			str.str(line);

			while (str >> itemType >> name >> level >> rarity >> buyValue >> sellValue >> damageMin >> damageMax)
			{
				temp.addItem(Weapon(damageMin, damageMax, name, level, buyValue, sellValue, rarity));

			}
		
			str.clear();
			line.clear();
			getline(inFile, line);

			str.str(line);

			while (str >> itemType >> name >> level >> rarity >> buyValue >> sellValue >> defense >> type)
			{
				temp.addItem(Armour(type, defense, name, level, buyValue, sellValue, rarity));
			}
			
			
			this->player.push_back(Player(temp));

			cout << "Player" << temp.getName() << "loaded!\n";

			str.clear();
		}
		

	}

	inFile.close();

	if (this->player.size() <= 0)
	{
		cout << "Error! No player loaded or empty file!";
		player.push_back(Player());
		activePlayer = player.size() - 1;
		player[activePlayer].initialize(name);
	}
	
}

void Game::selectPlayer()
{
	cout << "Select Player: " << "\n\n";

	for (size_t i = 0; i < this->player.size(); i++)
	{
		cout << "Index: " << i << " = " << this->player[i].getName() << "Level: " << this->player[i].getLevel() << "\n";
	}

	cout << "\n";

	cout << "Choice: ";

	cin >> this->choice;

	while (cin.fail() || this->choice >= this->player.size() || this->choice < 0)
	{
		cout << "Wrong Input!" << "\n";
		cin.clear();
		cin.ignore(100, '\n');

		cout << "Select Player: " << "\n";
		cin >> this->choice;
	}

	cin.ignore(100, '\n');
	cout << "\n";

	this->activePlayer = this->choice;
	cout << this->player[this->activePlayer].getName() << " is chosen!" << "\n\n";
}

void Game::walk()
{
	this->player[activePlayer].walked();
	Event ev;
	ev.activateEvent(this->player[activePlayer], this->enemies);
}

void Game::rest()
{
	int restCost = this->player[this->activePlayer].getMaxHealth() - this->player[this->activePlayer].getHealth();
	cout << "= Rest =" << "\n\n";
	cout << "Resting costs you: " << restCost << "\n";
	cout << "Your Gold: " << this->player[this->activePlayer].getGold() << "\n";
	cout << "Health: " << this->player[this->activePlayer].getHealth() << " / " << this->player[this->activePlayer].getMaxHealth() << "\n\n";

	if (this->player[this->activePlayer].getGold() < restCost)
	{
		cout << "You Don't Have Enough Gold. Our Apologies." << "\n\n";
	}
	else if (this->player[this->activePlayer].getHealth() >= this->player[this->activePlayer].getMaxHealth())
	{
		cout << "What Do You Need To Rest For? You're At Full Health!" << "\n\n";
	}
	else
	{
		cout << "\n\n Rest? (0) Yes, (1) No..." << "\n\n";

		cin >> this->choice;

		while (cin.fail() || this->choice < 0 || this->choice > 1)
		{
			cout << "Wrong Input!" << "\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "\n\n Rest? (0) Yes, (1) No..." << "\n\n";
			cin >> this->choice;
		}

		cin.ignore(100, '\n');
		cout << "\n";

		if (this->choice == 0)
		{
			this->player[this->activePlayer].resetHealth();
			this->player[this->activePlayer].payGold(restCost);
			cout << "You're Rested and Refreshed!" << "\n\n";
		}
		else
		{
			cout << "You Decided Not To Rest!" << "\n\n";
		}
	}
}