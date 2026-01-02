#include <iostream>
#include "myTemplates.hpp"


int main()
{
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
/*
	int *ptrA = &a;
	int *ptrB = &b;

	std::cout << "ptrA = " << ptrA << ", ptrB = " << ptrB << std::endl;
	::swap( ptrA, ptrB );
	std::cout << "ptrA = " << ptrA << ", ptrB = " << ptrB << std::endl;
	std::cout << "min( ptrA, ptrB ) = " << ::min( ptrA, ptrB ) << std::endl;
	std::cout << "max( ptrA, ptrB ) = " << ::max( ptrA, ptrB ) << std::endl;

*/
	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
