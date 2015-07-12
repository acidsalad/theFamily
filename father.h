#pragma once
#include "enemy.h"

class Father: public Enemy{
public:
	Father(){
		hp = 40;
		pp = 30;
		name = "Unloving Father";
	}

	int shout();

protected:
	int shoutPrivate(string);
	
}