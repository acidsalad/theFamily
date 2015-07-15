#include <iostream>
#include <conio.h> //for the getch(); function
#include <string>
#include "Level.h"
#include "gameSystem.h"

using namespace std;

int main()
{
	bool isDone = false;
	int levelNumber = 0;
	gameSystem gs;
	gs.playGame();

	

	system("PAUSE");
}

/* A way to clear the screen.
string clearScreen(100, '\n');
cout << clearScreen;
*/