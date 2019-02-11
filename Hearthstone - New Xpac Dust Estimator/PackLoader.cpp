// Author:		Logan Hammond; hamm32637@email.ccbcmd.edu
// Source File: Pack.cpp
// Description: Cpp file for Pack class. Contains implementation of functions declared in Pack.h header file.
// IDE:			Microsoft Visual Studio 2017

#include "PackLoader.h"
#include "Pack.h"
#include "Card.h"
//#include "estimator.cpp"
#include <random>
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

/*
	Generates a Pack composed of 5 Card objects. Generates numbers, and therefore
	card qualities based on a uniform distribution.
	@return Pack pack Pack object.
*/
Pack PackLoader::loadPackAvg(bool isNewSet) {
	// Create Pack object to return, and setup RNG's.
	Pack pack;


	bool hasRareOrBetter = false;


	// Card generation.
	for (int i = 0; i < 5; i++) {
		Card card;
		unsigned seed = chrono::system_clock::now().time_since_epoch().count();
		unsigned seed2 = chrono::system_clock::now().time_since_epoch().count() % 10;
		default_random_engine rarityGenerator(seed);
		default_random_engine goldenGenerator(seed2);
		uniform_real_distribution<double> rarityDist(1, 100);
		uniform_real_distribution<double> goldenDist(1, 100);

		double rarityDouble = rarityDist(rarityGenerator);
		double goldDouble = goldenDist(goldenGenerator);

		// Set initial rarity. Epic: 1 in 5 packs => 1 in 25 cards. Legendary: 1 in 20 packs => 1 in 100 cards
		if (rarityDouble >= 99) {									// 1% chance for Legendary.
			card.setRarity("legendary");
			hasRareOrBetter = true;
		}
		else if ((rarityDouble < 99) && (rarityDouble > 95)) {		// 4% chance for Epic.
			card.setRarity("epic");
			hasRareOrBetter = true;
		}
		else if ((rarityDouble <= 95) && (rarityDouble > 74)) {		// Assume 20% chance for Rare.
			card.setRarity("rare");
			hasRareOrBetter = true;
		}
		else {														// Else Common.
			card.setRarity("common");
		}

		// Set gold status.
		if (goldDouble <= 3.2) {
			card.setIsGolden(true);
		}

		// Insert card into pack.
		pack.contents[i] = card;
	}

	// Check for one rare or better per pack.
	if (hasRareOrBetter) {
		return pack;
	}
	else {
		pack.contents[4].setRarity("rare");
		return pack;
	}

	// Account for pity timer.


	return 0;
}

/*
	---WORKING AS INTENDED---
	Generates a Pack composed of 5 Card objects. This function assumes worst possible
	luck. Assuming so pity timers are the only way to obtain cards of Epic/Legendary
	quality. Rares are obtained only on packs containing 4 Commmon cards. No golden 
	pity timer has been discovered therefore none can be obtained assuming worst possible
	luck.
	@return Pack pack Pack object.
*/
vector<Pack> PackLoader::loadPackWorst(int num, bool isNewSet){
	// Create vector Pack object to return.
	Pack pack;
	vector<Pack> packVector;
	int numRuns = num;
	bool newSet = isNewSet;
	

	// Card generation.
	for (int i = 1; i <= numRuns; i++) {
		if (i % 40 == 0) {								// Pity timer for Legendary = 40.
			pack.contents[0].setRarity("legendary");
			pack.contents[1].setRarity("epic");
			pack.contents[2].setRarity("common");
			pack.contents[3].setRarity("common");
			pack.contents[4].setRarity("common");
		}
		else if (i % 10 == 0) {							// Pity timer for Epic = 10.
			pack.contents[0].setRarity("epic");
			pack.contents[1].setRarity("common");
			pack.contents[2].setRarity("common");
			pack.contents[3].setRarity("common");
			pack.contents[4].setRarity("common");
			if (newSet) {
				pack.contents[1].setRarity("legendary");
				newSet = false;
			}
		}
		else {														// Otherwise...
			pack.contents[0].setRarity("rare");
			pack.contents[1].setRarity("common");
			pack.contents[2].setRarity("common");
			pack.contents[3].setRarity("common");
			pack.contents[4].setRarity("common");
		}
		packVector.push_back(pack);
	}

	return packVector;
}
