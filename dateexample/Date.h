#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	Date();
	Date(int aDate);
	int getDate();
	int getYear();
	int getMonth();
	int getDay();
	int getQuarter();
	bool leapYear();
	bool validate();
	int daysInYear();
	int daysLeft();
	void incDate();
	void decDate();
	int dateDiff(Date aDate);
	int weekDay();
	string weekdaytext();
	void print();
	~Date();
private:
	int theDate;	//Format YYYYMMDD
	int array[8];
};

