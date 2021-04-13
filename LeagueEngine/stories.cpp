#include "stories.h"

void fstories(string name, float health, float hit, float block) {

	if (health > 0) {
		cout << endl;
		cout << name << " dealt " << hit << " and was blocked for " << block << ". Leaving his opponent with a health of: " << health << endl;
		
	}
	else if (health == 0 || health < 0) {
		cout << endl;

		cout << name << " dealt " << hit << " and was blocked for " << block << ". Leaving his opponent with a health of: 0" << endl;
		cout << "The crowd goes wild! " << name << " has bested their opponent in the ring of battle! " << endl;
	}

	else {

		cout << "A turn is missed" << endl;
	}
}