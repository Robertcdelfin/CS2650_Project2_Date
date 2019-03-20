
#include<string>
using namespace std;
class Date
{
	friend istream &operator>>(istream &in, Date&);
	friend ostream &operator<<(ostream &out, const Date&);
private:
	int month;
	int day;
	int year;
	//checks if the date is a leap year
	bool leapYearCheck(int);
	void addDates();
	void subtractDates();

public:
	//default Constructor
	Date();
	//setters
	void setMonth(int);
	void setDay(int);
	void setYear(int);
	// additional members
	Date(int, int, int);
	Date operator++();
	Date operator++(int);
	Date operator--();
	Date operator--(int);
	int operator-(const Date&);
};
