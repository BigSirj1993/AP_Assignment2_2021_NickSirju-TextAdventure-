#pragma once

#include "STLINCLUDE.h"

#include "Event.h"

//Done

using namespace std;



class Game
{
	public:
		Game();
		virtual ~Game();

		// Operators 

		// Need Functions
		//void defaultPlayer(); // starting player
		void initGame(); // Init game
		void gameMenu(); // Game menu
		void createNewPlayer(); // New player
		void savePlayer(); // Can save player
		void loadPlayer(); // Can load player
		void levelUpPlayer();
		void playerMenu();
		void selectPlayer();
		void walk();
		void rest();



		// Need Accessors
		inline bool getRunning() const
		{
			return this->running;
		}

		

private:
	int choice; // Choice
	bool running; // Game is running

	// Character related
	int activePlayer; // Current player
	vector<Player> player;
	string fileName; 

	//Enemies
	dArr<Enemy> enemies;


};

