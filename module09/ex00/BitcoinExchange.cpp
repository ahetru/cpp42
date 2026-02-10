#include "BitcoinExchange.hpp"
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <limits>

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
		std::string BtcScalarStr = line.substr(delim + 1);

		double btcScalar = std::atof(valueStr.c_str());
		_referenceDB.insert(make_pair(date, btcScalar));
	}
}

void BitcoinExchange::evaluate(std::ifstream& inputData)
{
	std::string line;
	//process header
	std::getline(inputData, line);
	if (line != "date | value")
	{
		std::cerr << "Invalid format" << std::endl;
		return ;
	}
	while (std::getline(inputData, line))
	{
		std::cout << line << std::endl;
		size_t delim = line.find(" | ");
		if (delim == std::string::npos)
			std::cerr "Error: bad input =>" << line;

		std::string date = line.substr(0, delim);
		std::string btcStr = line.substr(delim + 1);

		
		long float btcValue = std::atof(bctStr.c_str());
		if (btcValue < 0)
			std::cerr << "Error: not a positive number" << std::endl;
		if (btcValue > 1000)
			std::cer << "Error: btc value superior to 1000" << std::endl;
	}

}
