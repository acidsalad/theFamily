#include <iostream>
#include <cstring>
#include "player.h"
#include "story.h"

using namespace std;

Storybook::Storybook()
{
	your->createCharacter(your);
}

Storybook::~Storybook()
{
	delete your;
	cout << "Game over." << endl;
}

void Storybook::STORY()
{
	STORYpriv(your);
}

int chapter;

void Storybook::STORYpriv(Player* your)
{
	int input;
	
	//test-values
	cout << "hp = " << hp << endl;
	cout << "pp = " << pp << endl;
	
	cout << "This is the beginning of " << your->name << "'s beautiful, teenage-rebellion story." << endl;
	cout << your->name << " has an awful relationship with " << your->his << " parents." << endl;
	cout << your->he << " recently had sex with DARLA THE DARING next door." << endl;
	cout << "The first to find out about this was " << your->name << "'s dad." << endl;
	
	cout << "Would you like to brave your house or go back and see Darla?" << endl;
	cout << "Press [1] to go home, [2] to go to Darla's:\n";
	cin >> input;
	
	//input == 1 ? Home(chapter) : Darla(chapter);
		switch (input)
		{
			case 1:
			Home(your);
			break;
			case 2:
			Darla(your);
			break;
			default:
			cout << "No wonder you make such bad grades.\n";
			Detention(your);
			break;
		}
}

void Storybook::Home(Player* y)
{
	
}

void Storybook::Darla(Player* y)
{
	
}

void Storybook::Detention(Player* y)
{
	
}