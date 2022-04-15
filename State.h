#pragma once

#include <iostream>
#include "LinkedList.h"
#include "AvailableList.h"
#include <vector>
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>

class State
{
	int numOfCities;
	LinkedList* structure;

public:
	State() {};
	State(int num) : numOfCities(num) {
		this->structure = new LinkedList[num];
	};

	bool buildStateStructure(int numOfPairs);
	void printStateStructure()const;
	LNode* getConnectedCitiesList(int cityNum);
	int getNumOfCities();
};

