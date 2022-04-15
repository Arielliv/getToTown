#include <iostream>
#include "State.h"
#include "AvailableList.h"
#include "Stack.h"

State creatState(bool & isValid);
void getUserInput(int& numOfCities, int& numOfPairs);
void getcityNumToCheckInput(int& cityNumToCheck);
void goToTownRecoursive(State& state, int cityNum, int colors[], StaticList& availableCities);
void goToTownNotRecoursive(State& state, int cityNum, int colors[], StaticList& availableCities);

int main() {
	bool isValid = true;
	int cityNumToCheck;
	State state = creatState(isValid);
	getcityNumToCheckInput(cityNumToCheck);
	if (!isValid) {
		std::cout << "output =invalid input";
		return 1;
	}
	AvailableList availableCities(state.getNumOfCities());
	AvailableList availableCitiesRec(state.getNumOfCities());

	goToTownRecoursive(state, cityNumToCheck, availableCities.getColorArr(), availableCities.getAvailableList());
	goToTownNotRecoursive(state, cityNumToCheck, availableCitiesRec.getColorArr(), availableCitiesRec.getAvailableList());
	std::cout << "output =";
	std::cout << "Cities accessible from source city" << cityNumToCheck << "(recursive algorithm): ";
	availableCities.getAvailableList().printList();
	std::cout << "Cities accessible from source city" << cityNumToCheck << "(iterative algorithm): ";
	availableCitiesRec.getAvailableList().printList();
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
				//curItem.setConnectedCity(state.getConnectedCitiesList(curItem.getCityNum()));
				
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

	State state(numOfCities);
	isValid = state.buildStateStructure(numOfPairs);

	return state;
}

void getUserInput(int& numOfCities, int& numOfPairs) {
	std::cout << "Please enter num of cities and num of pairs\n" << ">>";
	std::cin >> numOfCities >> numOfPairs;
}

void getcityNumToCheckInput(int& cityNumToCheck) {
	std::cout << "Please enter city num to check\n" << ">>";
	std::cin >> cityNumToCheck;
}