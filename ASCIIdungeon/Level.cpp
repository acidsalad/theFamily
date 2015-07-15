#include "Level.h"
#include <iostream>
#include <string>
#include "Exclamation.h"
#include "DangerousPussy.h"
#include "DangerousVagina.h"
#include "YouAreHere.h"

using namespace std;

Level::Level()
{
	//Store the levels in a vector.
	_levels.push_back("level0.txt");
	_levels.push_back("level1.txt");
	_levels.push_back("level2.txt");
	//....
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
	if (fileName == "level0.txt" || fileName == "level2.txt")
	{
		while (getline(file, line))
		{
			_levelDataCutScene.push_back(line);
		}
	}
	else {
		while (getline(file, line))
		{
			_levelData.push_back(line);
		}
	}

	file.close();

	//Process the level
	char tile;
	if (_levelData.size() != 0)
	{
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
				case 'F':
					_NPCs.push_back(NPC('F'));
					_NPCs.back().setPosition(j, i);
					break;
				case '!': //Exclamation Enemy!
					_enemies.push_back(Exclamation());
					_enemies.back().setPosition(j, i);
					break;
				case 'P': // DANGEROUS PUSSY!
					_enemies.push_back(DangerousPussy());
					_enemies.back().setPosition(j, i);
					break;
				case '0': // DANGEROUS VAGINA!
					_enemies.push_back(DangerousVagina());
					_enemies.back().setPosition(j, i);
					break;
				case 'v': //YOUAREHERE!
					_enemies.push_back(YouAreHere());
					_enemies.back().setPosition(j, i);
					break;
				}
			}
		}
	}
	else {
		for (int i = 0; i < _levelDataCutScene.size(); i++) {
			for (int j = 0; j < _levelDataCutScene[i].size(); j++) {
				tile = _levelDataCutScene[i][j];
				switch (tile) {
				case '@':
					player->setPosition(j, i);
					break;
				case 'D':
					break;
				case 'T':
					break;
				case 'F':
					_NPCs.push_back(NPC('F'));
					_NPCs.back().setPosition(j, i);
					break;
				case '!': //Exclamation Enemy!
					_enemies.push_back(Exclamation());
					_enemies.back().setPosition(j, i);
					break;
				case 'P': // DANGEROUS PUSSY!
					_enemies.push_back(DangerousPussy());
					_enemies.back().setPosition(j, i);
					break;
				case '0': // DANGEROUS VAGINA!
					_enemies.push_back(DangerousVagina());
					_enemies.back().setPosition(j, i);
					break;
				case 'v': //YOUAREHERE!
					_enemies.push_back(YouAreHere());
					_enemies.back().setPosition(j, i);
					break;
				}
			}
		}
	}
}

void Level::print(Player* &player)
{
	if (_levelData.size() != 0)
	{
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
	else {
		for (int i = 0; i < _levelDataCutScene.size(); i++)
		{
			printf("%s\n", _levelDataCutScene[i].c_str());
		}
		cout << endl;
	}
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


void Level::processPlayerMove(Player* &player, int targetX, int targetY)
{
	int playerX, playerY;
	player->getPosition(playerX, playerY);

	char moveTile = getTile(targetX, targetY);
	//string line = "Get fucking rekt, pussy lips.";

	switch (moveTile)
	{
	case '#':
	case 'v':
		break;
	case '.': player->setPosition(targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');
		break;
	case ' ': 
		player->setPosition(targetX, targetY);
		setTile(playerX, playerY, ' ');
		setTile(targetX, targetY, '@');
		break;
		break;
	case 'T':
		break;
	case 'D': 
		newLevel(player);
		break;
	default:
		battleMonster(player, targetX, targetY);
		break;
	}
}

	char Level::getTile(int x, int y) {
		if (_levelData.size() != 0)
			return _levelData[y][x];
		else
			return _levelDataCutScene[y][x];
	}

	void Level::setTile(int x, int y, char tile)
	{
		if (_levelData.size() != 0)
			_levelData[y][x] = tile;
		else
			_levelDataCutScene[y][x] = tile;
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
	case ' ': _enemies[enemyIndex].setPosition(targetX, targetY);
		setTile(enemyX, enemyY, ' ');
		setTile(targetX, targetY, _enemies[enemyIndex].getAvatar());
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
				int playerDefense = player->getDefense();
				int enemyDefense = _enemies[i].getDefense();
				string enemyName = _enemies[i].getName();
				//WE MUST DO BATTLE
				attack = player->attack();

				attackResult = _enemies[i].takeDamage(attack);
				if (attackResult != 0 && attackResult != -1) {
				printf("%s does damage of %d!\n", playerName.c_str(), attack - enemyDefense);
				
					printf("%s met a bitter end.\n", enemyName.c_str());
					player->addExperience(attackResult);

					_enemies[i] = _enemies.back();
					_enemies.pop_back();
					i--;
					setTile(targetX, targetY, '.');
					return;
				}
				else if (attackResult == -1) {
					printf("%s does damage of %d!\n", playerName.c_str(), 0);
					printf("You didn't even dent %s.\n", enemyName.c_str());
				}
				else {
					printf("%s does damage of %d!\n", playerName.c_str(), attack - enemyDefense);
				}
				//monster fights now!
				attack = _enemies[i].attack();
				attackResult = player->takeDamage(attack);
				
				if (attackResult != 0 && attackResult != -1) {
				printf("%s does damage of %d\n", enemyName.c_str(), attack - playerDefense);
					setTile(playerX, playerY, '.');
					printf("%s met a bitter end.", playerName.c_str());
					
					player->addExperience(attackResult);
					system("PAUSE");
					exit(1);
				}
				else if (attackResult == -1) {
					printf("%s does damage of %d!\n", enemyName.c_str(), 0);
				}
				else {
					printf("%s does damage of %d\n", enemyName.c_str(), attack - playerDefense);
				}
				
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


void Level::newLevel(Player* &player)
{
	_levelNumber++;
	_levelData.clear();
	_levelDataCutScene.clear();
	load(_levels[_levelNumber], player);
}
