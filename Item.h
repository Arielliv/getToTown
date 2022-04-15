#pragma once
#include "LNode.h"

enum class Line { START = 1, After = 2 };

class Item
{
private:
	int cityNum;
	LNode* connectedCity;
	Line line;
public:
	Item(Line line, LNode* connectedCity, int cityNum = 0): cityNum(cityNum), line(Line::START), connectedCity(connectedCity) {};
	int getCityNum();
	Line getLine();
	LNode* getConnectedCity();
	void setCityNum(int cityNum);
	void setLine(Line line);
	void setConnectedCity(LNode* city);
	bool operator==(const Item& item) const;
};

