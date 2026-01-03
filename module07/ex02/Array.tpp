#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	_size = 0;
	_data = NULL;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_size = n;
	_data = new T[_size];
	for (size_t i = 0; i < _size ; ++i) {
		_data[i] = T();
	}
}

template <typename T>
Array<T>::~Array()
{
	if (_data) delete[] _data;
}

template <typename T>
Array<T>::Array(const Array& other)
{
	_size = other._size;
	_data = new T[_size];

	for (size_t i = 0; i < _size; ++i) {
		_data[i] = other._data[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (*this != other)
	{
		delete[] _data;
		_size = other._size;
		_data = new T[_size];
		for (size_t i = 0; i < _size; ++i) {
			_data[i] = other._data[i];
		}
	}
	return *this;
}

template <typename T>
	const char* Array<T>::OutOfBoundsException::what() const throw() { return "Given index is out of bounds";}

template <typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= _size)
	{
		throw OutOfBoundsException();
	}
	return _data[index];
}

template <typename T>
size_t Array<T>::size() const { return _size; };
