#include "StaticList.h"

StaticList::StaticList(int size) 
{
	this->arr = new SNode[size];
	this->headList = -1;
	this->headFree = 0;

	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			arr[i].setNext(-1);
		}
		else {
			arr[i].setNext(i + 1);
		}
	}
}

void StaticList::makeEmptylist() {
	this->headList = -1;
	this->headFree = 0;
}

StaticList::~StaticList()
{
	delete arr;
}

bool StaticList::isEmpty() const
{
	return this->headList == -1;
}

SNode* StaticList::first()
{
	if (isEmpty()) {
		return nullptr;
	}
	else {
		return arr + headList;
	}
}

SNode* StaticList::last() {
	if (isEmpty()) {
		return nullptr;
	}
	else
	{
		int temp = this->headList;
		int next = arr[headList].getNext();
		while (next != -1) {
			temp = next;
			next = arr[temp].getNext();
		}
		return arr + temp;
	}
}

SNode* StaticList::find(int cityNum) {
	if (isEmpty()) {
		return nullptr;
	}

	int temp = this->headList;
	while (temp != -1)
	{
		if (arr[temp].getData().getNum() == cityNum) {
			break;
		}
		temp = arr[temp].getNext();
	}
	return arr + temp;
}

SNode* StaticList::findBefore(int cityNum)
{
	if (isEmpty()) {
		return nullptr;
	}
	int temp = this->headList;
	int next = this->arr[headList].getNext();
	while (next != -1)
	{
		if (arr[next].getData().getNum() == cityNum) {
			break;
		}
		temp = next;
		next = arr[temp].getNext();
	}
	return arr + temp;
}

bool StaticList::insertToEnd(int x) 
{
	if (this->headFree == -1) {
		//return exception
		return false;
	}
	if (isEmpty()) {
		this->headList = this->headFree;
		this->headFree = arr[headList].getNext();
		arr[headList].setNext(-1);
		arr[headList].setData(x);
	}
	else if (arr[this->headFree].getNext() == -1) {
		SNode* lastItem = last();
		lastItem->setNext(this->headFree);
		arr[headFree].setData(x);
		arr[headFree].setNext(-1);
		this->headFree = -1;
	}
	else {
		
		SNode* lastItem = last();
		lastItem->setNext(this->headFree);
		int saver = this->headFree;
		this->headFree = arr[headFree].getNext();
		arr[saver].setData(x);
		arr[saver].setNext(-1);
	}
	return true;
}

bool StaticList::insertAfter(SNode* after, int x)
{
	if (this->headFree == -1) {
		//return exception
		return false;
	}

	if (after == last()) {
		insertToEnd(x);
	}
	else
	{
		int nextAfter = after->getNext();
		int saver = this->headFree;
		after->setNext(this->headFree);
		this->headFree = arr[headFree].getNext();
		arr[saver].setData(x);
		arr[saver].setNext(nextAfter);
	}
	return true;
}

bool StaticList::insertToStart(int x) {
	if (this->headFree == -1) {
		//return exception
		return false;
	}
	if (isEmpty()) {
		insertToEnd(x);
	}
	else {
		int saver = this->headFree;
		this->headFree = arr[headFree].getNext();
		arr[saver].setNext(this->headList);
		arr[saver].setData(x);
		this->headList = saver;
	}
	return true;
}

void StaticList::deleteNode(SNode* x){
	
	if (x == first()) 
	{
		int saver = this->headList;
		this->headList = x->getNext();
		x->setNext(this->headFree);
		this->headFree = saver;
	}
	else {
		SNode* before = findBefore(x->getData().getNum());
		int saver = before->getNext();
		before->setNext(x->getNext());
		x->setNext(this->headFree);
		this->headFree = saver;
	}
}

int StaticList::size()
{
	int counter = 0;
	int temp = this->headList;

	while (temp != -1)
	{
		counter++;
		temp = arr[temp].getNext();
	}
	return counter;
}

void StaticList::printList() const {
	int temp = this->headList;
	while (temp != -1) {
		std::cout << arr[temp].getData().getNum() << ' ';
		temp = arr[temp].getNext();
	}
	std::cout << std::endl;
}