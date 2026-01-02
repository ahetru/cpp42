#ifndef ITER_HPP
#define ITER_HPP

#include <stddef.h>

template <typename T> void iter(T array[], const size_t SIZE, void (*f) (T&))
{
	for (size_t i = 0; i < SIZE; ++i) {
		f(array[i]);
	}
};

template <typename T> void iter(const T array[], const size_t SIZE, void (*f) (const T&))
{
	for (size_t i = 0; i < SIZE; ++i) {
		f(array[i]);
	}
};

#endif
