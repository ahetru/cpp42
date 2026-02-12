#pragma once
#include <map>
#include <iostream>
#include <fstream>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _referenceDB;
		void loadDatabase(const std::string &filename);
		bool isValidValue(const std::string &value, double &out) const;
		bool isValidDate(const std::string &date) const;

	public:
		BitcoinExchange(const std::string &dbFilename);
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void processInput(const std::string& filename) const;
};
