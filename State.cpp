#include "State.h"

bool State::buildStateStructure(int numOfPairs)
{
	int from, to;
	int counter = 0;
	std::string line;

	std::cin.ignore();
	std::getline(std::cin, line);
	std::stringstream ss(line);

	while (ss >> from >> to) {
		if (counter < numOfPairs && (from > 0 && from <= this->numOfCities) && (to > 0 && to && to <= this->numOfCities)) {
			this->structure[from - 1].insertToEnd(to);
		}
		else {
			return false;
		}
		counter++;
	 }
	
	return true;
}

void State::printStateStructure() const
{
	for (int i = 0; i < this->numOfCities; i++)
	{
		std::cout << "City num " << i + 1 << " : ";
		this->structure[i].printList();
		std::cout << std::endl;
	}
}

LNode* State::getConnectedCitiesList(int cityNum) {
	return this->structure[cityNum -1].first();
}

int State::getNumOfCities() {
	return this->numOfCities;
}