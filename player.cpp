#include "player.h"
#include <string>
using std::cout;

// overloading <<, constructing class, and destructing class
std::ostream& operator<<(std::ostream& os, const Player& y)
{
  std::cout << "";
  return os;
}

Player::Player()
{
		hp = 30;
		pp = 10;
		name = "fuckboy";
		his = "his";
		he = "he";
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
	std::string input;
	printf("Please enter your name: ");
	scanf("%s", your->name.c_str());
	
	cout << "\nAre you a boy or a girl?\n";
	scanf("%s", input);
	if (input == "boy" || input == "Boy" || input == "BOY" || input == "a boy")
	{
		// keep defaults
	}
	else if (input == "girl" || input == "Girl" || input == "GIRL" || input == "a girl")
	{
		your->his = "her";
		your->he = "she";
	}
	else
	{
		your->his = "its";
		your->he = "it";
	}
}