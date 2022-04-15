#pragma once

#include "StackItem.h"

class Stack
{
private:
	StackItem* topItem;
public:
	Stack();
	~Stack();
	void MakeEmpty();
	bool isEmpty();
	void push(int data);
	int pop();
	StackItem* top();
};

