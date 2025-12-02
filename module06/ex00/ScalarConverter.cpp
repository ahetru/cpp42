#include "ScalarConverter.hpp"
#include <cctype>
#include <iterator>
#include <cstdlib>

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
  (void)other;
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
  (void)other;
	return *this;
};

ScalarConverter::~ScalarConverter() {};

ScalarConverter::Type ScalarConverter::getType(const std::string& literal) {
	if (isInt(literal)) {
    std::cout << literal << " is an int\n";
		return TYPE_INT;
	}
	if (isFloat(literal)) {
    std::cout << literal << " is a float\n";
		return TYPE_FLOAT;
	}
	if (isChar(literal)) {
    std::cout << literal << " is a char\n";
		return TYPE_CHAR;
	}
	if (isDouble(literal)) {
    std::cout << literal << " is a double\n";
		return TYPE_DOUBLE;
	}
	return TYPE_UNKNOWN;
}

bool ScalarConverter::isInt(const std::string& literal) {
  size_t i = 0;

  if (literal[i] == '+' || literal[i] == '-') {
    ++i;
  }
  if (i >= literal.length()) {
    return false;
  }

  for (; i < literal.length(); ++i) {
    if (!std::isdigit(literal[i])) {
        return false;
    }
  }
  return true;
}

bool ScalarConverter::isFloat(const std::string &literal) {
  bool hasDecimalPoint= false;
  size_t i = 0;

  char lastChar = literal[literal.length() - 1];
  if (lastChar != 'f') {
    return false;
  }

  if (literal[i] == '+' || literal[i] == '-') {
    ++i;
  }

  for (; i < literal.length() - 1; ++i){
    char c = literal[i];
    if (c == '.') {
      if (hasDecimalPoint) {
        return false;
      }
      hasDecimalPoint = true;
    }
    if (!std::isdigit(literal[i]) && c != '.') {
      return false;
    }
  }
  if (!hasDecimalPoint) {
    return false;
  }
  return true;
}

bool ScalarConverter::isChar(const std::string& literal) {
  return (literal.length() == 3 &&
      literal[0] == 39 &&
      literal[2] == 39);
}

bool ScalarConverter::isDouble(const std::string& literal) {
  bool hasDecimalPoint = false;
  size_t i = 0;

  if (literal[i] == '+' || literal[i] == '-') {
    ++i;
  }

  for (; i < literal.length(); ++i){
    char c = literal[i];
    if (c == '.') {
      if (hasDecimalPoint) {
        return false;
      }
      hasDecimalPoint = true;
    }
    if (!std::isdigit(literal[i]) && c != '.') {
      return false;
    }
  }
  if (!hasDecimalPoint) {
    return false;
  }
  return true;
}

static void convertFromInt(const std::string &literal)
{
	int litToInt = std::atoi(literal.c_str());

	{
		char intToChar = litToInt;
		if (litToInt >= 33 && litToInt <= 126)
		{
			std::cout << "char: " << intToChar << std::endl;
		}
		else
		{
			std::cout <<"char : Non displayable" << std::endl;
		}
	}

	{
		std::cout << "int: " << litToInt << std::endl;
	}

	{
		float intToFloat = static_cast<float>(litToInt);
		std::cout << "float: " << intToFloat << ".0f" << std::endl;
	}

	{
		double intToDouble = static_cast<double>(litToInt);
		std::cout << "double: " << intToDouble << ".0" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &literal) {
  if (literal.empty()) {
    std::cout << "literal given is empty\n";
  }
	Type type = getType(literal);

	switch(type)
	{
		case TYPE_CHAR:
		{
		} break;
		case TYPE_INT:
		{
			convertFromInt(literal);
		} break;
		case TYPE_FLOAT:
		{
		} break;
		case TYPE_DOUBLE:
		{
		} break;
		case TYPE_UNKNOWN:
		{
		} break;
	}
	// switch(type) {
	//    case TYPE_INT:
	//      convertFromInt(literal);
	//      break;
	//    case TYPE_CHAR:
	//      convertFromChar(literal);
	//      break;
	//    case TYPE_FLOAT:
	//      convertFromFloat(literal);
	//      break;
	//    case TYPE_DOUBLE:
	//      convertFromDouble(literal);
	//      break;
	//    case TYPE_PSEUDO:
	//      convertFromPseudo(literal);
	//      break;
	// 	default:
	// 		std::cout << "Unknown type";
	// }
}
