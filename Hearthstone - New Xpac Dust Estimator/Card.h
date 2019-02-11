// Author:		Logan Hammond; hamm32637@email.ccbcmd.edu
// Source File: Card.h
// Description: Header file for Card class. A card is an object with a specific
//				rarity that may, or may not be golden. The value of a card is
//				determined by its rarity, and golden quality. If the card is golden its value is
//				increased by a pre-defined amount.
// IDE:			Microsoft Visual Studio 2017

#include <iostream>
using namespace std;
#pragma once

class Card {
private:
	string rarity;
	bool isGolden;
	int totalVal;
public:
	// Constructor.
	Card(string rar = "common", bool gold = false) {
		this->rarity = rar;
		this->isGolden = gold;
	}

	// Destructor.
	~Card() {
		
	}

	// Function declarations.
	string getRarity();
	void setRarity(string);
	bool getIsGolden();
	void setIsGolden(bool);
	int getValue();
};