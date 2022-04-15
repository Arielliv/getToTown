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

void Stack::push(int data) {
	this->topItem = new StackItem(data, this->topItem);
}

int Stack::pop() {
	if (this->isEmpty()) {
		std::cout << "error" << std::endl;
	}
	StackItem* tmp = this->topItem;
	int data = tmp->getData();
	this->topItem = this->topItem->getNext();
	delete tmp;
	return data;
}

StackItem* Stack::top() {
	return this->topItem;
}