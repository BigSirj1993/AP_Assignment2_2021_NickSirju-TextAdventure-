#include "Game.h"








// Update: Today

// The puzzle questions are showing up but not the choices for the questions
// Inputs the choice of answer but can't see the answers for the questions
// Always considered as wrong answer
// Still can't exit out of the store without having it crash on me // Fixed
// Tip: Apply breakpoints in enemy.cpp in the same way we fixed the store exit 
// Tip: It's in enemy.cpp
// Update: Enemy health back to normal but damage output still too high
// Back to exception on 503




int main()
{

	srand(time(NULL));
	


	Game game;
	game.initGame();


	while (game.getRunning())
	{
		game.gameMenu();
	}


	return 0;
}