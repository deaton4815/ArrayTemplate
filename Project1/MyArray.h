#pragma once
#include <iostream>
#include "Date.h"

using namespace std;

template <typename T>
class MyArray
{
private:
	int m_size;
	T* m_data;

public:
	MyArray<T>(int sz)
		: m_size{ sz } {
		m_data = new T[m_size];
	};

	// Copy constructor
	MyArray<T>(const MyArray<T>& src)
		: m_size(src.m_size) {
		m_data = new T[m_size];
		for (size_t i{ 0 }; i < m_size; i++) {
			m_data[i] = src.m_data[i];
		}

		cout << "\nMyArray copied!" << endl;
	};

	void operator=(const MyArray<T>& rhs) {
		for (int i{ 0 }; i < m_size; i++) {
			m_data[i] = rhs.getValue(i);
		}
	};

	virtual ~MyArray<T>() { delete[] m_data; };

	void setValue(T value, int index) { m_data[index] = value; };
	T getValue(int index) const { return m_data[index]; };

	// Print MyArray object without creating a new copy
	void printArray() const {
		for (size_t i{ 0 }; i < m_size; i++) {
			cout << m_data[i] << " ";
		}
		cout << endl;
	};
};

// Class specialization for date object
template <>
class MyArray<Date>
{
private:
	int m_size;
	Date* m_data;

public:
	MyArray<Date>(int sz)
		: m_size{ sz } {
		m_data = new Date[m_size];
	};

	// Copy constructor
	MyArray<Date>(const MyArray<Date>& src)
		: m_size(src.m_size) {
		m_data = new Date[m_size];
		for (size_t i{ 0 }; i < m_size; i++) {
			m_data[i] = src.m_data[i];
		}

		cout << "\nMyArray copied!" << endl;
	};

	void operator=(const MyArray<Date>& rhs) {
		for (int i{ 0 }; i < m_size; i++) {
			m_data[i] = rhs.getValue(i);
		}
	};

	virtual ~MyArray<Date>() { delete[] m_data; };

	void setValue(const Date& value, int index) { m_data[index] = value; };
	Date getValue(int index) const { return m_data[index]; };

	// Print MyArray object without creating a new copy
	void printArray() const {
		for (size_t i{ 0 }; i < m_size; i++) {
			cout << m_data[i].getDateNorthAmerican() << endl;
		}
		cout << endl;
	};
};