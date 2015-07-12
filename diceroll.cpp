#include <iostream>
#include <string>
#include <random>

using namespace std;

int main()
{
	default_random_engine rando;
	uniform_int_distribution<int> diceRoll(1, 6);
	
	cout << "You rolled a " << diceRoll(rando) << endl;
	
	int temp;
	cin >> temp;
}