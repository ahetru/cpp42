#pragma once
#include <vector>
#include <stdexcept>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int number);

    template <typename Iterator>
    void addRange(Iterator begin, Iterator end)
    {
        if (_numbers.size() + std::distance(begin, end) > _maxSize)
            throw std::runtime_error("Span is full");
        _numbers.insert(_numbers.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;
};
