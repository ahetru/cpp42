#include "PmergeMe.hpp"
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>


PmergeMe::PmergeMe() : _data() {};
PmergeMe::~PmergeMe() {};
PmergeMe::PmergeMe(char **cleanARGV) : _data()
{
	loadData(cleanARGV);
}
PmergeMe::PmergeMe(const PmergeMe& other) {(void)other;};
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {(void)other; return *this;};

/* int& Pmerge::operator[](int idx) */
/* { */
/* 	if (idx < 0 || idx >= data.size()) */
/* 		throw std::logic_error("out of bounds"); */
/* 	return _data[idx]; */
/* } */

/* const int& Pmerge::operator[](int idx) const */
/* { */
/* 	if (idx < 0 || idx >= data.size()) */
/* 		throw std::logic_error("out of bounds"); */
/* 	return _data[idx]; */
/* } */

void PmergeMe::loadData(char **argv)
{
	size_t i = 0;
	while (argv[i])
	{
		_data.push_back(std::atoi(argv[i]));
		++i;
	}
}

void PmergeMe::sort()
{
	//TODO: implement sorting algorithm
}

std::ostream& operator<<(std::ostream& os, const PmergeMe& p)
{
	os << "[";
	for (size_t i = 0; i < p._data.size(); ++i)
	{
		os << p._data[i];
		if (i != p._data.size() - 1)
			os << ", ";
	}
	os << "]";
	return os;
}
