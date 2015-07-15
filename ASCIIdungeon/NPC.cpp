#include "NPC.h"
#include <random>
#include <ctime>


NPC::NPC(char avatar)
{
	_avatar = avatar;
}


NPC::~NPC()
{
}

bool NPC::talk()
{
	printf("You are a disgrace to THEFAMILY.");
	return true;
}

char NPC::getMove(int playerX, int playerY)
{
	bool done = false;
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> moveRoll(0, 6);

	float distance;
	int dx = _x - playerX;
	int dy = _y - playerY;
	int adx = abs(dx), ady = abs(dy);

	distance = sqrt((pow(adx, 2)) + pow(ady, 2.0));

	//should the NPC move at all?
	switch (_avatar) {
	case 'F':
		break;
	default:
		while (!done)
		{
			if (distance <= 5){
				//should the NPC move left/right?
				if (adx > ady) {
					if (dx < 0) {
						return 'a';
					}
					else {
						return 'd';
					}
				}
				else { // or up/down?
					if (dy < 0) {
						return 'w';
					}
					else {
						return 's';
					}
				}
				
			}
			else {
				int randomMove = moveRoll(randomEngine);
				switch (randomMove){
				case 0:
					return 'a';
				case 1:
					return 'w';
				case 2:
					return 's';
				case 3:
					return 'd';
				default:
					return '.';
				}
			}
		}
	}
}