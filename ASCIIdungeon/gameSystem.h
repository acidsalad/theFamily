#pragma once
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include <string>

using namespace std;

class gameSystem
{
public:
	gameSystem();

	//initializes game
	void playGame();
	//moves player and processes move
	void playerMove();

	//clears the screen
	void ClearScreen();

private:
	Level _level;
	Player* _player = new Player;
};

