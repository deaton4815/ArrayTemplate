/*
*	Philip Deaton
*	605.604
*	Assignment 3
*/

#include <iostream>

#include "My_Array.h"

using namespace std;

int main() {
	// Create array object
	int arraySize{ 5 };
	My_Array<int> existingObj(arraySize);

};
	/*
	// Fill array object with values
	int testArray[5]{ 1, 2, 3, 4, 5 };
	for (int i{ 0 }; i < arraySize; i++) {
		existingObj.setValue(testArray[i], i);
	}

	// Initialize new array object
	My_Array<int> newObj{ existingObj };

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

}
*/