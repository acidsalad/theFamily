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
	int anger;
	std::string his;
	std::string he;
	std::string name;
	
	// The player accumulates ghosts whenver the story is recreated (i.e. whenever the player dies and continues)
	// The your->ghostCount will accumulate in the Storybook constructor (which inherits from here, so it's all good)
	// And the ghosts will have names based on ghostCount. Still working on this.
	// The ghosts will be the final boss.
	int ghostCount;
	
	int attackPrivate(int);
	void createCharacterPrivate(Player*);
	
};