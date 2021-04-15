#include "engine.h"

float roll(float x, float y) {

	float z = x + FLT_MIN;

	srand(time(0));
	float val = fmod(rand(), z)/y;

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

Gladiator *combatLoop(Gladiator* g1, Gladiator* g2) {

	float g1Health = g1->getHP();
	float g2Health = g2->getHP();
	float g1Str = g1->getStrength();
	float g2Def = g2->getDefence();
	float g1Att = g1->getAttack();

	if (g1Health > 0 || g2Health > 0)
	{
		if (g1Att * roll(101, 1) > 0.5) {

			float hit = roundf(1 + g1Str + (sign() * roll() * g1Str * 0.95));

			float block = roundf(g2Def*0.3 + (sign() * roll() * g2Def * 0.15));


			if (hit < block) {
				block = hit;
			}

			hit = hit - block;

			if (hit > g2Health) {
				hit = g2Health;
			}

			/*g2->setHP(g2->getHP() - hit + block)*/;

		

			g2Health = roundf(g2Health - hit);

			g2->setHP(g2Health);


			fstories(g1->getName(), g2Health, hit, block);

			if (g2Health <= 0) {
				return g1;
			}

		};

		combatLoop(g2, g1);

	}

};


Gladiator* selection(vector <Gladiator*> &vec) {
	for (int i = 0; i < 10; i++)
	{
		if (vec[i]->getMatchMarker() < 2 && vec[i]->getFocus() == 0)					// && getFocus() == 0
		
			vec[i]->setMatchMarker();
			return vec[i];
		}

	}




void engine(vector <Gladiator*> &vec) {

	Gladiator* g1 = new Gladiator;

	int gladiatorIndex = 0;

	for (gladiatorIndex = 0; gladiatorIndex < vec.size(); gladiatorIndex++) {

		if (vec[gladiatorIndex]->getFocus() > 0)
		{

			g1 = vec[gladiatorIndex];
		}
	}


	Gladiator *g2 = selection(vec);

	Gladiator *winner;

	
	
	float g1Health = g1->getHP();
	float g2Health = g2->getHP();


	winner = combatLoop(g1, g2);

	g1->setHP(g1Health);
	g2->setHP(g2Health);


	if (winner->getName() == g1->getName() && winner->getFocus() == g1->getFocus()) {

		training(g1, 1);
		training(g2, 0);


		g1->setWins(g1->getWins() + 1);
		g2->setLoss(g2->getLosses() + 1);
		//g2->setMatchMarker();
	}
	else {

		training(g2, 0);
		training(g1, 1);

		g2->setWins(g2->getWins() + 1);
		//g1->setMatchMarker();
		g1->setLoss(g1->getLosses() + 1);

	}


	int counter = 1;
	for (int i = 0; i < vec.size(); i++)
	{
	
		if (vec[i]->getName() != g1->getName() && vec[i]->getName() != g2->getName())
		{
			if (counter % 2 == 1)
			{
				vec[i]->setWins(vec[i]->getWins() + 1);
				counter++;
				training(vec[i], 0);
			}
			else
			{
				vec[i]->setLoss(vec[i]->getLosses() + 1);
				counter++;
				training(vec[i], 0);
			}
		}



	}

};