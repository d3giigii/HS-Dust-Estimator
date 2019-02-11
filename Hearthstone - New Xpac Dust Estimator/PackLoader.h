// Author:		Logan Hammond; hamm32637@email.ccbcmd.edu
// Source File: PackLoader.h
// Description: Header file for PackLoader class. The PackLoader determines what rarity, 
//				and golden quality of Card object is put into Pack object. PackLoader also
//				is responsible for determining whether or not the packs being opened are
//				within the first 10 of a new set.
// IDE:			Microsoft Visual Studio 2017

#include <iostream>
#include <vector>
#include "Card.h"
#include "Pack.h"
using namespace std;
#pragma once

class PackLoader {
public:
	Pack loadPackAvg(bool);
	vector<Pack> loadPackWorst(int, bool);

	// Constructor
	PackLoader() {

	}

	// Destructor
	~PackLoader() {

	}

private:

	

};

