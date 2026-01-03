#include "Array.hpp"

#include <exception>
#include <iostream>

int main()
{
	int *a = new int();
	std::cout << "Memory is zeroed at initialization *a = " << *a << std::endl;
	delete a;

	Array<int> array;
	try {
		std::cout << "array[1] = " << array[1] << std::endl;

	} catch (const std::exception &e) {
		std::cout << "Error :" << e.what() << std::endl;
	}
	try {
		std::cout << "array[0] = " << array[0] << std::endl;

	} catch (const std::exception &e) {
		std::cout << "Error :" << e.what() << std::endl;
	}

	Array<int> array2(10);
	try {
			for (size_t i = 0; i < array2.size(); ++i){
				std::cout << "array2[" << i << "] = " << array2[i] << std::endl;
			}
	} catch (const std::exception &e) {
		std::cout << "Error :" << e.what() << std::endl;
	}

	try {
			std::cout << "array2[10] = " << array2[10] << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Error :" << e.what() << std::endl;
	}
	try {
			std::cout << "array2[-1] = " << array2[-1] << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Error :" << e.what() << std::endl;
	}
	return 0;
}
