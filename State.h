#pragma once

#include <iostream>
#include "LinkedList.h"

class State
{
	int numOfCities;
	LinkedList* structure;
	int* cityColors;

public:
	State(int num) : numOfCities(num) {
		this->structure = new LinkedList[num];
		this->cityColors = new int[num] {};
	};

	void buildStateStructure(int numOfPairs);
	void printStateStructure()const;
	void printColorArr() const;
	
};

