#include <iostream>
#include "State.h"
#include "AvailableList.h"
#include "Stack.h"

State creatState(bool & isValid);
void getUserInput(int& numOfCities, int& numOfPairs);
void getcityNumToCheckInput(int& cityNumToCheck);
void goToTownRecoursive(State& state, int cityNum, int colors[], StaticList& availableCities);
void goToTownNotRecoursive(State& state, int cityNum, int colors[], StaticList& availableCities);
void printCityResults(int cityNumToCheck, AvailableList& availableCities, bool isRecoure);

int main() {
	bool isValid = true;
	int cityNumToCheck;
	State state = creatState(isValid);
	getcityNumToCheckInput(cityNumToCheck);
	if (!isValid || cityNumToCheck > state.getNumOfCities()) {
		std::cout << "invalid input";
		return 1;
	}
	AvailableList availableCitiesRec(state.getNumOfCities());
	AvailableList availableCitiesNonRec(state.getNumOfCities());

	goToTownRecoursive(state, cityNumToCheck, availableCitiesRec.getColorArr(), availableCitiesRec.getAvailableList());
	goToTownNotRecoursive(state, cityNumToCheck, availableCitiesNonRec.getColorArr(), availableCitiesNonRec.getAvailableList());
	printCityResults(cityNumToCheck, availableCitiesRec, true);
	printCityResults(cityNumToCheck, availableCitiesNonRec, false);
}

void printCityResults(int cityNumToCheck, AvailableList& availableCities, bool isRecoure) {
	if (isRecoure) {
		std::cout << "Cities accessible from source city " << cityNumToCheck << " (recursive algorithm): ";
	}
	else {
		std::cout << "Cities accessible from city source city " << cityNumToCheck << " (iterative algorithm): ";
	}

	availableCities.getAvailableList().printList();
}

void goToTownRecoursive(State& state, int cityNum, int colors[], StaticList& availableCities) {
	if (colors[cityNum - 1] == 1) {
		return;
	}
	colors[cityNum - 1] = 1;
	availableCities.insertToEnd(cityNum);

	LNode* temp = state.getConnectedCitiesList(cityNum);
	while (temp != nullptr) {
		goToTownRecoursive(state, temp->getData().getNum(), colors, availableCities);
		temp = temp->getNext();
	}
}

void goToTownNotRecoursive(State& state, int cityNum, int colors[], StaticList& availableCities) {
	Stack recurStack = Stack();
	recurStack.MakeEmpty();

	recurStack.push(cityNum, Line::START, state.getConnectedCitiesList(cityNum));
	while (!recurStack.isEmpty()) {
		Item curItem = recurStack.pop();
		
		if (curItem.getLine() == Line::START) {
			if (colors[curItem.getCityNum() - 1] == 1) {
				
			}
			else {
				colors[curItem.getCityNum() - 1] = 1;
				availableCities.insertToEnd(curItem.getCityNum());
				
				if (curItem.getConnectedCity() != nullptr) {
					Item tmp = Item(Line::START, 
						state.getConnectedCitiesList(curItem.getConnectedCity()->getData().getNum()),
						curItem.getConnectedCity()->getData().getNum());
					curItem.setLine(Line::After);
					recurStack.push(curItem);
					recurStack.push(tmp);
				}
			}
		}
		else if (curItem.getLine() == Line::After) {
			if (curItem.getConnectedCity()->getNext() != nullptr) {
				Item tmp = Item(Line::START,
					state.getConnectedCitiesList(curItem.getConnectedCity()->getNext()->getData().getNum()),
					curItem.getConnectedCity()->getNext()->getData().getNum());
				curItem.setConnectedCity(curItem.getConnectedCity()->getNext());
				recurStack.push(curItem);
				recurStack.push(tmp);
			}
		}
	}
}

State creatState(bool& isValid) {
	int numOfCities, numOfPairs;
	getUserInput(numOfCities, numOfPairs);
	if (numOfCities < 0) {
		isValid = false;
		return NULL;
	}
	State state(numOfCities);
	isValid = state.buildStateStructure(numOfPairs);

	return state;
}

void getUserInput(int& numOfCities, int& numOfPairs) {
	//for debuging
	//std::cout << "Please enter num of cities and num of pairs\n" << ">>";
	std::cin >> numOfCities >> numOfPairs;
}

void getcityNumToCheckInput(int& cityNumToCheck) {
	//for debuging
	//std::cout << "Please enter city num to check\n" << ">>";
	std::cin >> cityNumToCheck;
}