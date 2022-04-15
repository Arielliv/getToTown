#include "StackItem.h"

StackItem* StackItem::getNext() {
	return this->next;
}

int StackItem::getData() {
	return this->data;
}

void StackItem::setNext(StackItem* next) {
	this->next = next;
}

bool StackItem::operator==(const StackItem& item) const {
	return this->data == item.data && this->next == item.next;
}

StackItem& StackItem::operator=(const StackItem& item) {
	this->data = item.data;
	this->next = item.next;
}