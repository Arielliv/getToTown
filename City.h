#pragma once
class City
{
	int num;
public:
	City() = delete;
	City(int data) : num(data) {};
	int getNum() const;
	void setNum(int num);
};

