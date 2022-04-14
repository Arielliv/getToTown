#include "LinkedList.h"

bool LinkedList::isEmpty() const
{
	return this->head == nullptr;
}

LNode* LinkedList::first()
{
	if (isEmpty()) {
		return nullptr;
	}
	return this->head;
}

LNode* LinkedList::last()
{
	if (isEmpty())
		return nullptr;

	LNode* ptr = this->head;
	LNode* next = this->head->getNext();
	while (next != nullptr)
	{
		ptr = next;
		next = ptr->getNext();
	}
	return ptr;
}

LNode* LinkedList::find(int cityNum) 
{
	LNode* ptr = this->head;

	while (ptr != nullptr)
	{
		if(ptr->getData().getNum() == cityNum)
		{
			break;
		}
		ptr = ptr->getNext();
	}
	return ptr;
}

void LinkedList::insertToEnd(int x)
{
	LNode* newNode = new LNode(x, nullptr);

	if (isEmpty()) {
		head = newNode;
	}
	else
	{
		LNode* ptr = this->head;
		while (ptr->getNext() != nullptr)
		{
			ptr = ptr->getNext();
		}
		ptr->setNext(newNode);
	}
	this->length++;
}

void LinkedList::insertAfter(LNode* after, int x)
{
	LNode* newNode = new LNode(x, nullptr);

	if (after == nullptr) {
		newNode->setNext(this->head);
		this->head = newNode;
	}
	else
	{
		newNode->setNext(after->getNext());
		after->setNext(newNode);
	}
	this->length++;
}

void LinkedList::insertToStart(int x)
{
	LNode* newNode = new LNode(x, nullptr);

	if(isEmpty())
	{
		this->head = newNode;
	}
	else
	{
		newNode->setNext(this->head);
		head = newNode;
	}

	this->length++;
}

LNode* LinkedList::findBefore(LNode* x)
{
	LNode* ptr = this->head;
	LNode* next = this->head->getNext();
	while (ptr != nullptr)
	{
		if (next == x) {
			break;
		}
		ptr = next;
		next = next->getNext();
	}
	return next;;
}

void LinkedList::deleteNode(LNode* x)
{
	LNode* before = findBefore(x);
	
	if (before == nullptr) {
		this->head = x->getNext();
	}
	else
	{
		before->setNext(x->getNext());
	}

	delete x;
	length--;
}

int LinkedList::size() {
	return this->length;
}

LinkedList::~LinkedList()
{
	LNode* ptr1 = this->head;
	LNode* ptr2 = ptr1->getNext();
	
	while (ptr2 != nullptr) 
	{
		delete ptr1;
		ptr1 = ptr2;
		ptr2 = ptr2->getNext();
	}
	delete ptr1; //Delete the last node;
}

void LinkedList::makeEmptylist()
{
	this->head = nullptr;
}

void LinkedList::printList() const
{
	LNode* ptr = this->head;

	while (ptr != nullptr) {
		std::cout << ptr->getData().getNum() << ' ';
		ptr = ptr->getNext();
	}
}