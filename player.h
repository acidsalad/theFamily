#pragma once

class Player{
public:
	Player(){
		hp = 30;
		pp = 10;
		name = "fuckboy";
	}
	
	int attack();
	

private:	
	int hp;
	int pp;
	int attackPrivate(int);
	string name;
	
};