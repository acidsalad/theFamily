#pragma once
#include "player.h"

class Storybook : public Player{
	//friend operator==()
	
public:
	void STORY();
	Storybook();
	~Storybook();
	Player* your = new Player;
	
private:

	void STORYpriv(Player*);
	void Home(Player*);
	void Darla(Player*);
	void Detention(Player*);
	
	std::string randomDarlaSaying(Player*);
	void placeTic(char[3][3]);
	void placeTac(char[3][3]);
	void fullBoard(char[3][3], Player*);
	
};