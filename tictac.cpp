#include <iostream>
#include <random>
#include <ctime>
#include <string>

using namespace std;

const string NPCDarla = "DARLA THE DARING";

void printBoard(char board[3][3])
{
	for (int y = 0; y < 3; y++){
		for (int x = 0; x < 3; x++){
			cout << "| " << board[y][x] << " ";
		}
		cout << "|\n";
	}
	
}

void placeTic(char board[3][3])
{
	int x,y;
	cout << "Enter an x-value: ";
	cin >> x;
	cout << "Enter a y-value: ";
	cin >> y;
	board[y-1][x-1] = 'X';
	
	static default_random_engine rando(time(NULL));
	uniform_int_distribution<int> ar(1, 3);
	int x2 = x, y2 = y;
	do {
		x2 = ar(rando);
		y2 = ar(rando);
		if(x2 != x || y2 != y)
		{
			board[y2-1][x2-1] = 'O';
		} 
	} while (x2 == x && y2 == y);
}