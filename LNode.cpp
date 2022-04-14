#include "LNode.h"
LNode* LNode::getNext()
{
	return this->next;
}

bool LNode::operator==(const LNode& node) const
{
	return this->data.getNum() == node.data.getNum();
}

City LNode::getData() 
{
	return this->data;
}

void LNode::setNext(LNode* next) 
{
	this->next = next;
}