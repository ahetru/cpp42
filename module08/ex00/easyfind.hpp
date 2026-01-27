#pragma once

#include <algorithm>
#include <stdexcept>
#include <iostream>

template <typename T>
int easyfind(T& ints, int toFind)
{
    typename T::iterator it;

    it = find(ints.begin(), ints.end(), toFind);
    if (it == ints.end())
    {
        throw std::runtime_error("Element not found");
    }
    size_t index = std::distance(ints.begin(), it);
    std::cout << "Found element" << toFind << "at index: " << index << std::endl;

    return 0;
}
