#include "player.cpp"
#include "story.cpp"

using namespace std;

int main()
{
	//Player* your = new Player;
	//your->createCharacter(your);
	Storybook* book = new Storybook;	
	book->STORY();
	
	
	//delete your;
	delete book;
	return 0;
}