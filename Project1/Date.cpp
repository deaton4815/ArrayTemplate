#include "Date.h"

using namespace std;

Date::Date() = default;
Date::Date(int month, int day, int year) {
	setMonth(month);
	setDay(day);
	setYear(year);
}

Date::Date(const Date&) = default;
Date& Date::operator=(const Date& rhs) = default;

//Validate user entries for month, day and year.
//Parameters:
//	month, day, year: user-entries
//Returns:
//	isValidMonth, isValidDay, isValidYear:
//		True or false for entry validity

//Valid entry for month is integer between 1 and 12
bool Date::isValidMonth(int month) const {
	bool isValidMonth{ false };

	int lowerBound = 1;
	int upperBound = 12;
	if (isWithinBounds(month, lowerBound, upperBound)) {
		isValidMonth = true;
	}
	return isValidMonth;
}

//Valid entry for day varies by month and year.
bool Date::isValidDay(int day) const {
	bool isValidDay{ false };

	Month month = getMonth();
	bool isLeapYear{ getIsLeapYear() };

	int lowerBound{ 1 };
	int upperBound{ 1 };

	//Set upper bound based on month
	//and leap year
	switch (month) {
		//Months with 31 days
	case Month::January:
	case Month::March:
	case Month::May:
	case Month::July:
	case Month::August:
	case Month::October:
	case Month::December:
		upperBound = 31;
		break;
		//Months with 30 days
	case Month::April:
	case Month::June:
	case Month::September:
	case Month::November:
		upperBound = 30;
		break;
		// February.
		//Set upper bound based on leap year
	case Month::February:
		if (isLeapYear) {
			upperBound = 29;
		}
		else if (!isLeapYear) {
			upperBound = 28;
		}
		break;
	default:
		upperBound = 1;
		break;
	}

	if (isWithinBounds(day, lowerBound, upperBound)) {
		isValidDay = true;
	}
	return isValidDay;
}

//Valid entry for year is a four-digit Anno Domoni year
bool Date::isValidYear(int year) const {
	bool isValidYear{ false };

	int lowerBound = 0;
	int upperBound = 9999;
	if (isWithinBounds(year, lowerBound, upperBound)) {
		isValidYear = true;
	}
	return isValidYear;
}


//Set Class attributes
//Paramters:
//	month, day, year: Already-validated user entries for month, day, and year
void Date::setMonth(int month) {
	m_month = intToMonth(month);
	setMonthName();//Set string for month name
}
void Date::setDay(int day) {
	m_day = day;
}
void Date::setYear(int year) {
	m_year = year;
	setIsLeapYear();//Check for leap year
}


//Outputs to user

//Returns:
//	dateMMDDYYYY: Date as "MM-DD-YYYY"
string Date::getDateMMDDYYYY() const {

	//Get formatted strings for month, day, and year
	string month{ getFormattedDate(monthToInt(getMonth()), 2) };
	string day{ getFormattedDate(getDay(), 2) };
	string year{ getFormattedDate(getYear(), 4) };

	string dateMMDDYYYY{ month + "-"s + day + "-"s + year };
	return dateMMDDYYYY;
}

//Returns:
//	dateNorthAmerican: Date as "Month, Day Year"
string Date::getDateNorthAmerican() const {

	//Get formatted strings for month name, day, and year
	string monthName{ getMonthName() };
	string day{ getFormattedDate(getDay(), 2) };
	string year{ getFormattedDate(getYear(), 4) };

	string dateNorthAmerican{ monthName + " "s + day + ", "s + year };
	return dateNorthAmerican;
}

//Returns:
//	dateEuropean: Date as "Day Month Year"
string Date::getDateEuropean() const {
	//Get formatted strings for month name, day, and year
	string monthName{ getMonthName() };
	string day{ getFormattedDate(getDay(), 2) };
	string year{ getFormattedDate(getYear(), 4) };

	string dateEuropean{ day + " "s + monthName + " "s + year };
	return dateEuropean;
}

//Private data member getter
bool Date::getIsLeapYear() const {
	return m_isLeapYear;
}

//Check user-entry bounds for month, day, and year
//Parameters:
//	value: user entry for month, day, or year
//	lowerBound: inclusive lower bound
//	upperBound: inclusive upper bound
//Returns:
//	isWithinBounds: True or false for value being bounded by upper and lower bound
bool Date::isWithinBounds(int value, int lowerBound, int upperBound) const {
	bool isWithinBounds{ false };
	if ((value >= lowerBound) && (value <= upperBound)) {
		isWithinBounds = true;
	}
	return isWithinBounds;
}

//Check divisibility. For leap year attribute
//Parameters:
//	dividend: validated user entry for day of the month
//	divisor: 4, 100, or 4oo in this case
//Returns:
//	isDivisible: True or false for divisibility
bool Date::isDivisible(int dividend, int divisor) const {
	bool isDivisible{ false };
	if ((dividend % divisor) == 0) {
		isDivisible = true;
	}
	return isDivisible;
}

//Private data member setters

void Date::setMonthName() {
	int month{ monthToInt(getMonth()) };
	m_monthName = m_allMonthNames[month - 1];
}

//Check for leap year and set attribute
/*
* "There is a leap year every year divisible by four
*  except for years which are both divisible by 100 and not divisible by 400."
*
* source: https://scienceworld.wolfram.com/astronomy/LeapYear.html#:~:text=
*	The%20complete%20list%20of%20leap,2040%2C%202044%2C%20and%202048
*/
void Date::setIsLeapYear() {
	bool isLeapYear{ false };

	int year{ getYear() };

	//Check divisibility of year
	bool isDivisibleByFour{ false };
	bool isDivisibleByOneHundred{ false };
	bool isDivisibleByFourHundred{ false };

	if (isDivisible(year, 4)) {
		isDivisibleByFour = true;
	}
	if (isDivisible(year, 100)) {
		isDivisibleByOneHundred = true;
	}
	if (isDivisible(year, 400)) {
		isDivisibleByFourHundred = true;
	}

	//Set leap year based on divisibility
	if (isDivisibleByFour
		&& (!isDivisibleByOneHundred
			|| (isDivisibleByOneHundred && isDivisibleByFourHundred))) {
		isLeapYear = true;
	}

	m_isLeapYear = isLeapYear;
}

//Private data member getters
//Returns:
//	month, day, year, or month name attribute
Date::Month Date::getMonth() const {
	return m_month;
}
int Date::getDay() const {
	return m_day;
}
int Date::getYear() const {
	return m_year;
}
string Date::getMonthName() const {
	return m_monthName;
}

//Attribute formatter
//Parameters:
//	dateInt: Integer value for month, day, or year
//  width: Desires number of digits (2 for month and day, 4 for year)
//Returns:
//	Formatted date attribute
string Date::getFormattedDate(int dateInt, int width) const {
	return format("{:0{}d}", dateInt, width);
}

//Month enum class converters
//Parameters:
//	month as Month or int
//Returns:
//  Returns month enumerator as month number
//		or month number as month enumerator
Date::Month Date::intToMonth(int month) const {
	return static_cast<Month>(month);
}
int Date::monthToInt(Month month) const {
	return static_cast<int>(month);
}