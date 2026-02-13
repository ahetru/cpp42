#pragma once
#include <vector>
#include <string>

class PmergeMe
{
	private:
		std::vector<int> _data;
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		void loadData(char **cleanARGV);

	public:
		PmergeMe();
		PmergeMe(char **cleanARGV);
		~PmergeMe();
		void sort();

		friend std::ostream& operator<<(std::ostream& os, const PmergeMe& p);
};
