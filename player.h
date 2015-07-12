#pragma once
#include <iostream>

class Player{
public:
	friend std::ostream& operator<<(std::ostream&, const Player&);
	friend std::istream& operator>>(std::istream& is, Player& your);
	friend class Storybook;

	Player();
	~Player();
	
	int attack();
	void createCharacter(Player*);

protected:	
	int hp;
	int pp;
	std::string his;
	std::string he;
	std::string name;
	
	int attackPrivate(int);
	void createCharacterPrivate(Player*);
	
};