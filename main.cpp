#include <iostream>
#include "State.h"
#include "AvailableList.h"

void goToTown(State& state, int cityNum, int colors[], StaticList& availableCities);

int main() {
	int numOfCities, numOfPairs;

	std::cout << "Please enter num of cities and num of pairs\n" << ">>";
	std::cin >> numOfCities >> numOfPairs;

	State state(numOfCities);
	state.buildStateStructure(numOfPairs);
	state.printStateStructure();

	AvailableList availableCities(numOfCities);
	goToTown(state, 5, availableCities.getColorArr(), availableCities.getAvailableList());
	availableCities.getAvailableList().printList();
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