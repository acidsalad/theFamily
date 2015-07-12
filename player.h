#pragma once
#include <iostream>

class Player{
public:
	friend std::ostream& operator<<(std::ostream&, const Player&);
	friend std::istream& operator>>(std::istream& is, Player& your);

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