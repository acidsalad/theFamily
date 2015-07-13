#ifndef _PLAYERCPP
#define _PLAYERCPP

#include "player.h"
#include <string>
using std::cout;
using std::endl;
using std::cin;

// overloading <<, >>, constructing class, and destructing class
std::ostream& operator<<(std::ostream& os, const Player& your)
{
  std::cout << "";
  return os;
}

std::istream& operator>>(std::istream& is, Player& your)
{
	std::cin >> your.name;
	return is;
}

Player::Player()
{
		hp = 30;
		pp = 10;
		anger = 0;
		ghostCount = 0;
		name = "Ghost" + static_cast<char>(ghostCount + 1);
		his = "his";
		he = "He";
	}
	
Player::~Player()
{
	cout << name << " has died.\n";
}

void Player::createCharacter(Player* y)
{
	createCharacterPrivate(y);
}

void Player::createCharacterPrivate(Player* your)
{
	std::string input;
	printf("Please enter your name: ");
	cin >> your->name;
	//scanf("%s", your->name.c_str());
	int n = your->name.length();
	
	
	
	cout << "\nAre you a boy or a girl?\n";
	cin >> input;
	cout << "Your name is a word of length " << your->name.length() << endl;
	cout << your->name << endl;
	cout << "Your gender is a word of length " << input.length() << endl;
	cout << input << endl;
	if (input == "boy" || input == "Boy" || input == "BOY" || input == "a boy")
	{
		// keep defaults
	}
	else if (input == "girl" || input == "Girl" || input == "GIRL" || input == "a girl")
	{
		your->his = "her";
		your->he = "She";
	}
	else
	{
		your->his = "its";
		your->he = "It";
	}
}

#endif