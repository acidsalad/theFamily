#pragma once

class Enemy{
public:
	Enemy(){
		hp = 0;
		pp = 0;
		name = "default";
	} 
	
	int attack();

protected:	
	int hp;
	int pp;
	string name;
	
	int attackPrivate(int);
};