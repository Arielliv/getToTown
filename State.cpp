#include "State.h"

void State::buildStateStructure(int numOfPairs)
{
	int from, to;
	for (int i = 0; i < numOfPairs; i++) {
		std::cin >> from >> to;
		this->structure[from - 1].insertToEnd(to);
	}
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

void State::printColorArr() const
{
	std::cout << "Color array: ";
	for (int i = 0; i < this->numOfCities; i++) {
		std::cout << cityColors[i] << ' ';
	}
}