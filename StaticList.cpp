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
		SNode temp = arr[headList];
		int next = temp.getNext();
		while (next != -1) {
			temp = arr[next];
			next = temp.getNext();
		}
		return &temp;
	}
}

SNode* StaticList::find(int cityNum) {
	SNode temp = this->arr[headList];
	int next = temp.getNext();
	while (next != -1)
	{
		if (temp.getData().getNum() == cityNum) {
			break;
		}
		temp = arr[next];
		next = temp.getNext();
	}
	return &temp;
}