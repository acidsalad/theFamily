#pragma once
#include "player.h"

class Storybook : public Player{
public:
	void STORY(Player*);
	~Storybook();
	
private:
	void STORYpriv(Player*, int, int);
	void Home(int);
	void Darla(int);
};