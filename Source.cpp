#include<iostream>
#include<string>
#include "Date.h"
using namespace std;
int main()
{
	Date date;
	cout << "Please enter a date following the format with spaces (month day year): ";
	cin >> date;
	cout << "Date:" << endl;
	cout << date;
	//Tests Incrementor operators
	Date date1(12, 31, 2000);
	//Tests decrement operators
	Date date2(4, 26, 2011);
	//date 3 and 4 compare
	Date date3(4, 19, 2012);
	Date date4(5, 3, 2012);

	cout << "\nOrginal Date 1:" << endl;
	cout << date1;
	//postfix
	date1++;
	cout << "\nPostfix incrementor of Date 1:" << endl;
	cout << date1;
	//prefix
	++date1;
	cout << "\nPrefix incrementor of Date 1:" << endl;
	cout << date1;

	cout << "\nOriginal Date 2:" << endl;
	cout << date2;
	//postfix
	date2--;
	cout << "\nPostfix decrementor Date 2:" << endl;
	cout << date2;
	--date2;
	cout << "\nPrefix decrementor Date 2:" << endl;
	cout << date2;
	cout << "\nComparing Date 4 and Date 4\n";
	cout << "\nDate 3:" << endl;
	cout << date3;
	cout << "\nDate 4:" << endl;
	cout << date4;
	cout << "\nDifference between date 3 and date 4 is " << (date3 - date4) << " days." << endl << endl;
	return 0;
}