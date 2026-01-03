#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <stddef.h>

template <typename T> class Array {
	private:
		size_t _size;
		T* _data;

	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array& other);
		Array& operator=(const Array& other);

		class OutOfBoundsException : public std::exception
		{
			const char* what() const throw();
		};
		T& operator[](size_t index);

		size_t size() const;
};

#include "Array.tpp"

#endif
