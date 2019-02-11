// Author:		Logan Hammond; hamm32637@email.ccbcmd.edu
// Source File: Card.cpp
// Description: Cpp file for Card class. Contains implementation of functions declared in Card.h header file.
// IDE:			Microsoft Visual Studio 2017

#include <iostream>
#include "Card.h"
using namespace std;

/*
	Returns rarity of card as string.
	@return string rarity Rarity of card.
*/
string Card::getRarity() {
	return rarity;
}

/*
	Sets rarity of card.
	@param string rar Rarity which will be set.
	@return none.
*/
void Card::setRarity(string rar) {
	rarity = rar;
}

/*
	Determines if card is golden.
	@return bool TRUE if card is golden. FALSE if card is not golden.
*/
bool Card::getIsGolden() {
	if (this->isGolden) {
		return true;
	}
	else {
		return false;
	}
	return 0;
}

/*
	Sets golden quality of card.
	@param bool golden Whether or not card will be set to golden or not.
*/
void Card::setIsGolden(bool golden) {
	if (golden) {
		this->isGolden = true;
	}
	else if(!golden){
		this->isGolden = false;
	}
	else {
		this->isGolden = false;
	}
}

int Card::getValue() {
	if (this->isGolden) {
		if (this->rarity == "legendary") {
			this->totalVal = 1600;
			return this->totalVal;
		}
		else if (this->rarity == "epic") {
			this->totalVal = 400;
			return this->totalVal;
		}
		else if (this->rarity == "rare") {
			this->totalVal = 100;
			return this->totalVal;
		}
		else if (this->rarity == "common") {
			this->totalVal = 50;
			return this->totalVal;
		}
	}
	else {
		if (this->rarity == "legendary") {
			this->totalVal = 400;
			return this->totalVal;
		}
		else if (this->rarity == "epic") {
			this->totalVal = 100;
			return this->totalVal;
		}
		else if (this->rarity == "rare") {
			this->totalVal = 20;
			return this->totalVal;
		}
		else if (this->rarity == "common") {
			this->totalVal = 5;
			return this->totalVal;
		}
	}
	return 0;
}
