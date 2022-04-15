#include "Item.h"

int Item::getCityNum() {
	return this->cityNum;
}

Line Item::getLine() {
	return this->line;
}

LNode* Item::getConnectedCity() {
	return this->connectedCity;
}

void Item::setCityNum(int cityNum) {
	this->cityNum = cityNum;
}

void Item::setLine(Line line) {
	this->line = line;
};

void Item::setConnectedCity(LNode* city) {
	this->connectedCity = city;
}

bool Item::operator==(const Item& item) const {
	return this->cityNum == item.cityNum && this->line == item.line && this->connectedCity == item.connectedCity;
}