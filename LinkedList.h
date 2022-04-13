#pragma once
#include <iostream>
#include "LNode.h"

class LinkedList
{
	LNode* head;
	int length = 0;

public:
	LinkedList(LNode* _head = nullptr) : head(_head) { 
		if (_head != nullptr)
			length++;
	};
	~LinkedList();
	bool isEmpty() const;
	LNode* first();
	LNode* last();
	LNode* find(int cityNum);
	LNode* findBefore(LNode* x);
	void insertToEnd(int x);
	void insertAfter(LNode* after, int x);
	void insertToStart(int x);
	void deleteNode(LNode* x);
	int size();
	void makeEmptylist();
	void printList() const;
};

