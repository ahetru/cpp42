#include "ScalarConverter.hpp"
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cmath>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}



bool ScalarConverter::isChar(const std::string& literal)
{
	return literal.length() == 1 && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(const std::string& literal)
{
	size_t i = 0;

	if (literal[i] == '+' || literal[i] == '-')
		i++;

	if (i >= literal.length())
		return false;

	for (; i < literal.length(); i++)
		if (!std::isdigit(literal[i]))
			return false;

	return true;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return true;

	if (literal[literal.length() - 1] != 'f')
    return false;

	bool hasDot = false;
	size_t i = 0;

	if (literal[i] == '+' || literal[i] == '-')
		i++;

	for (; i < literal.length() - 1; i++)
	{
		if (literal[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!std::isdigit(literal[i]))
			return false;
	}

	return hasDot;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;

	bool hasDot = false;
	size_t i = 0;

	if (literal[i] == '+' || literal[i] == '-')
		i++;

	for (; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!std::isdigit(literal[i]))
			return false;
	}

	return hasDot;
}

ScalarConverter::Type ScalarConverter::getType(const std::string& literal)
{
	if (isChar(literal)) return TYPE_CHAR;
	if (isInt(literal))
	{
		long v = std::strtol(literal.c_str(), NULL, 10);
				if (v >= std::numeric_limits<int>::min() &&
				    v <= std::numeric_limits<int>::max())
					return TYPE_INT;
				else
					return TYPE_DOUBLE;
	}
	if (isFloat(literal)) return TYPE_FLOAT;
	if (isDouble(literal)) return TYPE_DOUBLE;
	return TYPE_UNKNOWN;
}



void ScalarConverter::convertFromInt(const std::string &literal)
{
	long val = std::strtol(literal.c_str(), NULL, 10);

	if (val < 0 || val > 255)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<char>(val)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(val) << "'\n";

	if (val < std::numeric_limits<int>::min() ||
		val > std::numeric_limits<int>::max()) {
			std::cout << "int: impossible\n";
		} else {
			int intVal = static_cast<int>(val);
			std::cout << "int: " << intVal << "\n";
		}

	std::cout << "float: " << static_cast<float>(val) << ".0f\n";

	std::cout << "double: " << static_cast<double>(val) << ".0\n";
}


void ScalarConverter::convertFromChar(const std::string &literal)
{
	char c = literal[0];

	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << ".0f\n";
	std::cout << "double: " << static_cast<double>(c) << ".0\n";
}


void ScalarConverter::convertFromFloat(const std::string &literal)
{
	float f;

	bool pseudo = false;

	if (literal == "-inff")  { f = -std::numeric_limits<float>::infinity(); pseudo = true; }
	else if (literal == "+inff") { f =  std::numeric_limits<float>::infinity(); pseudo = true; }
	else if (literal == "nanf")  { f =  std::numeric_limits<float>::quiet_NaN(); pseudo = true; }
	else f = std::strtof(literal.c_str(), NULL);

	if (pseudo || std::isnan(f) || f < 0 || f > 255)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<char>(f)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(f) << "'\n";

	if (pseudo || f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(f) << "\n";

	std::cout << "float: " << f << "f\n";

	std::cout << "double: " << static_cast<double>(f) << "\n";
}


void ScalarConverter::convertFromDouble(const std::string& literal)
{
	double d;

	bool pseudo = false;

	if (literal == "-inf")  { d = -std::numeric_limits<double>::infinity(); pseudo = true; }
	else if (literal == "+inf") { d =  std::numeric_limits<double>::infinity(); pseudo = true; }
	else if (literal == "nan")  { d =  std::numeric_limits<double>::quiet_NaN(); pseudo = true; }
	else d = std::strtod(literal.c_str(), NULL);

	if (pseudo || std::isnan(d) || d < 0 || d > 255)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<char>(d)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(d) << "'\n";

	if (pseudo || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(d) << "\n";

	std::cout << "float: " << static_cast<float>(d) << "f\n";

	std::cout << "double: " << d << "\n";
}


void ScalarConverter::convert(const std::string& literal)
{
	Type t = getType(literal);

	switch (t)
	{
		case TYPE_CHAR:   convertFromChar(literal);   break;
		case TYPE_INT:    convertFromInt(literal);    break;
		case TYPE_FLOAT:  convertFromFloat(literal);  break;
		case TYPE_DOUBLE: convertFromDouble(literal); break;
		default:
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: impossible\n";
			std::cout << "double: impossible\n";
	}
}
