#include <iostream>
#include "PmergeMe.hpp"

int main(int ac, char **av)

{
	if (ac == 1)
	{
		std::cout << "No parameters given\n";
		return 1;
	}
	try
	{
		PmergeMe merge(av + 1);
		std::cout << merge << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
