#pragma once

template <typename T>
class My_Array
{
private:
	int m_size;
	int* m_data;

public:
	My_Array<T>(int sz)
		: m_size{ sz } {
		m_data = new T[m_size];
	}

};

/*
	My_Array<T>(const My_Array<T>&); //Copy constructor
	virtual ~My_Array<T>();

	void setValue(T, int);
	void  printArray(const My_Array<T>&) const;
	*/
