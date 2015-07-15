#pragma once
#include <iostream>
using namespace std;

class Entity {
public:
	Entity();
	~Entity();

	int attack();
	void walk();


	//setter
	void setPosition(int x, int y);

	//getter
	void getPosition(int &x, int &y);
	int get_hp(){ return _hp; }
	int get_pp(){ return _pp; }
	string getName() { return _name; }
	int getDefense() { return _defense; }

protected:
	int _attack;
	int _defense;
	string _name;
	int _hp;
	int _pp;
	int _x;
	int _y;
	char _avatar;
};

