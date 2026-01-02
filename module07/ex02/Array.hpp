#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stddef.h>

template <typename T> class Array {
	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array& other);
		Array& operator=(const Array& other);
	private:
		size_t _size;
		T _array[];
};

#endif
