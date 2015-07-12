#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

int main()
{
	static default_random_engine rando(time(NULL));
	uniform_int_distribution<int> diceRoll(1, 6);
	
	cout << "You rolled a " << diceRoll(rando) << endl;
	
	uniform_real_distribution<float> attackRoll(0.0f, 1.0f);
	
	float attack = attackRoll(rando);
	cout << "You attack your unloving father!" << endl;
	if (attack <= 0.7f)
	{
		cin.get();
		cout << "No damage." << endl;
		cout << "Your father said you hit like a girl." << endl;
	}
	else 
	{
		cin.get();
		cout << "A direct hit!" << endl;
		cout << "A sparkling tear forms in your father's unloving eyes." << endl;
	}
	
	int temp;
	cin >> temp;
}