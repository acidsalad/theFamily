#include "Entity.h"
#include <random>
#include <ctime>

using namespace std;

Entity::Entity()
{
	_hp = 5;
	_pp = 5;
	_name = "DEADLY EVIL SPONGES";
	_avatar = '!';
}


Entity::~Entity()
{
}


//setter
void Entity::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}

//getters
void Entity::getPosition(int &x, int &y)
{
	x = _x;
	y = _y;
}


int Entity::attack()
{
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, _attack);

	return attackRoll(randomEngine);
}
