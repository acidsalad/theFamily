#include "Enemy.h"
#include <random>
#include <ctime>
#include <cmath>

using namespace std;


Enemy::Enemy(string name, char tile, int attack, int defense, int hp, int exp, int attackDistance)
{
	_name = name;
	_avatar = tile;
	_attack = attack;
	_defense = defense;
	_hp = hp;
	_expValue = exp;
	_attackDistance = attackDistance;
}


Enemy::~Enemy()
{
}


int Enemy::takeDamage(int attack)
{
	attack -= _defense;
	//check if attack damages
	if (attack > 0) {
		_hp -= attack;
		//check if death
		if (_hp <= 0)
			return _expValue;
	}
	else {
		return -1;
	}
	return 0;
}

char Enemy::getMove(int playerX, int playerY)
{
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> moveRoll(0, 6);

	float distance;
	int dx = _x - playerX;
	int dy = _y - playerY;
	int adx = abs(dx), ady = abs(dy);

	distance = sqrt((pow(adx, 2)) + pow(ady, 2.0));

	if (distance <= _attackDistance){
		//should the enemy move left/right?
		if (adx > ady) {
			if (dx < 0) {
				return 'a';
			}
			else {
				return 'd';
			}
		}
		else { // or up/down?
			if (dy < 0) {
				return 'w';
			}
			else {
				return 's';
			}
		}
	}
	else {
		int randomMove = moveRoll(randomEngine);
		switch (randomMove){
		case 0:
			return 'a';
		case 1:
			return 'w';
		case 2:
			return 's';
		case 3:
			return 'd';
		default:
			return '.';
		}
	}
}