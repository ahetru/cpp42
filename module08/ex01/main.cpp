#include "Span.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
try
    {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        Span big(1000);
        std::vector<int> values;
        for (int i = 0; i < 1000; i++) {
            values.push_back(rand());
        }

        big.addRange(values.begin(), values.end());
        std::cout << "Big shortest: " << big.shortestSpan() << std::endl;
        std::cout << "Big longest: " << big.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

return 0;
}
