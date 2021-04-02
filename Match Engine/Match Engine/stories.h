#pragma once

#include <iostream>
using namespace std;

string* fstories(string* name, float health, float hit, float block) {

	if (health > 0) {
		cout << name << "dealt " << hit << " and was blocked for " << block << endl;
	}
	else if (health == 0 || health < 0) {

		cout << "The crowd goes wild! " << name << " has bested their opponent in the ring of battle! " << endl;
	}

	else {

		cout << "A turn is missed" << endl;
	}

	//these should be appended to one another into a string and then returned, but as an object that has a certain size? Potentially in a struct
	return name;
}