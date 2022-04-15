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
	void insertToEnd(int x);
	void insertAfter(SNode* after, int x);
	void insertToStart(int x);
	void deleteNode(SNode* x);
	int size();
	//void makeEmptylist();
	void printList() const;
};

