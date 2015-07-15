#include "Level.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

Level::Level()
{

}


Level::~Level()
{

}

void Level::load(string fileName, Player* &player) {
	//level loader
	ifstream file;
	file.open(fileName);
	if (file.fail()) {
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}
	string line;
	while (getline(file, line))
	{
		_levelData.push_back(line);
	}

	file.close();

	//Process the level
	char tile;

	for (int i = 0; i < _levelData.size(); i++) {
		for (int j = 0; j < _levelData[i].size(); j++) {
			tile = _levelData[i][j];
			switch (tile) {
			case '@':
				player->setPosition(j, i);
				break;
			case 'D':
				break;
			case 'T':
				break; 
			case '!': //Exclamation Enemy!
				_enemies.push_back(Enemy("Exclamation Guy", tile, 1, 2, 4, 50, 10));
				_enemies.back().setPosition(j, i);
				break;
			case 'P': // DANGEROUS PUSSY!
				_enemies.push_back(Enemy("DANGEROUS PUSSY", tile, 2, 3, 5, 100, 5));
				_enemies.back().setPosition(j, i);
				break;
			case '0': // DANGEROUS VAGINA!
				_enemies.push_back(Enemy("Dangerous Vagina", tile, 4, 20, 20, 500, 3));
				_enemies.back().setPosition(j, i);
				break;
			}
		}
	}

}

void Level::print(Player* &player)
{
	cout << string(100, '\n');

	printf("%s\tPlayer Name: %s\n", _levelData[0].c_str(), player->getName().c_str());
	printf("%s\tLevel: %d\n", _levelData[1].c_str(), player->getLevel());
	printf("%s\tHP: %d\n", _levelData[2].c_str(), player->get_hp());
	printf("%s\tPP: %d\n", _levelData[3].c_str(), player->get_pp());
	printf("%s\txp: %d\n", _levelData[4].c_str(), player->getExp());
	printf("%s\tTo Next Level: %d\n", _levelData[5].c_str(), player->get_tNL());
	
	for (int i = 6; i < _levelData.size(); i++)
	{
		printf("%s\n", _levelData[i].c_str());
	}
	cout << endl;
}

void Level::movePlayer(char input, Player* &player)
{
	int playerX, playerY;
	player->getPosition(playerX, playerY);

	char moveTile;

	switch (input) {
	case 'w':
	case 'W':
		processPlayerMove(player, playerX, playerY - 1);
		break;
	case 's':
	case 'S':
		processPlayerMove(player, playerX, playerY + 1);
		break;
	case 'a':
	case 'A':
		processPlayerMove(player, playerX - 1, playerY);
		break;
	case 'd':
	case 'D':
		processPlayerMove(player, playerX + 1, playerY);
		break;
	default:
		break;
	}
}
	//void Level::updateMonsters(Player* &player)
	//{
		//for (int i = 0, i < _enemies.size(); i++) {

		//}
	//}


void Level::processPlayerMove(Player* &player, int targetX, int targetY)
{
	int playerX, playerY;
	player->getPosition(playerX, playerY);

	char moveTile = getTile(targetX, targetY);

	switch (moveTile)
	{
	case '#': printf("That is a wall, dumbass.\n");
		break;
	case '.': player->setPosition(targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');
		break;
	default:
		battleMonster(player, targetX, targetY);
		break;
	}
}

	char Level::getTile(int x, int y) {
		return _levelData[y][x];
	}

	void Level::setTile(int x, int y, char tile)
	{
		_levelData[y][x] = tile;
	}

void Level::processEnemyMove(Player* &player, int enemyIndex, int targetX, int targetY) {
	int playerX, playerY;
	player->getPosition(playerX, playerY);
	int enemyX, enemyY;
	_enemies[enemyIndex].getPosition(enemyX, enemyY);

	char moveTile = getTile(targetX, targetY);

	switch (moveTile)
	{
	case '#':
		break;
	case '.': _enemies[enemyIndex].setPosition(targetX, targetY);
		setTile(enemyX, enemyY, '.');
		setTile(targetX, targetY, _enemies[enemyIndex].getAvatar());
		break;
	default:

		break;
	}
}

	void Level::battleMonster(Player* &player, int targetX, int targetY)
	{
		int enemyX, enemyY;
		int playerX, playerY;
		player->getPosition(playerX, playerY);

		int attack;
		int attackResult;
		string playerName = player->getName();
		
		for (int i = 0; i < _enemies.size(); i++) {
			_enemies[i].getPosition(enemyX, enemyY);
			if (targetX == enemyX && targetY == enemyY)
			{
				int enemyDefense = _enemies[i].getDefense();
				string enemyName = _enemies[i].getName();
				//WE MUST DO BATTLE
				attack = player->attack();

				attackResult = _enemies[i].takeDamage(attack);
				printf("%s does damage of %d!\n", playerName.c_str(), attack - enemyDefense);
				if (attackResult != 0 && attackResult != -1) {
					print(player);
					printf("%s met a bitter end.\n", enemyName.c_str());
					system("PAUSE");
					player->addExperience(attackResult);

					_enemies[i] = _enemies.back();
					_enemies.pop_back();
					i--;
					setTile(targetX, targetY, '.');
					return;
				}
				else if (attackResult == -1) {
					printf("You didn't even dent %s.\n", enemyName.c_str());
				}
				//monster fights now!
				attack = _enemies[i].attack();
				attackResult = player->takeDamage(attack);
				printf("%s does damage of %d\n", enemyName.c_str(), attack);
				
				if (attackResult != 0) {
					setTile(playerX, playerY, '.');
					print(player);
					printf("%s met a bitter end.", playerName.c_str());
					system("PAUSE");
					player->addExperience(attackResult);

					exit(1);
				}
				system("PAUSE");
				return;
			}
		}
	}

void Level::updateEnemies(Player* &player) {
	char aimove;
	int enemyX, enemyY;
	int playerX, playerY;
	player->getPosition(playerX, playerY);


	for (int i = 0; i < _enemies.size(); i++) {
		aimove = _enemies[i].getMove(playerX, playerY);
		_enemies[i].getPosition(enemyX, enemyY);
		switch (aimove) {
		case 'w':
			processEnemyMove(player, i, enemyX, enemyY + 1);
				break;
		case 's':
			processEnemyMove(player, i, enemyX, enemyY - 1);
			break;
		case 'a':
			processEnemyMove(player, i, enemyX + 1, enemyY);
			break;
		case 'd':
			processEnemyMove(player, i, enemyX - 1, enemyY);
			break;
		}
	}
}
