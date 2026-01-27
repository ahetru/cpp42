#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
int main(void)
{
    std::vector<int> vec;
    std::list<int> lst;
    std::deque<int> deq;

    for(int i = 1; i <= 10; ++i) {
        vec.push_back(i);
        lst.push_back(i);
        deq.push_back(i);
    }

    try {
        std::cout <<  "Test for vector\n";
        easyfind(vec, 2);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout <<  "Test for list\n";
        easyfind(lst, 4);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::cout <<  "Test for deque\n";
        easyfind(deq, 11);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
