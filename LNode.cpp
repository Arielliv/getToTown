#include "LNode.h"

LNode::LNode(int data, LNode* ptr = nullptr) :data(data), next(ptr) {};

void LNode::insertAfter(LNode* newNode) {
	newNode->next = this->next;
	this->next = newNode;
}

LNode* LNode::deleteAfter() {
	LNode* toDelete = next;
	if (toDelete == nullptr) {
		return nullptr;
	}
	else {
		this->next = toDelete->next;
		return toDelete;
	}
}

int LNode::getData() {
	return this->data;
}

LNode* LNode::getNext() {
	return this->next;
}

void LNode::setData(int data) {
	this->data = data;
}

void LNode::setNext(LNode* next) {
	this->next = next;
}

void LNode::print() {};