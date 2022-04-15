#pragma once
#include "City.h"
class LNode
{
private:
	City data;
	LNode* next;
public: 
	LNode() : next(nullptr) {};
	LNode(int data, LNode* ptr = nullptr) : data(City(data)), next(nullptr) {};
	LNode* getNext();
	City getData();
	void setNext(LNode* next);

	bool operator==(const LNode& node) const;
};

