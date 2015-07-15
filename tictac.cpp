#include <iostream>
#include <random>
#include <ctime>
#include <string>

using namespace std;

const string NPCDarla = "DARLA THE DARING";

void printBoard(char board[3][3])
{
	int y = 0, x = 0;
	cout << "   | 1 | 2 | 3 |\n";
	for (y = 0; y < 3; y++){
		cout << " " << y+1 << " ";
		for (x = 0; x < 3; x++){
			cout << "| " << board[y][x] << " ";
		}
		cout << "|\n";
	}
}

bool ThreeInaRow(char board[3][3])
{
	bool gameOver = false;
	
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
	
	return gameOver;
}

void Storybook::fullBoard(char board[3][3], Player* your)
{
if (board[0][0] != '_' && board[0][1] != '_' && board[0][2] != '_' && board[1][1] != '_' && board[1][2] != '_' && board[2][0] != '_' && board[2][1] != '_' && board[2][2] != '_')
	{
		cout << "Tie. Let's start over :)\n";
		your->anger++;
		cout << your->name << "'s anger rose by 1.\n";
		for (int y = 0; y < 3;  y++){
			for (int x=0;x<3; x++){
				board[y][x] = '_';
			}
		}
		
	}
}