#ifndef A_HPP
#define A_HPP

#include "Base.hpp"
#include <iostream>

class A : public Base {
	public:
		A() { std::cout << "A default constructor\n"; };
		~A() { std::cout << "A destructor\n"; };
};

#endif
