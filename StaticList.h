#pragma once
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
	/*LNode* findBefore(LNode* x);
	void insertToEnd(int x);
	void insertAfter(LNode* after, int x);
	void insertToStart(int x);
	void deleteNode(LNode* x);
	int size();
	void makeEmptylist();
	void printList() const;*/
};

