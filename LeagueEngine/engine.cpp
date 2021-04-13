#include "engine.h"

float roll(float x, float y) {

	float z = x + FLT_MIN;

	srand(time(0));
	float val = fmod(rand(), z);

	return val;
};

int sign() {

	int pos = 1;
	int neg = -1;

	srand(time(0));
	int val = rand() % 2;
	if (val == 0)
	{
		return neg;
	}
	else
	{
		return pos;
	}

};

Gladiator *combatLoop(Gladiator* g1, Gladiator* g2, float g1Health, float g2Health, float g1Str, float g2Def, float g1Att) {

	if (g1Health > 0 || g2Health > 0)
	{
		if (g1Att * roll(101, 1) > 0.5) {

			float hit = g1Str + sign() * roll(g1->getStrength() / 2, 100);

			float block = g2Def * roll(g2->getDefence(), 100);

			if (hit < block) {
				block = hit;
			}

			if (hit > g2Health) {
				hit = g2Health;
			}

			/*g2->setHP(g2->getHP() - hit + block)*/;

		

			g2Health = g2Health - hit + block;


			fstories(g1->getName(), g2Health, hit, block);

			if (g2Health <= 0) {
				return g1;
			}

		};

		combatLoop(g2, g1, g1Health, g2Health, g1Str, g2Def, g1Att);

	}

};

Gladiator* g1 = new Gladiator; //Find a way to always put our gladiator here

Gladiator* selection(vector <Gladiator*> &vec) {
	for (int i = 0; i < 9; i++)
	{
		if (vec[i]->getMatchMarker() < 2)
		{
			vec[i]->setMatchMarker();
			return vec[i];
		}
	}
}



void engine(vector <Gladiator*> &vec) {


	Gladiator *g1 = vec[9];


	Gladiator *g2 = selection(vec);

	Gladiator *winner;

	float g1Health = g1->getHP();
	float g2Health = g2->getHP();
	float g1Str = g1->getStrength();
	float g2Def = g2->getDefence();
	float g1Att = g1->getAttack();



	winner = combatLoop(g1, g2, g1Health, g2Health, g1Str, g2Def, g1Att);

	/*g1->setHP(g1Health);
	g2->setHP(g2Health);*/


	if (winner->getName() == g1->getName() && winner->getFocus() == g1->getFocus()) {


		int wins = g1->getWins();
		int loss = g2->getLosses();

		g1->setWins(wins++);
		g2->setLoss(loss++);
		g2->setMatchMarker();
	}
	else {

		int wins = g2->getWins();
		int loss = g1->getLosses();

		g2->setWins(wins++);
		g1->setMatchMarker();
		g1->setLoss(loss++);

	}

	//training(g2, g1);

};