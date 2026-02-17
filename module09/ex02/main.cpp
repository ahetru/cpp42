#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe sorter;
        sorter.process(argv + 1, argc - 1);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}

