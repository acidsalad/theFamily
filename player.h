#pragma once

class Player{
public:
	Player(){
		hp = 30;
		pp = 10;
	}
	
	int attack();

private:	
	int hp;
	int pp;
	int attack(int);
	
};