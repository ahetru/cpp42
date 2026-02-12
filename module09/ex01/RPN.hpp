#pragma once
#include <stack>
#include <string>

class RPN
{
	private:
		std::stack<int> _expr;
	
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

		void debugPrintStack() const;
		bool isOperator(const unsigned char c) const;
		void makeOperation(unsigned char op);
	public:
		RPN();
		~RPN();

		void evaluateExpression(const std::string& expr);
};

