#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Player.h"
#include "Enemy.h"
using namespace std;

class Level
{
public:
	Level();
	~Level();

	void load(string fileName, Player* &player);
	void print(Player* &player);

	void movePlayer(char input, Player* &player);
	void updateEnemies(Player* &player);

	//getters
	char getTile(int x, int y);
	//gets AI move command
	
	//setters
	void setTile(int x, int y, char tile);

private:
	vector<string> _levelData;
	vector<Enemy> _enemies;
	
	void processPlayerMove(Player* &player, int targetX, int targetY);
	void processEnemyMove(Player* &player, int enemyIndex, int targetX, int targetY);
	void battleMonster(Player* &player, int targetX, int targetY);
};

