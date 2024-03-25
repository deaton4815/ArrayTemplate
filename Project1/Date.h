#pragma once

#include <string>
#include <format>

using namespace std;

class Date
{

public:

	enum class Month {
		January = 1, February, March,
		April, May, June, July, August, September,
		October, November, December
	};

	//Validate user entries
	bool isValidMonth(int) const;
	bool isValidDay(int) const;
	bool isValidYear(int) const;

	//Public data member setters
	void setMonth(int);
	void setDay(int);
	void setYear(int);

	//Outputs to user
	string getDateMMDDYYYY() const;//MM-DD-YYYY
	string getDateNorthAmerican() const;//Month Day, Year
	string getDateEuropean() const;//Day Month Year
	bool getIsLeapYear() const;//Return leap year bool

private:

	bool isWithinBounds(int, int, int) const;//Check bounds of month day or year
	bool isDivisible(int, int) const;//Check divisibility for leap years

	//Private data member setters
	void setMonthName();
	void setIsLeapYear();

	//Data member getters
	Month getMonth() const;
	int getDay() const;
	int getYear() const;
	string getMonthName() const;

	//Format attribute as MM, DD, or YYYY
	string getFormattedDate(int, int) const;

	//Month enum class conversions
	Month intToMonth(int) const;
	int monthToInt(Month) const;

	//Date attributes
	Month m_month{ Month::January };
	int m_day{ 0 };
	int m_year{ 0 };
	bool m_isLeapYear{ false };

	//All month names
	const string m_allMonthNames[12]{ "January", "February",
		"March", "April", "May", "June", "July", "August",
		"Setpember", "October", "November", "December" };

	string m_monthName{ m_allMonthNames[0] };

};

