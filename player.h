#pragma once
#include <iostream>

class Player{
public:
	Player();
	~Player();
	
	int attack();
	void createCharacter(Player*);

private:	
	int hp;
	int pp;
	int attackPrivate(int);
	std::string name;
	void createCharacterPrivate(Player*);
	
};