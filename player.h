#pragma once
#include <iostream>

class Player{
public:
	Player();
	~Player();
	
	int attack();
	void createCharacter(Player*);
	void STORY(Player*);

private:	
	int hp;
	int pp;
	std::string his;
	std::string he;
	std::string name;
	int attackPrivate(int);
	void createCharacterPrivate(Player*);
	void STORYpriv(Player*, int, int);
};