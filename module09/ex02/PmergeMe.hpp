#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
private:
    std::vector<int> _vector;
    std::deque<int>  _deque;

    void parseInput(char **args, int size);

    void sortVector();
    void sortDeque();

    void fordJohnsonVector(std::vector<int>& vec);
    void fordJohnsonDeque(std::deque<int>& deq);

public:
    PmergeMe();
    ~PmergeMe();

    void process(char **args, int size);
};

#endif

