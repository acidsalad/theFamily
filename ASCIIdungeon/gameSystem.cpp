#include "gameSystem.h"
#include <conio.h>
#include <windows.h>


gameSystem::gameSystem()
{
	_player->init(20, 5, 1, 0, 4, 50);

	
	_level.load("level2.txt", _player);
}



void gameSystem::playGame()
{
	bool isDone = false;
	while (!isDone)
	{
		_level.print(_player);
		playerMove();
	}
}

void gameSystem::playerMove() {
	char input;
	input = _getch();

		ClearScreen();
	//cout << string(25, '\n');

	
	_level.movePlayer(input, _player);
	_level.updateEnemies(_player);
	}


void gameSystem::ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
		)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}