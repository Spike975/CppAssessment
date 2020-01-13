// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

// Last modified by Terry Nguyen (terryn@aie.edu.au)
// 10/09/2018

// Fixes issues with project.
// Jacob Firsdon 12/10/2019

#include <iostream>
#include "Marine.h"
#include "Zergling.h"

using std::cout;
using std::endl;

bool marineAlive(Marine * marine, size_t arrSize);
bool zerglingAlive(Zergling * swarmArr, size_t arrSize);

int main()
{
	const int squadSize = 10;
	const int swarmSize = 20;
	int currSquad = 0;
	int currSwarm = 0;
	Marine squad[squadSize];
	Zergling swarm[swarmSize];

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!"<< endl;
	// Attack each other until only one team is left alive
	while (currSquad < 10 && currSwarm < 20) // If anyone is left alive to fight . . .
	{
		if (marineAlive(squad, squadSize)) // if there's at least one marine alive
		{
			for (size_t i = 0; i < squadSize; i++) // go through the squad
			{
				if (squad[i].isAlive()&&(currSwarm < 20 && swarm[currSwarm].isAlive())) {//sees if the current marine is alive, there aren't to many dead zergs, and if the current zerg is alive
					// each marine will attack the first zergling in the swarm
					cout << "A marine fires for " << squad[i].attack() << " damage. " << endl;
					swarm[currSwarm].takeDamage(squad[i].attack());
					if (!swarm[currSwarm].isAlive()) // if the zergling dies, it is marked as such
					{
						cout << "The zergling target dies" << endl;
						currSwarm++;
						cout << "ZERG " << currSwarm << endl;
					}
				}
			}
			int totalSwarm = 0;
			for (size_t i = 0; i < swarmSize; i++) {//checks the number of zergs left
				if (swarm[i].isAlive()) {
					totalSwarm++;
				}
			}
			cout << "There are " << totalSwarm << " zerglings left to fight!\n";
		}
		if (zerglingAlive(swarm, swarmSize)) // if there's at least one zergling alive
		{
			for (size_t i = 0; i < swarmSize; i++) // loop through zerglings
			{
				if (swarm[i].isAlive()&&(currSquad < 10 && squad[currSquad].isAlive())) {//checks to see if the marine is alive, there aren't to many marines and if there is a zerg left
					cout << "A zergling attacks for " << swarm[i].attack() << " damage." << endl;
					squad[currSquad].takeDamage(swarm[i].attack());
					if (!squad[currSquad].isAlive())
					{
						cout << "The marine succumbs to his wounds." << endl;
						currSquad++;
						cout << "MARINE " << currSquad << endl;
					}
				}
			}
			int totalSquad = 0;
			for (size_t i = 0; i < squadSize; i++) {//Checks the number of marines left
				if (squad[i].isAlive()) {
					totalSquad++;
				}
			}
			cout << "There are "<< totalSquad << " marines left.\n";
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (marineAlive(squad, squadSize))
	{
		cout << "The Marines win." << endl;
	} else {
		cout << "The Zerg win." << endl;
	}
	return 0;
}

// Is there a Marine Alive?
bool marineAlive(Marine * marine, size_t arrSize)
{
	for (int i = 0; i < arrSize; i++) {
		if (marine[i].isAlive()) {
			return true;
		}
	}
	return false;
}

// Is there a Zergling Alive?
bool zerglingAlive(Zergling * swarmArr, size_t arrSize)
{
	for (int i = 0; i < arrSize; i++) {
		if (swarmArr[i].isAlive()) {
			return true;
		}
	}
	return false;
}
