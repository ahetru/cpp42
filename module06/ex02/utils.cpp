#include "utils.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

Base* generate(void)
{
	Base* base = NULL;
	int random = std::rand() % 3;
	switch(random)
	{
		case (0):
			base = new A(); break;
		case (1):
			base = new B(); break;
		case (2):
			base = new C(); break;
	}
	return base;
}

void identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	if (a)
	{
		std::cout << "Base is type A\n";
		return;
	}
	B* b = dynamic_cast<B*>(p);
	if (b)
	{
		std::cout << "Base is type B\n";
		return;
	}
	C* c = dynamic_cast<C*>(p);
	if (c)
	{
		std::cout << "Base is type C\n";
		return;
	}
}

void identify(Base& p)
{
	std::cout << "From identify &\n";
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Base is type A\n";
	}
	catch(...)
	{std::cout << "Is not type A\n";}
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "Base is type B\n";
		(void)b;
	}
	catch(...)
	{std::cout << "Is not type B\n";}
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "Base is type C\n";
		(void)c;
	}
	catch(...)
	{std::cout << "Is not type C\n";}
}
