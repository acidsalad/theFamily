#include "player.cpp"
#include "story.cpp"

using namespace std;

int main()
{
	Player* your = new Player;
	your->createCharacter(your);
	Storybook* book = new Storybook;	
	book->STORY(your);
	
	
	delete your;
	delete book;
	return 0;
}