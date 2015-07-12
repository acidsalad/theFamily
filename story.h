#pragma once
#include "player.h"

class Storybook : public Player{
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
};