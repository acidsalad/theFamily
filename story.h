#pragma once
#include "player.h"

class Storybook : public Player{
	//friend operator==()
	
public:
	void STORY();
	Storybook();
	~Storybook();
	Player* your = new Player;
	std::string randomDarlaSaying(Player*);
	
private:

	void STORYpriv(Player*);
	void Home(Player*);
	void Darla(Player*);
	void Detention(Player*);
	
};