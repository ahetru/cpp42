#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Invalid arguments\n";
		std::cerr << "Usage: <" << av[0] << " input.txt>\n";
		return 1;
	}

	std::ifstream referenceDB("data.csv");
	if (!referenceDB.is_open())
	{
		std::cerr << "Could not open reference database file\n";
		return -1;
	}
	std::ifstream inputData(av[1]);
	if (!inputData.is_open())
	{
		std::cerr << "Could not open input file\n";
		referenceDB.close();
		return -1;
	}

	try
	{
		BitcoinExchange btc(referenceDB);
		btc.evaluate(inputData);
	} catch(std::exception& e)
	{
		std::cerr << "Error" << e.what() << std::endl;
	}
	return 0;
}
