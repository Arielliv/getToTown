#include <iostream>
#include "State.h"
#include "AvailableList.h"

int main() {
	State state = creatState();
	state.printStateStructure();

	AvailableList availableCities(state.getNumOfCities());

	goToTown(state, 5, availableCities.getColorArr(), availableCities.getAvailableList());
	availableCities.printAvailableList();
}

void goToTown(State& state, int cityNum, int colors[], StaticList& availableCities) {
	if (colors[cityNum - 1] == 1) {
		return;
	}
	colors[cityNum - 1] = 1;
	availableCities.insertToEnd(cityNum);

	LNode* temp = state.getConnectedCitiesList(cityNum);
	while (temp != nullptr) {
		goToTown(state, temp->getData().getNum(), colors, availableCities);
		temp = temp->getNext();
	}
}

State creatState() {
	int numOfCities, numOfPairs;
	getUserInput(numOfCities, numOfPairs);

	State state(numOfCities);
	state.buildStateStructure(numOfPairs);
	return state;
}

void getUserInput(int& numOfCities, int& numOfPairs) {
	std::cout << "Please enter num of cities and num of pairs\n" << ">>";
	std::cin >> numOfCities >> numOfPairs;
}