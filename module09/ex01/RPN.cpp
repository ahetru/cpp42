#include "RPN.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

RPN::RPN() : _expr() {};
RPN::~RPN() {};

bool RPN::isOperator(const unsigned char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::debugPrintStack() const
{
	std::stack<int> cpy;
	cpy = _expr;

	while (cpy.size())
	{
		std::cout << cpy.top() <<  " " << std::endl;
		cpy.pop();
	}
	std::cout << "\n";
}

void RPN::makeOperation(unsigned char op)
{
	if (_expr.size() < 2)
	{
		debugPrintStack();
		throw std::logic_error("missing values to operate");
	}
	int right = _expr.top();
	_expr.pop();
	int left = _expr.top();
	_expr.pop();
	switch(op)
	{
		case('+'): _expr.push(left + right); break;
		case('-'): _expr.push(left - right); break;
		case('*'): _expr.push(left * right); break;
		case('/'):
			   {
				   if (right == 0)
					   throw std::logic_error("division by zero");
				   _expr.push(left / right); 
			   } break;
		default: break;
	}
}

void RPN::evaluateExpression(const std::string &expr)
{
	std::istringstream iss(expr);
	std::string token;

	while (iss >> token)
	{
		if (token.size() == 1 && isOperator(token[0]))
		{
			makeOperation(token[0]);
		}
		else if (token.size() == 1 && std::isdigit(token[0]))
		{
			_expr.push(std::atoi(token.c_str()));
		}
		else
		{
			throw std::logic_error("Error");
		}
	}

	if (_expr.size() != 1)
		throw std::logic_error("Error");

	std::cout << _expr.top() << std::endl;
}

