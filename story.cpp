#include <iostream>
#include <cstring>
#include "player.h"
#include "story.h"

using namespace std;

Storybook::~Storybook()
{
	cout << "Game over." << endl;
}

void Storybook::STORY(Player* y)
{
	STORYpriv(y, y->hp, y->pp);
}

int chapter;

void Storybook::STORYpriv(Player* your, int hp, int pp)
{
	int input;
	
	//test-values
	cout << "hp = " << hp << endl;
	cout << "pp = " << pp << endl;
	
	cout << "This is the beginning of " << your->name << "'s beautiful, teenage-rebellion story." << endl;
	cout << your->name << " has an awful relationship with " << your->his << " parents." << endl;
	cout << your->he << " recently had sex with Darla the Daring next door." << endl;
	cout << "The first to find out about this was " << your->name << "'s dad." << endl;
	
	cout << "Would you like to brave your house or go back and see Darla?" << endl;
	cout << "Press [1] to go home, [2] to go to Darla's:\n";
	cin >> input;
	
	input == 1 ? Home(chapter) : Darla(chapter);
	chapter++;
 	
}

void Storybook::Home(int ch)
{
	
}

void Storybook::Darla(int ch)
{
	
}