#pragma once
class StackItem
{
private:
	int data;
	StackItem* next;
public:
	StackItem(): data(0), next(nullptr) {};
	StackItem(int data, StackItem* ptr = nullptr) : data(data), next(ptr) {};
	StackItem* getNext();
	int getData();
	void setNext(StackItem* next);

	bool operator==(const StackItem& item) const;
	StackItem& operator=(const StackItem& item);
};

