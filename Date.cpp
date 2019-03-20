// Date.cpp

#include<iostream>
#include<string>
#include<cstdlib>
#include "Date.h"
using namespace std;

//string of the months arrays
string monthNames[12] = { "January", "February", "March", "April", "May", "June",
					"July", "August", "September", "October", "November", "December" };
//Unique days of certain months.
int lastDaysOfMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//default constructor
Date::Date()
{
	month = 0;
	day = 0;
	year = 0;
}
//sets the month from user input value and checks if the month is valid
void Date::setMonth(int userSelectedMonth)
{
	if (userSelectedMonth > 0 && userSelectedMonth<= 12)
	{
		month = userSelectedMonth;
	}
	else
	{
		cout << "Invalid month\n.";
		exit(1);
	}
}
void Date::setDay(int userSelectedDay)
{		//if day < 1        or       month is not 2 and if userDay > last day of that month
	if (userSelectedDay < 1 || (month != 2 && userSelectedDay > lastDaysOfMonth[month]) || 
		//special case of leap year
		(userSelectedDay > 29 && month == 2) || 
		//if day is 29 is Feb and it is not a leap year 
		(userSelectedDay == 29 && month == 2 && !leapYearCheck(year)))
	{
		cout << "Invalid day\n";
		exit(2);
	}
	else
	{
		day = userSelectedDay;
	}
}
void Date::setYear(int userYear)
{
	//year is not negative
	if (userYear > 0)
	{
		year = userYear;
	}
	else
	{
		cout << "Invalid year\n";
		exit(3);
	}
}
//check if the year is leap uses steps to determine whether a year is a leap year
bool Date::leapYearCheck(int year)
{
	//if year is evenly divisible 
	if (year % 400 == 0)
		return true;
	//if year is evenly divisible
	else if (year % 100 == 0)
		return false;
	//if year is evenly divisible
	else if (year % 4 == 0)
		return true;
	else
		return false;
}
//Adds the dates
void Date::addDates()
{
	//checks if the date is maxed for the month
	if (day > lastDaysOfMonth[month] && !(day == 29 && month == 2 && leapYearCheck(year)))
	{	
		//new month and day is reset
		day = 1;
		month++;
		//increments to next year 
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
}
void Date::subtractDates()
{
	if (day == 0)
	{
		if (month == 3 && leapYearCheck(year))
		{
			day = lastDaysOfMonth[month - 1] + 1;
			month--;
		}
		else if (month > 1)
		{
			day = lastDaysOfMonth[month - 1];
			month--;
		}
		else
		{
			day = lastDaysOfMonth[month] + day;
			month = 12;
			year--;
		}
	}
}
Date::Date(int month, int day, int year)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}
Date Date::operator++()
{
	++day;
	addDates();
	return *this;
}
Date Date::operator++(int)
{
	Date newMonth(month, day, year);
	day++;
	addDates();
	return newMonth;
}
Date Date::operator--()
{
	--day;
	subtractDates();
	return *this;
}
Date Date::operator--(int)
{
	Date newMonth(month, day, year);
	day--;
	subtractDates();
	return newMonth;
}
int Date::operator-(const Date &alternateDate)
{
	if (month < 3)
	{
		year--;
		month += 12;
	}
	int first = 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
	int userDay = alternateDate.day;
	int userMonth = alternateDate.month;
	int userYear = alternateDate.year;
	if (userMonth < 3)
	{
		userYear--;
		userMonth += 12;
	}
	int second = 365 * userYear + userYear / 4 - userYear / 100 + userYear / 400 + (153 * userMonth - 457) / 5 + userDay - 306;
	return abs(first - second);
}
//takes in user input 
istream &operator>>(istream &input, Date& dateHolder)
{
	int inputDay;
	int inputMonth;
	int inputYear;
	cin >> inputMonth >> inputDay >> inputYear;
	/* modification: call setYear() function first */
	dateHolder.setYear(inputYear);
	dateHolder.setMonth(inputMonth);
	dateHolder.setDay(inputDay);
	return input;
}
ostream &operator<<(ostream &output, const Date& dateHolder)
{
	output << dateHolder.month << "/" << dateHolder.day << "/" << dateHolder.year << endl;
	output << monthNames[dateHolder.month - 1] << " " << dateHolder.day << ", " << dateHolder.year << endl;
	output << dateHolder.day << " " << monthNames[dateHolder.month - 1] << " " << dateHolder.year << endl;
	return output;
}