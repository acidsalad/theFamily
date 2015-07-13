#include <iostream>
#include <cstring>
#include "player.h"
#include "story.h"
#include "tictac.cpp"

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
	cout << your->he << " recently had sex with "<< NPCDarla << " next door." << endl;
	cout << "The first to find out about this was " << your->name << "'s dad." << endl;
	
	cout << "Would you like to brave your house or go back and see " << NPCDarla << "?" << endl;
	cout << "Press [1] to go home, [2] to go to " << NPCDarla << "'s:\n";
	cin >> input;
	
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
	int input;
	char board[3][3];
	bool gameOver = false;
	
	//initiating Board function
	for (int y = 0; y< 3; y++){
		for (int x =0;x<3;x++){
			board[x][y] = '_';
		}
	}
	
	cout << NPCDarla << ": Let's play a game of TIC-TAC-TOE!" << endl;
	cout << "[1] - yes\t[2] - no" << endl;
	cin >> input;
	//you're going to play no matter what you say.
	cout << "Darla: You're a DAAAARRRRRling." << endl;
	printBoard(board);
	while(!gameOver)
	{
	placeTic(board);
	printBoard(board);
	if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') || (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O'))
	gameOver = true;
	if ((board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') || (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O'))
	gameOver = true;
	if ((board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') || (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O'))
	gameOver = true;
	if ((board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') || (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O'))
	gameOver = true;
	if ((board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') || (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O'))
	gameOver = true;
	if ((board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') || (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'))
	gameOver = true;
	if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'))
	gameOver = true;
	if ((board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
	gameOver = true;
	
	string darsays = randomDarlaSaying(your);
	cout << NPCDarla << ": " << darsays << endl;
	cout << your->anger << endl;
	}
}

void Storybook::Detention(Player* y)
{
	
}