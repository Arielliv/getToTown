#include "StackItem.h"

StackItem* StackItem::getNext() {
	return this->next;
}

Item StackItem::getItem() {
	return this->item;
}

void StackItem::setNext(StackItem* next) {
	this->next = next;
}

bool StackItem::operator==(const StackItem& stackItem) const {
	return this->item == stackItem.item && this->next == stackItem.next;
}

StackItem& StackItem::operator=(const StackItem& item) {
	this->item = item.item;
	this->next = item.next;
	return *this;
}