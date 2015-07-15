#include "gameSystem.h"
#include <conio.h>


gameSystem::gameSystem(string levelFileName)
{
	_player->init(20, 5, 1, 0, 4, 50);

	_level.load(levelFileName, _player);
	
}


void gameSystem::playGame()
{
	bool isDone = false;
	while (!isDone)
	{
		_level.print(_player);
		playerMove();
		
	}
}

void gameSystem::playerMove() {
	char input;
	//printf("Enter a move command: \n");
	input = _getch();

	_level.movePlayer(input, _player);
	_level.updateEnemies(_player);
	}

gameSystem::~gameSystem()
{
}
