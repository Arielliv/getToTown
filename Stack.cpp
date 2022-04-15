#include "Stack.h"

Stack::Stack() {
	this->topItem = nullptr;
}

Stack::~Stack() {
	this->MakeEmpty();
}

void Stack::MakeEmpty() {
	StackItem* tmp;
	while (this->topItem != nullptr)
	{
		tmp = this->topItem;
		this->topItem = this->topItem->getNext();
		delete tmp;
	}
}

bool Stack::isEmpty() {
	return this->topItem == nullptr;
}

void Stack::push(int cityNum, Line line, LNode* connectedCity) {
	this->topItem = new StackItem(Item(line, connectedCity,cityNum), this->topItem);
}

void Stack::push(Item item) {
	this->topItem = new StackItem(item, this->topItem);
}

Item Stack::pop() {
	if (this->isEmpty()) {
		std::cout << "error in stack" << std::endl;
	}
	StackItem* tmp = this->topItem;
	Item item = tmp->getItem();
	this->topItem = this->topItem->getNext();
	delete tmp;
	return item;
}

StackItem* Stack::top() {
	return this->topItem;
}