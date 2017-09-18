#include "stdafx.h"
#include "Date.h"
#include <iostream>
using namespace std;

Date::Date()
{
}

Date::Date(int aDate)
{
	theDate = aDate;
	for (int i = 7; i >= 0; i--)
	{
		array[i] = theDate % 10;
		theDate = theDate / 10;
	}
}

int Date::getDate()
{
	int a = (array[0] * 10000000) + (array[1] * 1000000) + (array[2] * 100000) + (array[3] * 10000) + (array[4] * 1000) + (array[5] * 100) + (array[6] * 10) + array[7];
	return a;
}

int Date::getYear()
{
	int a = (array[0] * 1000) + (array[1] * 100) + (array[2] * 10) + array[3];
	return a;
}

int Date::getMonth()
{
	int a = (array[4] * 10 + array[5]);
	return a;
}

int Date::getDay()
{
	int a = (array[6] * 10 + array[7]);
	return a;
}

int Date::getQuarter()
{
	return (getMonth() + 1) / 3 + 1;
}

bool Date::leapYear()
{
	if (getYear() % 4 == 0 && getYear() % 100 != 0)
	{
		return true;
	}
	else if (getYear() % 400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::validate()
{
	if (getYear() >= 0 && getYear() < 10000)
	{
		if (getMonth() > 0 && getMonth() < 13)
		{
			if (getMonth() % 2 != 0 && getMonth() < 8 && getMonth() != 2)
			{
				if (getDay() > 0 && getDay() <= 31)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if (getMonth() % 2 == 0 && getMonth() < 8 && getMonth() != 2)
			{
				if (getDay() > 0 && getDay() <= 30)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if (getMonth() % 2 == 0 && getMonth() > 7 && getMonth() != 2)
			{
				if (getDay() > 0 && getDay() <= 31)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if (getMonth() % 2 != 0 && getMonth() > 7 && getMonth() != 2)
			{
				if (getDay() > 0 && getDay() <= 30)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if (getMonth() == 2)
			{
				if ((getDay() > 0 && getDay() <= 28) || (getDay() == 29 && leapYear() == true))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int Date::daysInYear()
{
	int days = 0;
	switch (getMonth())
	{
	case 1 || 2:	days = getDay();
		break;
	case 2:	days = 31 + getDay();
		break;
	case 3:	days = 59 + getDay();
		break;
	case 4:	days = 90 + getDay();
		break;
	case 5:	days = 120 + getDay();
		break;
	case 6:	days = 151 + getDay();
		break;
	case 7:	days = 181 + getDay();
		break;
	case 8:	days = 212 + getDay();
		break;
	case 9:	days = 243 + getDay();
		break;
	case 10: days = 273 + getDay();
		break;
	case 11: days = 304 + getDay();
		break;
	case 12: days = 334 + getDay();
		break;
	}
	if (leapYear() && getMonth() > 2)
	{
		return days + 1;
	}
	else
	{
		return days;
	}
}

int Date::daysLeft()
{
	if (leapYear())
	{
		return 366 - daysInYear();
	}
	else
	{
		return 365 - daysInYear();
	}
}

void Date::incDate()
{
	array[7] = array[7] + 1;
	int a = getDate();
	int b = 0;
	while (!validate())
	{
		a++;
		b = a;
		for (int i = 7; i >= 0; i--)
		{
			array[i] = b % 10;
			b = b / 10;
		}
	}
	/*array[7] = array[7] + 1;
	if (validate() == false)
	{
		array[7] = 1;
		array[6] = array[6] + 1;
		if (validate() == false)
		{
			array[6] = 0;
			array[5] = array[5] + 1;
			if (validate() == false)
			{
				array[5] = 1;
				array[4] = array[4] + 1;
				if (validate() == false)
				{
					array[4] = 0;
					array[3] = array[3] + 1;
					if (validate() == false)
					{
						array[3] = 0;
						array[2] = array[2] + 1;
						if (validate() == false)
						{
							array[2] = 0;
							array[1] = array[1] + 1;
							if (validate() == false)
							{
								array[1] = 0;
								array[0] = array[0] + 1;
								if (validate() == false)
								{
									array[0] = 0;
								}
							}
						}
					}
				}
			}
		}
	}*/
}

void Date::decDate()
{
	array[7] = array[7] - 1;
	int a = getDate();
	int b = 0;
	while (!validate())
	{
		a--;
		b = a;
		for (int i = 7; i >= 0; i--)
		{
			array[i] = b % 10;
			b = b / 10;
		}
	}
}

int Date::dateDiff(Date aDate)
{
	Date tempDate(getDate());
	int diff = 0;
	if (aDate.getDate() < tempDate.getDate())
	{
		while (aDate.getDate() != tempDate.getDate() - 1)
		{
			tempDate.decDate();
			diff++;
		}
	}
	else
	{
		while (aDate.getDate() != tempDate.getDate() + 1)
		{
			tempDate.incDate();
			diff++;
		}
	}
	tempDate.~Date();
	return diff;
}

int Date::weekDay()
{
	Date baseDate(20010101);
	auto temp = dateDiff(baseDate) % 7;
	switch (temp)
	{
	case 0:
		return 1;
		break;
	case 1:
		return 2;
		break;
	case 2:
		return 3;
		break;
	case 3:
		return 4;
		break;
	case 4:
		return 5;
		break;
	case 5:
		return 6;
		break;
	case 6:
		return 7;
		break;
		return 0;
	}
}

Date::~Date()
{
}
