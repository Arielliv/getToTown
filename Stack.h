#pragma once
#include <iostream>
#include "StackItem.h"
#include "Item.h"

class Stack
{
private:
	StackItem* topItem;
public:
	Stack();
	~Stack();
	void MakeEmpty();
	bool isEmpty();
	void push(int cityNum, Line line, LNode* connectedCity);
	void push(Item item);
	Item pop();
	StackItem* top();
};

