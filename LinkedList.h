#pragma once

#include  "LNode.h"

class LinkedList
{
	LNode* head;
	LNode* tail;
public :
	LinkedList() { head = tail = nullptr; }
	void makeEmpty();
	bool isEmpty();
	LNode* first();
	LNode* last();
	LNode* find(int data);
	void insertAfter(LNode* after, LNode* newNode);
	void deleteNode(LNode* node);
	void print();
	int size();
};

