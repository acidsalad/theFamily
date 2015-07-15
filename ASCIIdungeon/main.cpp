#include <iostream>
#include <conio.h> //for the getch(); function
#include <string>
#include "Level.h"
#include "gameSystem.h"

using namespace std;

int main()
{
	gameSystem gs("level1.txt");
	gs.playGame();

	system("PAUSE");
}

/* A way to clear the screen.
string clearScreen(100, '\n');
cout << clearScreen;
*/