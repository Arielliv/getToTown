#include <iostream>
#include "State.h"

int main() {
	int numOfCities, numOfPairs;

	std::cout << "Please enter num of cities and num of pairs\n" << ">>";
	std::cin >> numOfCities >> numOfPairs;

	State state(numOfCities);
	state.buildStateStructure(numOfPairs);
	state.printStateStructure();
	state.printColorArr();
}