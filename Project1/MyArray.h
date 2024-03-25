#pragma once
#include <iostream>

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

		std::cout << "MyArray copied!" << std::endl;
	};

	virtual ~MyArray<T>() { delete[] m_data; };

	void setValue(T value, int index) {
		m_data[index] = value;
	};

	// Print MyArray object without creating a new copy
	void printArray() const {
		for (size_t i{ 0 }; i < m_size; i++) {
			std::cout << m_data[i] << " ";
		}
		std::cout << std::endl;
	};
};