#pragma once
#include "Player.h"
#include "Level.h"
#include "Enemy.h"
#include <string>

using namespace std;

class gameSystem
{
public:
	gameSystem(string levelFileName);
	~gameSystem();

	void playGame();
	void playerMove();

private:
	Level _level;
	Player* _player = new Player;
};

