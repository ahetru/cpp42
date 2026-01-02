#include "Array.hpp"

Array<T>::Array()
{
	_size = 0;
	_array = new T[0];
}

Array<T>::Array(unsigned int n)
{
	_size = n;
	_array = new T[_size];
}

Array<T>::~Array()
{
	delete[] _array;
}

Array<T>::Array(const Array& other) 
{
	_size = other.size;
	_array = new T[_size];

	for (size_t i = 0; i < _size; ++i) {
		_array[i] = _other[i];
	}
}

Array<T>& Array::operator=(const Array& other) {
	if (*this != other)
	{
		delete[] _array;
		_size = other.size;
		_array = new T[_size];
		for (size_t i = 0; i < _size; ++i) {
		_array[i] = _other[i];
	}
	return *this;
};

