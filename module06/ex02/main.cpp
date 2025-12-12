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
	Base* a = generate();
	identify(a);

	Base &ref = *a;
	identify(ref);

	delete a;

	return 0;
}
