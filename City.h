#pragma once
class City
{
	int num;
public:
	City() {};
	City(int data) : num(data) {};
	int getNum() const;
	void setNum(int num);
};

