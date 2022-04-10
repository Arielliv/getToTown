#pragma once
class LNode
{
	int data;
	LNode* next;
public: 
	LNode() :next(nullptr) {};
	LNode(int data, LNode* ptr = nullptr);
	int getData();
	LNode* getNext();
	void setData(int data);
	void setNext(LNode* next);
	void insertAfter(LNode* newNode);
	LNode* deleteAfter();
	void print();
};

