#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <stdexcept>
#include <algorithm>
#include <ctime>

static int safeAtoi(const std::string &str)
{
  std::stringstream ss(str);
  long value;

  ss >> value;

  if (ss.fail() || !ss.eof())
    throw std::runtime_error("Error");

  if (value < 0 || value > std::numeric_limits<int>::max())
    throw std::runtime_error("Error");

  return static_cast<int>(value);
}

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(char **args, int size)
{
  for (int i = 0; i < size; ++i)
  {
    int value = safeAtoi(args[i]);
    _vector.push_back(value);
    _deque.push_back(value);
  }
}

static std::vector<size_t> generateJacobsthalIndices(size_t n)
{
  std::vector<size_t> jacob;
  std::vector<size_t> result;

  jacob.push_back(0);
  jacob.push_back(1);

  while (jacob.back() < n)
  {
    size_t size = jacob.size();
    jacob.push_back(jacob[size - 1] + 2 * jacob[size - 2]);
  }

  for (size_t i = 2; i < jacob.size(); ++i)
  {
    size_t start = jacob[i];
    size_t end = jacob[i - 1];

    if (start > n)
      start = n;

    for (size_t j = start; j > end; --j)
      result.push_back(j - 1);
  }

  return result;
}


void PmergeMe::fordJohnsonVector(std::vector<int>& vec)
{
  if (vec.size() <= 1)
    return;

  std::vector<int> mainChain;
  std::vector<int> pend;

  for (size_t i = 0; i + 1 < vec.size(); i += 2)
  {
    if (vec[i] < vec[i + 1])
    {
      pend.push_back(vec[i]);
      mainChain.push_back(vec[i + 1]);
    }
    else
  {
      pend.push_back(vec[i + 1]);
      mainChain.push_back(vec[i]);
    }
  }

  if (vec.size() % 2 != 0)
    pend.push_back(vec.back());

  fordJohnsonVector(mainChain);

  mainChain.insert(mainChain.begin(), pend[0]);
  std::vector<size_t> order = generateJacobsthalIndices(pend.size());

  for (size_t i = 0; i < order.size(); ++i)
  {
    size_t idx = order[i];

    if (idx == 0 || idx >= pend.size())
      continue;

    std::vector<int>::iterator pos =
      std::lower_bound(mainChain.begin(), mainChain.end(), pend[idx]);

    mainChain.insert(pos, pend[idx]);
  }

  vec = mainChain;
}


void PmergeMe::sortVector()
{
  fordJohnsonVector(_vector);
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& deq)
{
  if (deq.size() <= 1)
    return;

  std::deque<int> mainChain;
  std::deque<int> pend;

  for (size_t i = 0; i + 1 < deq.size(); i += 2)
  {
    if (deq[i] < deq[i + 1])
    {
      pend.push_back(deq[i]);
      mainChain.push_back(deq[i + 1]);
    }
    else
  {
      pend.push_back(deq[i + 1]);
      mainChain.push_back(deq[i]);
    }
  }

  if (deq.size() % 2 != 0)
    pend.push_back(deq.back());

  fordJohnsonDeque(mainChain);

  mainChain.insert(mainChain.begin(), pend[0]);
  std::vector<size_t> order = generateJacobsthalIndices(pend.size());

  for (size_t i = 0; i < order.size(); ++i)
  {
    size_t idx = order[i];

    if (idx >= pend.size())
      continue;

    std::deque<int>::iterator pos =
      std::lower_bound(mainChain.begin(), mainChain.end(), pend[idx]);

    mainChain.insert(pos, pend[idx]);
  }

  deq = mainChain;
}

void PmergeMe::sortDeque()
{
  fordJohnsonDeque(_deque);
}

void PmergeMe::process(char **args, int size)
{
  clock_t startVector;
  clock_t endVector;
  clock_t startDeque;
  clock_t endDeque;

  parseInput(args, size);

  std::cout << "Before: ";
  for (size_t i = 0; i < _vector.size(); ++i)
    std::cout << _vector[i] << " ";
  std::cout << std::endl;

  startVector = clock();
  sortVector();
  endVector = clock();

  startDeque = clock();
  sortDeque();
  endDeque = clock();

  std::cout << "After: ";
  for (size_t i = 0; i < _vector.size(); ++i)
    std::cout << _vector[i] << " ";
  std::cout << std::endl;

  double timeVector =
    static_cast<double>(endVector - startVector)
    / CLOCKS_PER_SEC * 1000000;

  double timeDeque =
    static_cast<double>(endDeque - startDeque)
    / CLOCKS_PER_SEC * 1000000;

  std::cout << "Time to process a range of "
    << size
    << " elements with std::vector : "
    << timeVector
    << " us"
    << std::endl;

  std::cout << "Time to process a range of "
    << size
    << " elements with std::deque : "
    << timeDeque
    << " us"
    << std::endl;
}

