// Author:		Logan Hammond; hamm32637@email.ccbcmd.edu
// Source File: estimator.cpp
// Description: Estimates total dust value of a given number of packs to open in Hearthstone. All packs contain five cards where at least one is guaranteed to be of Rare rarity or higher.
//				Rarities (least to most): Common, Rare, Epic, Legendary.
//				You receive one epic card from a pack every five packs on average. You recieve one Legendary card from a pack every twenty packs on average.
//				Good packs are packs that contain at least one card of Epic and/or Legendary rarity.
//				Standard packs are packs that contain four Commons and one Rare (worst luck).
// IDE:			Microsoft Visual Studio 2017
// 
// Problems:	1. Program does not correctly get proper number of different rarities per card pack. Currently there are a lot of Epics. This has too do with
//				how Packloader.loadPack() assigns card rarity.
//				2. Different calculations should call different versions of Packloader.loadPack(). I.e. calcAvg() -> loadPackAvg, & calcWorst() -> loadPackWorst()...
//				3. Improper display of individual cards in packs during output. Format should be Card X: <Golden>* <Rarity> <Value>. Should look nice.


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Card.h"
#include "Pack.h"
#include "PackLoader.h"
using namespace std;

// Global variables
locale loc;
int numPacks = 0;
bool isNewSet = false;

// Function declarations
void displayTitle();
int getNumPacks();
int calcDust(vector<Pack>);

// Function definitions
/*
	Displays title of program.
	@return none.
*/
void displayTitle() {
	cout << "\t\tHearthstone Dust Estimator\n";
}

/*
	Returns int numPacks.
	@return int numPacks Number of packs.
*/
int getNumPacks() {
	return numPacks;
}

int calcDust(vector<Pack> packs) {
	int val = 0;
	int totalArr[5] = {0, 0, 0, 0, 0}; // {Commons, Rares, Epics, Legendaries, Goldens}
	string gold = "";
	string rarity = "";

	cout << "\n\n\tCards";
	for (unsigned int i = 0; i < packs.size(); i++) {		// Pack starts here.
		cout << "\n\t   Pack " << i+1;
		cout << "\n\t-----------";
		for (int j = 0; j < 5; j++) {						// Cards start here.
			int cardVal = packs[i].contents[j].getValue();
			val += cardVal;
			if (packs[i].contents[j].getIsGolden()) {
				gold = "Golden ";
			}
			else {
				gold = "";
			}
			rarity = packs[i].contents[j].getRarity();
			cout << "\n\tCard " << j + 1 << ": " << gold << rarity +" "<< cardVal;
			
			// Tally rarity.
			if (packs[i].contents[j].getRarity() == "common") {
				totalArr[0]++;
			}
			else if (packs[i].contents[j].getRarity() == "rare") {
				totalArr[1]++;
			}
			else if (packs[i].contents[j].getRarity() == "epic") {
				totalArr[2]++;
			}
			else if (packs[i].contents[j].getRarity() == "legendary") {
				totalArr[3]++;
			}

			// Tally golden.
			if (packs[i].contents[j].getIsGolden() == true) {
				totalArr[4]++;
			}
		}
		cout << "\n";
	}

	cout << "\n\t   Totals";
	cout << "\n\tCommons    : " << totalArr[0];
	cout << "\n\tRares      : " << totalArr[1];
	cout << "\n\tEpics      : " << totalArr[2];
	cout << "\n\tLegendaries: " << totalArr[3];
	cout << "\n\tGolden     : " << totalArr[4];
	return val;
}

int main() {
	// Main variables.
	vector<Pack> packs;				// Vector collection of Pack objects.
	PackLoader loader;				// Instance of PackLoader object.

	// Display output starts here.
	displayTitle();

	// Prompt user for number of packs.
	cout << "\n\tEnter number of packs: ";
	cin >> numPacks;

	// Promt user for new set status.
	string userString = "";
	cout << "\n\tIs this a new set for you? (y/n): ";
	cin >> userString;
	if (userString == "y") {
		isNewSet = true;
	}

	// Enter switch menu for estimate type.
	int userChoice = -1;
	cout << "\n\tEnter estimate type...\n";
	cout << "\n\t1: All";
	cout << "\n\t2: Average";
	cout << "\n\t3: Best";
	cout << "\n\t4: Worst";
	cout << "\n\t0: Exit Program";
	cout << "\n\n\tChoice: ";
	cin >> userChoice;
	if (userChoice != 0) {
		switch (userChoice) {
		// Calculate avg dust from all possible estimate types. 
		case 1:
			// Do stuff
			break;
		// Calculate avg dust from average estimate type. 
		case 2:
			for (int i = 0; i < numPacks; i++) {
				packs.push_back(loader.loadPackAvg(isNewSet));
			}
			cout << "\n\tAverage dust from " << numPacks << " pack(s) : " << calcDust(packs) << " dust.";
			break;
		// Calculate avg dust from best estimate type
		case 3:
			// Do stuff
			break;
		// Calculate avg dust from worst estimate type
		case 4:
			packs = loader.loadPackWorst(numPacks, isNewSet);
			cout << "\n\tWorst dust from " << numPacks << " pack(s) : " << calcDust(packs) << " dust.";
			break;
		default:
			// Do stuff
			break;
		}
	}
	else if (userChoice == 0){
		cout << "\n\tThank you for using the program!";
	}

	// End program.
	cout << "\n\n\t";
	system("pause");
	return 0;
}