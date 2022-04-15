#pragma once
#include "Item.h"

class StackItem
{
private:
	Item item;
	StackItem* next;
public:
	StackItem(Item item, StackItem* ptr = nullptr) : item(item), next(ptr) {};
	StackItem* getNext();
	Item getItem();
	void setNext(StackItem* next);

	bool operator==(const StackItem& stackItem) const;
	StackItem& operator=(const StackItem& item);
};

