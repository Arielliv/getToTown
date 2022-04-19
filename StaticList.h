#pragma once
#include <iostream>
#include "SNode.h"

class StaticList
{
	int headFree;
	int headList;
	SNode* arr;

public:

	StaticList(int size);
	~StaticList();
	bool isEmpty() const;
	SNode* first();
	SNode* last();
	SNode* find(int cityNum);
	SNode* findBefore(int cityNum);
	bool insertToEnd(int x);
	bool insertAfter(SNode* after, int x);
	bool insertToStart(int x);
	void deleteNode(SNode* x);
	int size();
	void makeEmptylist();
	void printList() const;
};

