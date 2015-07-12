#include <iostream>
#include <cstring>
#include "player.h"

using namespace std;

void Player::STORY(Player* y)
{
	STORYpriv(y, y->hp, y->pp);
}

void Player::STORYpriv(Player* your, int hp, int pp)
{
	cout << "This is the beginning of " << your->name << "'s beautiful, teenage-rebellion story." << endl;
	cout << your->name << " has an awful relationship with " << his << " parents." << endl;
	cout << he << " recently had sex with Darla the Daring next door." << endl;
}