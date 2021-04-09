#pragma once

#include "STLINCLUDE.h"

#include "Player.h"
#include "Enemy.h"
#include "Puzzle.h"
#include "Boss.h"

// Done


class Event
{
private:

public:
	Event();
	virtual ~Event();
	void activateEvent(Player& player, dArr<Enemy>& enemies);
	
	//Events
	void storeEncounter(Player &player);
	void enemyEncounter(Player& player, dArr<Enemy>& enemies);
	void puzzlieEncounter(Player& player);
	void bossEncounter(Player& player, Boss & boss);


	//Statics
	static int numberOfEvents;


};
