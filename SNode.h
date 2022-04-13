#pragma once
#include "City.h"

class SNode
{
	City data;
	int next;
public:
	SNode(int next = -1) : next(next) {};
	SNode(int data, int next) : data(City(data)), next(next) {};
	int getNext() const;
	City getData() const;
	void setNext(int next);
};

