// dateexample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Date.h"
#include <iostream>

using namespace std;

void main()
{
	Date mydate(20010102);
	Date newDate(20010108);
	cout << mydate.getDate() << endl;
	cout << mydate.getYear() << endl;
	cout << mydate.getMonth() << endl;
	cout << mydate.getDay() << endl;
	cout << mydate.getQuarter() << endl;
	cout << mydate.leapYear() << endl;
	cout << mydate.validate() << endl;
	cout << mydate.daysInYear() << endl;
	cout << mydate.daysLeft() << endl;
	cout << mydate.getDate() << endl;
	mydate.decDate();
	cout << mydate.getDate() << endl;
	cout << newDate.getDate() << endl;
	cout << mydate.dateDiff(newDate) << endl;
	cout << mydate.weekDay() << endl;
}

