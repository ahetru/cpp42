#ifndef B_HPP
#define B_HPP

#include "Base.hpp"
#include <iostream>

class B : public Base {
	public:
		B() { std::cout << "B default constructor\n"; };
		~B() { std::cout << "B destructor\n"; };
};

#endif
