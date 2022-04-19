#pragma once
#include "StaticList.h"

class AvailableList
{
	int* colors;
	StaticList available;

public:
	AvailableList(int n) : available(StaticList(n)){
		this->colors = new int[n] {};
	}

	~AvailableList() { delete this->colors; }

	int getCityColor(int cityNum)
	{
		return this->colors[cityNum - 1];
	}

	void setCityColorToBlack(int cityNum) {
		this->colors[cityNum - 1] = 1;
	}

	void insert(City city) {
		this->available.insertToEnd(city.getNum());
	}
	
	StaticList& getAvailableList() {
		return this->available;
	}

	int* getColorArr() {
		return this->colors;
	}
};

