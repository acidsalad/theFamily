#include "player.cpp"

using namespace std;

int main()
{
	Player* your = new Player;
	your->createCharacter(your);
	
	
	
	
	delete your;
	return 0;
}