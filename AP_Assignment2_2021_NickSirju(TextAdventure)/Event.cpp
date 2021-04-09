#include "Event.h"

//Done


int Event::numberOfEvents = 4;

using namespace std;

Event::Event()
{


}

Event::~Event()
{


}

void Event::activateEvent(Player& player, dArr<Enemy>& enemies)
{
	int i = rand() % Event::numberOfEvents;

	switch (i)
	{
	case 0:
		// Enemy encounter
		this->enemyEncounter(player, enemies);
		break;
	case 1:
		//Puzzle
		this->puzzlieEncounter(player);
		break;
	case 2:
		//Shop
		this->storeEncounter(player);
		break;
	case 3:
		//Boss
		cout << "Boss not ready" << endl;
		break;

	default:
		break;
		
	}

	
}

void Event::storeEncounter(Player& player)
{
	int choice = 0;
	bool shopping = true;
	BackPack ownerItems;
	string items;


	// init owner items
	int numberOFItems = rand() % 20 + 10;
	bool coinToss = false;

	for (size_t i = 0; i < numberOFItems; i++)
	{
		coinToss = rand() % 2;

		if (coinToss > 0)
			ownerItems.addItem(Weapon(player.getLevel() + rand() % 5, rand() % 4));
		else
			ownerItems.addItem(Armour(player.getLevel() + rand() % 5, rand() % 4));
	}

	while (shopping)
	{
		system("CLS");

		cout << " = Store Menu = " << "\n\n";

		cout << "0: Exit " << "\n";
		cout << "1: Buy " << "\n";
		cout << "2: Sell " << "\n";

		cout << "Choice: ";
		cin >> choice;

		while (cin.fail() || choice > 3 || choice < 0)
		{
			system("CLS");

			cout << "Wrong choice!" << "\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "= Store Menu =" << "\n\n";

			cout << "0: Exit" << "\n";
			cout << "1: Buy" << "\n";
			cout << "2: Sell" << "\n";

			cout << "Choice: ";
			cin >> choice;

		}

		cin.ignore(100, '\n');
		cout << "\n";

		//Store
		switch (choice)
		{
		case 0: // Exit
			shopping = false;
			break;

		case 1: // Buy

			cout << "= Buy Menu =" << "\n\n";

			cout << " - Gold:" << player.getGold() << "\n\n";

			items.clear();

			for (size_t i = 0; i < ownerItems.size(); i++)
			{
				items += to_string(i) + ": " + ownerItems[i].toString() + "\n - Price: " + to_string(ownerItems[i].getBuyValue()) + "\n";
			}

			cout << items << "\n";

			cout << "Gold: " << player.getGold() << "\n";
			cout << "Choice of item (-1 to cancel):";

			cin >> choice;

			while (cin.fail() || choice > ownerItems.size() || choice < -1)
			{
				system("CLS");

				cout << "Wrong choice" << "\n";
				cin.clear();
				cin.ignore(100, '\n');

				cout << "Gold: " << player.getGold() << "\n";
				cout << "Choice of item (-1 to cancel): ";
				cin >> choice;

			}

			cin.ignore(100, '\n');
			cout << "\n";

			if (choice == -1)
			{
				cout << "Negated..." << "\n";
			}
			else if (player.getGold() >= ownerItems[choice].getBuyValue())
			{
				player.payGold(ownerItems[choice].getBuyValue());
				player.addItem(ownerItems[choice]);

				
				cout << "Purchased Item " << ownerItems[choice].getName() << " - " << ownerItems[choice].getBuyValue() << "\n";
				
				ownerItems.removeItem(choice);
			
			}
			else
			{
				cout << "Not enough gold. Can't buy!" << "\n";
			}

			break;

		case 2: //Sell

			cout << player.getBackPackAsString(true) << "\n";

			cout << "= Sell Menu =" << "\n\n";

			cout << " - Gold: " << player.getGold() << "\n";

			if (player.getBackPackSize() > 0)
			{
				cout << "Gold: " << player.getGold() << "\n";
				cout << "Choice of Item (-1 to cancel): ";

				cin >> choice;

				while (cin.fail() || choice > player.getBackPackSize() || choice < -1)
				{
					system("CLS");

					cout << "Wrong Input!" << "\n";
					cin.clear();
					cin.ignore(100, '\n');

					cout << "Gold: " << player.getGold() << "\n";
					cout << "Choice of Item(-1 to cancel): ";
					cin >> choice;
				}

				cin.ignore(100, '\n');
				cout << "\n";

				if (choice == -1)
				{
					cout << "Negated..." << "\n";
				}
				else
				{
					player.gainGold(player.getItem(choice).getSellValue());
					
					cout << "Item Sold! " << "\n";
					cout << "Gold Earned: " << player.getItem(choice).getSellValue() << "\n\n";
					player.removeItem(choice);
				}
			}
			else
			{
				cout << "Backpack Empty..." << "\n";
			}

			break;

		default:
			break;
		}
		
		

		cout << "You decided to leave the store..." << "\n\n";
		cin.get();
	}

	cout << "Press Enter to continue" << "\n\n";
	cin.get();
	// have to get reference to game menu

	
}

void Event::enemyEncounter(Player& player, dArr<Enemy>& enemies)
{
	bool playerMove = false;
	int choice = 0;

	// Coin toss for turn

	int coinToss = rand() % 2 + 1;

	if (coinToss == 1)
		playerMove = true;
	else
		playerMove = false;

	//Ending conditions
	bool escape = false;
	bool playerBeaten = false;
	bool enemiesBeaten = false;

	//Enemies
	int numberOfEnemies = rand() % 5 + 1;

	for (size_t i = 0; i < numberOfEnemies; i++)
	{
		enemies.push(Enemy(player.getLevel() + rand() % 3));
	}

	// Battle stats

	int damage = 0;
	int gainExp = 0;
	int gainGold = 0;
	int playerTotal = 0;
	int enemyTotal = 0;
	int combatTotal = 0;
	int combatRollPlayer = 0;
	int combatRollEnemy = 0;

	while (!escape && !playerBeaten && !enemiesBeaten)
	{
		if (playerMove && !playerBeaten)
		{

			cout << "= Player Turn =" << "\n\n";
			cout << "Continue..." << "\n\n";
			cin.get();
			system("CLS");

			cout << "= Battle Menu =" << "\n\n";
			cout << "Health: " << player.getHealth() << " / " << player.getMaxHealth() << "\n\n";
		
			cout << "0: Escape" << "\n";
			cout << "1: Attack" << "\n";
			cout << "2: Defend" << "\n";
			cout << "3: Use Item" << "\n";
			cout << "\n";

			cout << "Choice: ";
			
			cin >> choice;
			

			while (cin.fail() || choice > 3 || choice < 0)
			{
				system("CLS");

				cout << "Wrong Input!" << "\n";
				cin.clear();
				cin.ignore(100, '\n');

				cout << "= Battle Menu =" << "\n\n";

				cout << "0: Escape" << "\n";
				cout << "1: Attack" << "\n";
				cout << "2: Defend" << "\n";
				cout << "3: Use Item" << "\n";
				cout << "\n";

				cout << "Choice: ";
				cin >> choice;
			}

			cin.ignore(100, '\n');
			cout << "\n";

			//Actions
			switch (choice)
			{
			case 0: // Escape
				escape = true;
				break;

			case 1: // Attack

				//Enemy Selection
				cout << "Select enemy" << "\n\n";

				for (size_t i = 0; i < enemies.size(); i++)
				{
					cout << i << ": "
						<< "Level: " << enemies[i].getLevel() << " - " <<
						"Health: " << enemies[i].getHealth() << "/" << enemies[i].getHealthMax() << " - " <<
						"Defense: " << enemies[i].getDefense() << " - " <<
						"Aim: " << enemies[i].getAim() << " - " <<
						"Damage: " << enemies[i].getDamageMin() << " - " << enemies[i].getDamageMax() <<
						"\n";
				}

				cout << "\n";
				cout << "Choice: ";

				cin >> choice;

				while (cin.fail() || choice >= enemies.size() || choice < 0)
				{
					cout << "Wrong Input!" << "\n";
					cin.clear();
					cin.ignore(100, '\n');

					cout << "Choose enemy: " << "\n\n";
					cout << "Choice: ";
					cin >> choice;

				}

				cin.ignore(100, '\n');
				cout << "\n";

				//Attack roll
				combatTotal = enemies[choice].getDefense() + player.getAim();
				enemyTotal = enemies[choice].getDefense() / (double)combatTotal * 100;
				playerTotal = player.getAim() / (double)combatTotal * 100;
				combatRollPlayer = rand() % (playerTotal + 1); // Expection thrown
				combatRollEnemy = rand() % (enemyTotal + 1);

				cout << "Combat Total:" << combatTotal << "\n";
				cout << "Enemy Percent:" << enemyTotal << "\n";
				cout << "Player Percent:" << playerTotal << "\n";
				cout << "Player Roll:" << combatRollPlayer << "\n";
				cout << "Enemy Roll:" << combatRollEnemy << "\n";

				if (combatRollPlayer > combatRollEnemy) // Hit
				{

					cout << "You Struck The Enemy!" << "\n\n";

					damage = player.getDamage();
					enemies[choice].takeDamage(damage);

					cout << "Damage: " << damage << "!" << "\n\n";

					if (!enemies[choice].isAlive())
					{

						cout << "Enemy Slain!" << "\n\n";
						gainExp = enemies[choice].getExp();
						player.gainExp(gainExp);
						gainGold = rand() % enemies[choice].getLevel() * 10 + 1;
						player.gainGold(gainGold);
						cout << "Exp Gained:" << gainExp << "\n";
						cout << "Gold Gained:" << gainGold << "\n\n";

						//Item roll
						int roll = rand() % 100 + 1;
						int rarity = -1;

						if (roll > 20)
						{
							rarity = 0; // Common Item

							roll = rand() % 100 + 1;
							if (roll > 30)
							{
								rarity = 1; // Uncommon Item

								roll = rand() % 100 + 1;
								if (roll > 50)
								{
									rarity = 2; // Rare Item


									roll = rand() % 100 + 1;
									if (roll > 70)

										rarity = 3; // Legendary Item


									roll = rand() % 100 + 1;
									if (roll > 90)
									{
										rarity = 4; // Epic/Mythical Item
									}

								}
							}
						}

						if (roll >= 0)
						{
							roll = rand() % 100 + 1;

							if (roll > 50)
							{
								Weapon tempWeapon(player.getLevel(), rarity);
								player.addItem(tempWeapon);
								cout << "Weapon Dropped!" << "\n";
							}
							else
							{
								Armour tempArmour(player.getLevel(), rarity);
								player.addItem(tempArmour);
								cout << "Armour Drop!" << "\n";
							}

						}

						enemies.remove(choice);
					}



				}
				else // Miss
				{
					cout << "Missed! \n\n";

				}
				break;

				case 2: // Defend

					break;

				case 3: // Use Item

					break;

				default:
					break;
			}

			// Ending turn
			playerMove = false;
			
		}
		else if (!playerMove && !playerBeaten && !escape && !enemiesBeaten)
		{
		cout << "= Enemy Turn =" << "\n";

		cout << "Continue..." << "\n\n";
		cin.get();
		system("CLS");

		//Enemy Attack
		for (size_t i = 0; i < enemies.size(); i++)
		{

			cout << "Continue..." << "\n\n";
			cin.get();
			system("CLS");

			cout << "Enemy: " << i << "\n\n";

			//Attack Roll
			combatTotal = enemies[i].getDefense() + (player.getDefense() + player.getAddedDefense());
			enemyTotal = enemies[i].getDefense() + (double)combatTotal * 100;
			playerTotal = (player.getDefense() + player.getAddedDefense()) / (double)combatTotal * 100;
			combatRollPlayer = rand() % playerTotal + 1; // Exception get handled
			combatRollEnemy = rand() % enemyTotal + 1;

			cout << "Combat Total: " << combatTotal << "\n";
			cout << "Enemy Percent: " << enemyTotal << "\n";
			cout << "Player Percent: " << playerTotal << "\n";
			cout << "Player Roll: " << combatRollPlayer << "\n";
			cout << "Enemy Roll: " << combatRollEnemy << "\n";

			if (combatRollPlayer < combatRollEnemy) // Hit
			{
				cout << "The Enemy Struck You! " << "\n\n";

				damage = enemies[i].getDamage();
				player.takeDamage(damage);

				cout << "Damage: " << damage << "!" << "\n";
				cout << "Health: " << player.getHealth() << " / " << player.getMaxHealth() << "\n\n";

				if (!player.isAlive())
				{
					cout << "You Dead!" << "\n\n";
					playerBeaten = true;
				}



			}

			else // Miss
			{
				cout << "Enemy Missed! \n\n";
			}

		}
		// End turn
		playerMove = true;

		}
		//Conditions
		if (!player.isAlive())
		{
			playerBeaten = true;
		}
		else if (enemies.size() <= 0)
		{
			enemiesBeaten = true;
		}
	}
}

void Event::puzzlieEncounter(Player& player)
{
	bool completed = false;
	int playerAnswer = 0;
	int chances = 3;
	int gainExp = (chances * player.getLevel() * (rand() % 10 + 1));
	int gainGold = (chances * player.getLevel() * (rand() % 10 + 1));

	Puzzle puzzle1("Puzzles/1.txt");
	Puzzle puzzle2("Puzzles/2.txt");
	Puzzle puzzle3("Puzzles/3.txt");
	Puzzle puzzle4("Puzzles/4.txt");
	Puzzle puzzle5("Puzzles/5.txt");

	while (!completed && chances > 0)
	{
		cout << "Chances: " << chances << "\n\n";
		chances--;
		cout << puzzle1.getAsString() << "\n";

		cout << "Your Answer: ";
		cin >> playerAnswer;

		while (cin.fail())
		{
			cout << "Wrong Input!" << "\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "Your Answer: ";
			cin >> playerAnswer;


		}

		cin.ignore(100, '\n');
		cout << "\n";

		if (puzzle1.getRightAnswer() == playerAnswer)
		{
			completed = true;

			player.gainExp(gainExp);
			player.gainGold(gainGold); 
			cout << "You Gained " << gainExp << "Exp! " << "\n";
			cout << "You Gained " << gainGold << "Gold!" << "\n\n";
		}

	}
	
	if (completed)
	{
		cout << "Look At The Genius!" << "\n\n";
	}
	else
	{
		cout << "For Once, Use Your Brain!" << "\n\n";
	}
}

void Event::bossEncounter(Player& player, Boss& boss)
{
}
