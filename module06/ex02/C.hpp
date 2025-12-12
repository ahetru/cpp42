#ifndef C_HPP
#define C_HPP

#include "Base.hpp"
#include <iostream>

class C : public Base {
	public:
		C() { std::cout << "C default constructor\n"; };
		~C() { std::cout << "C default destructor\n"; };
};

#endif
