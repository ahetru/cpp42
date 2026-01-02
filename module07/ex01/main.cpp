#include "iter.hpp"

#include <iostream>

void toZero(int &num) {
        num = 0;
}


void printValue(int &num)
{
	std::cout << num << std::endl;
}

void printValue(const int &num)
{
	std::cout << num << std::endl;
}

int main()
{
	int array[4] = { 1, 2, 3, 4};	
	::iter(array, 4, printValue);
	std::cout << "---------------------------------------------------------------\n";
	::iter(array, 4, toZero);
	::iter(array, 4, printValue);
	std::cout << "---------------------------------------------------------------\n";

	int const constArray[4] = { 42, 42, 42, 42};	
	::iter(constArray, 4, printValue);

	return 0;
}
