// Author:		Logan Hammond; hamm32637@email.ccbcmd.edu
// Source File: Pack.h
// Description: Header file for Pack class. A pack is a collection of five Card objects.
//				The chances of Legendary cards increases if the pack is one of the first
//				of 10 opened (of that individual set).
// IDE:			Microsoft Visual Studio 2017

#include <iostream>
#include "Card.h"
using namespace std;
#pragma once

class Pack {
private:
	bool isInFirst10;

public:
	Card contents[5];

	// Constructor.
	Pack(bool isFirst10 = false) {
		this->isInFirst10 = isFirst10;
	}

	//Destructor.
	~Pack() {

	}

	// Function declarations.
	bool getIsInFirst10();
	Card getContents();
};

