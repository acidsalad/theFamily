#include "player.h"

Player::Player()
{
		hp = 30;
		pp = 10;
		name = "fuckboy";
	}
	
Player::~Player()
{
	printf("%s has died.\n", name.c_str());
}

void Player::createCharacter(Player* y)
{
	createCharacterPrivate(y);
}

void Player::createCharacterPrivate(Player* your)
{
	printf("Please enter your name: ");
	scanf("%s", your->name.c_str());
	printf("\n");
}