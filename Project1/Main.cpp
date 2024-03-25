/*
*	Philip Deaton
*	605.604
*	Assignment 3
*/

#include <iostream>
#include <string>

#include "MyArray.h"
#include "Date.h"

using namespace std;

int main() {

	/**************** Integer Array ****************/

	// Create integer array object
	const int intArraySize{ 5 };
	MyArray<int> intObj(intArraySize);

	// Fill integer array object with values
	int iTest[intArraySize]{ 1, 2, 3, 4, 5 };
	for (int i{ 0 }; i < intArraySize; i++) {
		intObj.setValue(iTest[i], i);
	}

	cout << "\nintObj:" << endl;
	intObj.printArray();

	// Initialize new inter array to value of current object
	MyArray<int> newIntObj{ intObj };
	cout << "\nNew int array. Initialized to original array:" << endl;
	newIntObj.printArray();

	//New int obj modifications
	newIntObj.setValue(99, 2);
	newIntObj.setValue(77, 4);
	cout << "\nNew int array modified:" << endl;
	newIntObj.printArray();

	//Assign array back to original
	newIntObj = intObj;
	cout << "\nNew int array assigned back to original:" << endl;
	newIntObj.printArray();

	/**************** Float Array ****************/

	//Create float array object
	const int floatArraySize{ 3 };
	MyArray<float> floatObj(floatArraySize);

	// Fill float array with values
	float fTest[floatArraySize]{ 1.5f, 2.33f, 3.157f };
	for (int i{ 0 }; i < floatArraySize; i++) {
		floatObj.setValue(fTest[i], i);
	}

	cout << "\nfloatObj:" << endl;
	floatObj.printArray();

	// Initialize new float array to value of current object
	MyArray<float> newfloatObj{ floatObj };
	cout << "\nNew float array. Initialized to original array:" << endl;
	newfloatObj.printArray();

	//New float obj modifications
	newfloatObj.setValue(99.999, 0);
	newIntObj.setValue(77.777, 1);
	cout << "\nNew float array modified:" << endl;
	newfloatObj.printArray();

	//Assign array back to original
	newfloatObj = floatObj;
	cout << "\nNew float array assigned back to original:" << endl;
	newfloatObj.printArray();

	/**************** String Array ****************/

	const int stringArraySize{ 5 };
	MyArray<string> stringObj(stringArraySize);

	string sTest[stringArraySize]{ "This", "the", "ORIGINAL", "string", "array" };

	for (int i{ 0 }; i < stringArraySize; i++) {
		stringObj.setValue(sTest[i], i);
	}

	cout << "\nstringObj:" << endl;
	stringObj.printArray();

	// Initialize new string array to value of current object
	MyArray<string> newstringObj{ stringObj };
	cout << "\nNew string array. Initialized to original array:" << endl;
	newstringObj.printArray();

	//New string obj modifications
	newstringObj.setValue("NEW", 2);
	cout << "\nNew string array modified:" << endl;
	newstringObj.printArray();

	//Assign array back to original
	newstringObj = stringObj;
	cout << "\nNew string array assigned back to original:" << endl;
	newstringObj.printArray();

	/**************** Date Array ****************/

	const int dateArraySize{ 4 };
	MyArray<Date> dateObj(dateArraySize);

	Date today(3, 23, 2024);
	Date birthday(4, 28, 1999);
	Date tennesseeVolsNationalChampionship(1, 9, 1999);
	Date tennesseeBeatsBama(10, 15, 2022);

	Date dTest[dateArraySize]{ today, birthday,
		tennesseeVolsNationalChampionship, tennesseeBeatsBama };

	for (int i{ 0 }; i < dateArraySize; i++) {
		dateObj.setValue(dTest[i], i);
	}

	cout << "\ndateObj:" << endl;
	dateObj.printArray();

	// Initialize new date array to value of current object
	MyArray<Date> newdateObj{ dateObj };
	cout << "\nNew date array. Initialized to original array:" << endl;
	newdateObj.printArray();

	//New date obj modifications
	Date dueDate(3, 25, 2024);
	Date declarationOfIndependence(7, 4, 1776);
	newdateObj.setValue(dueDate, 1);
	newdateObj.setValue(declarationOfIndependence, 3);
	cout << "\nNew date array modified:" << endl;
	newdateObj.printArray();

	//Assign array back to original
	newdateObj = dateObj;
	cout << "\nNew date array assigned back to original:" << endl;
	newdateObj.printArray();
};