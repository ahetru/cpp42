#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor called\n";
};

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	std::cout << "Copy constructor called\n";
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
	std::cout << "Assignement operator called\n";
	if (this != &other)
	{
		(void)other;
	}
	return *this;
};

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor called\n";
};

Type ScalarConverter::getType(const std::string& literal) {
	if (isInt(literal)) {
		return TYPE_INT;
	}
	if (isFloat(literal)) {
		return TYPE_FLOAT;
	}
	if (isChar(literal)) {
		return TYPE_CHAR;
	}
	if (isDouble(literal)) {
		return TYPE_DOUBLE;
	}
	return TYPE_UNKOWN;
}

void ScalarConverter::convert(const std::string &literal) {
	Type type = getType(literal);
	switch(type) {


		default:
			std::cout << "Unknown type";
	}
	// switch:
	// isInt
	//	return convertToInt
	//isFloat
	//	return convertToFloat
	//isChar
	//	return convertToChar
	//isDouble
	//	return convertToDouble
	//default:
	// unknowm type
	// Should this be an exception ?
}
