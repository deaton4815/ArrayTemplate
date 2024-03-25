/*
*	Philip Deaton
*	605.604
*	Assignment 3
*/

#include <iostream>
#include <string>

#include "MyArray.h"

using namespace std;

int main() {
	// Create array object
	int arraySize{ 5 };
	MyArray<int> intObj(arraySize);

	// Fill array object with values
	int iTest[5]{ 1, 2, 3, 4, 5 };
	for (int i{ 0 }; i < arraySize; i++) {
		intObj.setValue(iTest[i], i);
	}

	cout << "\nintObj:" << endl;
	intObj.printArray();

	arraySize = 3;
	MyArray<float> floatObj(arraySize);

	float fTest[3]{ 1.5f, 2.33f, 3.157f };
	for (int i{ 0 }; i < arraySize; i++) {
		floatObj.setValue(fTest[i], i);
	}

	cout << "\nfloatObj:" << endl;
	floatObj.printArray();

	arraySize = 5;
	MyArray<string> stringObj(arraySize);

	string sTest[5]{ "This", "is", "a", "string", "array" };

	for (int i{ 0 }; i < arraySize; i++) {
		stringObj.setValue(sTest[i], i);
	}

	cout << "\nstringObj:" << endl;
	stringObj.printArray();

};


	/*
	// Initialize new array object
	MyArray<int> newObj{ existingObj };

	// Show that newObj = existingObj
	cout << "\nexistingObj:" << endl;
	existingObj.printArray(existingObj);
	cout << "\nnewObj:" << endl;
	newObj.printArray(newObj);

	// Modify newObj
	newObj.setValue(10, 2);
	newObj.setValue(99, 4);
	cout << "\nnewObj modified" << endl;

	// Show that newObj has been modified
	//	while existingObj remains the same
	cout << "\nexistingObj:" << endl;
	existingObj.printArray(existingObj);
	cout << "\nnewObj:" << endl;
	newObj.printArray(newObj);
};
	
*/