#include "LinkedList.h"

bool LinkedList::isEmpty() {
	if (this->head == nullptr)
	{
		return true;
	}
	else {
		return false;
	}
};

LNode* LinkedList::first() {
	return this->head;
};

LNode* LinkedList::last() {
	return this->tail;
}

LNode* LinkedList::find(int data) {
	LNode* cur = this->head;
	
	while (cur != nullptr) {
		if (cur->getData() == data) {
			return cur;
		}
		cur = cur->getNext();
	}
	return cur;	
}

void LinkedList::insertAfter(LNode* after, LNode* newNode) {
	if(after == nullptr){
		newNode->setNext(this->head);
		this->head = newNode;
	}
	else {
		newNode->setNext(after->getNext());
		after->setNext(newNode);
	}
	if (after == this->tail) {
		this->tail = newNode;
	}
}

void LinkedList::deleteNode(LNode* node) {
	if (node == nullptr) {
		return;
	}
	LNode* cur = this->head;

	while (cur != nullptr) {
		if (cur->getNext() == node) {
			cur->setNext(node->getNext());
			break;
		}
		cur = cur->getNext();
	}
	if (node == this->head) {
		this->head = node->getNext();
	}
	if (node == this->tail) {
		this->tail = cur;
	}

	delete node;
}

void LinkedList::print() {
	LNode* cur = this->head;

	while (cur != nullptr) {
		cur->print();
		cur = cur->getNext();
	}
}

int LinkedList::size() {
	int counter = 0;
	LNode* cur = this->head;

	while (cur != nullptr) {
		counter++;
		cur = cur->getNext();
	}

	return counter;
};
