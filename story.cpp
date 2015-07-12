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
	cout << "This is the beginning of the goddamn story." << endl;
	cout << /*your->name <<*/ " has an awful relationship with " /*<< his*/ << " parents.";
}