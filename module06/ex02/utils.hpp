#ifndef UTILS_HPP
#define UTILS_HPP
#include "Base.hpp"

Base* generate(void);

void identify(Base* p);
//It prints the actual type of the object pointed to by p: "A", "B", or "C".
void identify(Base& p);
//It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
//inside this function is forbidden

#endif
