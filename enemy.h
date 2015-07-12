#pragma once

class Enemy{
public:
	Enemy(){
		hp = 0;
		pp = 0;
	}
	
	int attack();

private:	
	int hp;
	int pp;
	int attack(int);
	string name;
	
};