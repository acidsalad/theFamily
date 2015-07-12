#include "player.cpp"
#include "story.cpp"

using namespace std;

int main()
{
	Player* your = new Player;
	your->createCharacter(your);
	
	your->STORY(your);
	
	
	delete your;
	return 0;
}