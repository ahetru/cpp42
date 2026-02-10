#include "BitcoinExchange.hpp"
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(std::ifstream& db)
{
	loadDatabase(db);
}

BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& btc)
{
	(void)btc;
	throw std::runtime_error("btc copy is not allowed\n");
};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& btc)
{
	(void)btc;
	std::cerr << "btc assignement is not allowed\n";
	return *this;
}

void BitcoinExchange::loadDatabase(std::ifstream& db)
{
	if (!db)
		throw std::runtime_error("Could not open database");
	std::string line;
	while (std::getline(db, line))
	{
		size_t delim = line.find(',');
		if (delim == std::string::npos)
			throw std::runtime_error("Error: bad database format");

		std::string date = line.substr(0, delim);
		std::string valueStr = line.substr(delim + 1);

		double btcScalar = std::atof(valueStr.c_str());
		_referenceDB.insert(make_pair(date, btcScalar));
	}
}

void BitcoinExchange::evaluate(std::ifstream& inputData)
{
	std::string line;
	while (std::getline(inputData, line))
	{
		std::cout << line << std::endl;
	}

}
