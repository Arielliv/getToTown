#include "SNode.h"

City SNode::getData() const
{
	return this->data;
}

int SNode::getNext() const
{
	return this->next;
}

void SNode::setNext(int next) {
	this->next = next;
}