#pragma once
#include "Entity.h"

class Enemy :	public Entity {
public:
	Enemy(string name, char tile, int attack, int defense, int hp, int exp, int attackDistance);
	~Enemy();

	int takeDamage(int attack);

	//Getters
	char getAvatar() { return _avatar; }
	//Gets AI move command
	char getMove(int playerX, int playerY);

private:
	int _expValue;
	int _attackDistance;

};

