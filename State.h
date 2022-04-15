#pragma once

#include <iostream>
#include "LinkedList.h"
#include "AvailableList.h"

class State
{
	int numOfCities;
	LinkedList* structure;

public:
	State() {};
	State(int num) : numOfCities(num) {
		this->structure = new LinkedList[num];
	};

	void buildStateStructure(int numOfPairs);
	void printStateStructure()const;
	LNode* getConnectedCitiesList(int cityNum);
	int getNumOfCities();
};

