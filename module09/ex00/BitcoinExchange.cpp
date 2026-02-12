#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& filename)
{
	loadDatabase(filename);
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file)
		throw std::runtime_error("Error: could not open database.");

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string value;

		if (!std::getline(ss, date, ',') || !std::getline(ss, value))
			continue;

		_referenceDB[date] = std::atof(value.c_str());
	}
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int y = std::atoi(date.substr(0, 4).c_str());
	int m = std::atoi(date.substr(5, 2).c_str());
	int d = std::atoi(date.substr(8, 2).c_str());

	if (y < 2009 || m < 1 || m > 12 || d < 1 || d > 31)
		return false;

	return true;
}

bool BitcoinExchange::isValidValue(const std::string &value, double &out) const
{
	char *end;
	out = std::strtod(value.c_str(), &end);

	if (*end != '\0')
		return false;
	if (out < 0)
		throw std::runtime_error("Error: not a positive number.");
	if (out > 1000)
		throw std::runtime_error("Error: too large a number.");

	return true;
}

void BitcoinExchange::processInput(const std::string &filename) const
{
	std::ifstream file(filename.c_str());
	if (!file)
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string valueStr;

		if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		date.erase(date.find_last_not_of(" \t") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t"));

		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		double value;
		try
		{
			if (!isValidValue(valueStr, value))
				throw std::runtime_error("Error: bad input => " + date);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
			continue;
		}

		std::map<std::string, double>::const_iterator it = _referenceDB.lower_bound(date);

		if (it == _referenceDB.end() || it->first != date)
		{
			if (it == _referenceDB.begin())
			{
				std::cout << "Error: no rate available." << std::endl;
				continue;
			}
			--it;
		}

		std::cout << date << " => " << value
				  << " = " << value * it->second << std::endl;
	}
}

