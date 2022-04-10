#pragma once

#include "SNode.h"
#include <vector>

class StaticList
{
	int headListIndex;
	int freeListIndex;
	std::vector<SNode> list;
public:
	StaticList(int size):headListIndex(-1), freeListIndex(0){};
	void makeEmpty();
	bool isEmpty();
	LNode* first();
	LNode* last();
	LNode* find(int data);
	bool insert(SNode* newNode);
	bool deleteNode(SNode* node);
	void print();
	int size();
};

