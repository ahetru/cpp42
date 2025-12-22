#include <iostream>
#include "Base.hpp"
#include "utils.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>


int main(void)
{
	std::srand(std::time(NULL));
	Base* ptr = generate();
	identify(ptr);

	Base &ref = *ptr;
	identify(ref);

	delete ptr;

	return 0;
}
