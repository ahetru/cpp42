#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: <" << av[0] << " expression>" << std::endl;
		return 1;
	}
	std::string expr(av[1]);
	RPN rpn;
	try
	{
		rpn.evaluateExpression(expr);

	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
