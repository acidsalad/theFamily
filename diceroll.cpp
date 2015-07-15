//The dice roll and attack do not correspond to each other.
//this is just an experimental .cpp file
//mainly curious in the default_random_generator type.

#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

int diceRoll(default_random_engine);
void attackFather(default_random_engine);
int attackRoll(default_random_engine);

int main()
{
	//dice roll part of application. Simple and short
	static default_random_engine rando(time(NULL));
	int dr = diceRoll(rando);
	
	cout << "You rolled a " << dr << "." << endl;
	
	
	//Here we have an attack part of the application.
	//The enemy is automatically the father.
	attackFather(rando);
	
	int temp;
	cin >> temp;
}

int diceRoll(default_random_engine rando)
{
	uniform_int_distribution<int> dr(1, 6);
	return dr(rando);
}

int attackRoll(default_random_engine rando)
{
	uniform_real_distribution<float> ar(0.0f, 1.0f);
	
	float attack = ar(rando);
	if (attack <= 0.7f)
	{
		return 0;
	}
	else 
	{
		return 1;	
	}
}

void attackFather(default_random_engine rando)
{
	cout << "You attack your unloving father!" << endl;
	int hit = attackRoll(rando);
	if (hit == 0)
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
}