#include "Player.h"
#include <random>
#include <ctime>


Player::Player()
{
	_hp = 20;
	_pp = 5;
	_name = "fuckboy";
	_x = 0;
	_y = 0;
	_level = 1;
	_exp = 0;
}

void Player::init(int hp, int pp, int level, int experience, int attack, int toNextLevel)
{
	_hp = hp;
	_pp = pp;
	_level = level;
	_exp = experience;
	_attack = attack;
	_toNextLevel = toNextLevel;
}


Player::~Player()
{
}


int Player::takeDamage(int attack)
{
	attack -= _defense;
	//check if attack damages
	if (attack > 0) {
		_hp -= attack;
		//check if death
		if (_hp <= 0)
			return 1;
	}
	else {
		return -1;
	}
	return 0;
}

void Player::addExperience(int exp) { 
	static default_random_engine randomGenerator(time(NULL));
	uniform_int_distribution<int> statsAandD(1, 3);
	uniform_int_distribution<int> statsHandP(2, 5);

	_exp += exp;
	while (_exp >= _toNextLevel) {
		printf("Leveled up!\n");
		_exp -= _toNextLevel;
		_attack += statsAandD(randomGenerator);
		_defense += statsAandD(randomGenerator);
		_hp += statsHandP(randomGenerator);
		_pp += statsHandP(randomGenerator);
		_toNextLevel = _toNextLevel + pow((_level + _attack + _defense), 2);
		_level += 1;
	}
}





