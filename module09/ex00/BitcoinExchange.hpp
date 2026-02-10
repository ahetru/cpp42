#pragma once
#include <map>
#include <iostream>
#include <fstream>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _referenceDB;
		BitcoinExchange();
		void loadDatabase(std::ifstream& db);

	public:
		BitcoinExchange(std::ifstream& db);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		void evaluate(std::ifstream& data);
};
