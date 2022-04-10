#include "StaticList.h"

StaticList::StaticList(int size) :headListIndex(-1), freeListIndex(0) {
	this->list.reserve(size);
	for (int i = 1; i < size; i++) {
		this->list.push_back(SNode(0, i));
	}
	this->list.push_back(SNode(0, -1));
};

bool StaticList::insert(SNode* newNode) {
	if(this->freeListIndex == -1){
		return false;
	}
	else {
		if (this->headListIndex == -1) {
			int tmpIndex = this->list[this->freeListIndex].getNext();
			newNode.setNext(-1);
			this->list[this->freeListIndex] = newNode;
			this->headListIndex = this->freeListIndex;
			this->freeListIndex = tmpIndex;
			
		}
		else {
				int tmpIndex = this->list[this->freeListIndex].getNext();
				newNode.setNext(this->headListIndex);
				this->list[this->freeListIndex] = newNode;
				this->freeListIndex = tmpIndex;
		}
		return true;
	}
};
bool StaticList::deleteNode(SNode* node) {
	if (this->freeListIndex == -1) {
		return false;
	}
	SNode* cur = this->list[this->headListIndex];
	while (cur->getNext() != -1) {
		if (this->list[cur->getNext()] == node) {
			int newfreeListIndex = cur->getNext()
			cur->setNext(node->getNext());
			node.setNext(this->freeListIndex);
			this->freeListIndex = newfreeListIndex;
		}
	}
	return true;

};