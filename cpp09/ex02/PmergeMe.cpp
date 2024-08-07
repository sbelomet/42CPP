/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:05:15 by sbelomet          #+#    #+#             */
/*   Updated: 2024/08/07 13:33:52 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>
#include <sys/time.h>

#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

PmergeMe::PmergeMe(void) {}
PmergeMe::PmergeMe(const std::string &args) : _args(args) { parseArgs(); }
PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other) { if (this != &other) _args = other._args; return (*this); }
PmergeMe::~PmergeMe(void) {}

// parseArgs
void PmergeMe::parseArgs()
{
	_size = 0;
	for (size_t i = 0; i < _args.size(); i++)
	{
		if (!isdigit(_args[i]) && _args[i] != ' ')
			throw InvalidArgument();
		if (isdigit(_args[i]))
		{
			while (isdigit(_args[i]))
				i++;
			_size++;
		}
	}

	size_t end = _args.find_last_not_of(' ');
	_args = _args.substr(0, end + 1);
}

// sort
void PmergeMe::sort()
{
	std::cout << BLUE << "Before: " << RESET << _args << std::endl;
	sortVector();
	sortDeque();
}

// Insert the pair in the correct position
static void insertion_sort(std::vector<int> pair, std::vector<int> *vecPairs, int len)
{
	if (len < 0 || pair[0] >= vecPairs[len][0])
		vecPairs[len + 1] = pair;
	else
	{
		vecPairs[len + 1] = vecPairs[len];
		insertion_sort(pair, vecPairs, len - 1);
	}
}

// Recursively sort the pairs by comparing the first elements of each pair
static void sort_pairs(std::vector<int> *vecPairs, int len)
{
	if (len < 1)
		return ;
	else
	{
		sort_pairs(vecPairs, len - 1);
		insertion_sort(vecPairs[len], vecPairs, len - 1);
	}
}

// sortVector
void PmergeMe::sortVector()
{
	// Start timer
	std::clock_t start = std::clock();

	// To avoid segfault hihi
	if (_size == 1 || _size == 0)
	{
		std::cout << BLUE << "After: " << RESET << _args << std::endl;
		std::clock_t end = std::clock();
		double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000;
		std::cout << "Time to process " << _size << " elements with std::vector : " << RED << elapsed << " ms" << RESET << std::endl;
		return ;
	}

	// If the number of elements is odd, store the last element and remove it from the vector
	int odd = -1;
	if (_size % 2 != 0)
	{
		size_t i = _args.find_last_of(' ') + 1;
		std::string tmp;
		while (isdigit(_args[i]))
		{
			tmp += _args[i];
			i++;
		}
		odd = atoi(tmp.c_str());
		_args = _args.substr(0, i - 1);
	}

	// Convert the string of numbers into a vector of integers
	std::vector<int> vecArgs;
	for (size_t i = 0; i < _args.size(); i++)
	{
		std::string tmp;
		while (isdigit(_args[i]))
		{
			tmp += _args[i];
			i++;
		}
		vecArgs.push_back(atoi(tmp.c_str()));
	}

	// Store each pair of elements in a vector of vectors
	std::vector<int> vecPairs[_size / 2];
	for (size_t i = 0; i < _size / 2; i++)
	{
		vecPairs[i].push_back(vecArgs[i * 2]);
		vecPairs[i].push_back(vecArgs[i * 2 + 1]);
	}

	// Compare each pair of elements and swap them if they are in the wrong order (largest to smallest)
	for (size_t i = 0; i < _size / 2; i++)
	{
		if (vecPairs[i][0] < vecPairs[i][1])
		{
			int tmp = vecPairs[i][0];
			vecPairs[i][0] = vecPairs[i][1];
			vecPairs[i][1] = tmp;
		}
	}

	// Recursively sort the pairs by comparing the first elements of each pair
	int len = _size / 2;
	sort_pairs(vecPairs, len - 1);

	// Store the largest element of each pair in vecSorted (also store the smallest element of the first pair)
	// Store the other smallest element of each pair in vecUnsorted (add the odd element if it exists)
	std::vector<int> vecSorted;
	std::vector<int> vecUnsorted;
	for (size_t i = 0; i < _size / 2; i++)
	{
		if (i == 0)
			vecSorted.push_back(vecPairs[i][1]);
		else
			vecUnsorted.push_back(vecPairs[i][1]);
		vecSorted.push_back(vecPairs[i][0]);
	}
	if (odd != -1)
		vecUnsorted.push_back(odd);

	// Seperate the elements of vecUnsorted with powers of 2 nonesense, flip the order
	// and insert them into vecSorted using binary search
	int lastSize = 0;
	int i = 1;
	std::vector<int> vecToInsert;
	while (!vecUnsorted.empty())
	{
		unsigned long sizeLimit = pow(2, i) - lastSize;
		while (vecToInsert.size() != sizeLimit && !vecUnsorted.empty())
		{
			vecToInsert.push_back(vecUnsorted.front());
			vecUnsorted.erase(vecUnsorted.begin());
		}
		lastSize = vecToInsert.size();
		i++;
		int j = vecToInsert.size() - 1;
		while (!vecToInsert.empty())
		{
			int low = 0;
			int high = vecSorted.size() - 1;
			int mid = 0;
			while (low <= high)
			{
				mid = low + (high - low) / 2;
				if (vecToInsert[j] == vecSorted[mid])
					break ;
				if (vecToInsert[j] > vecSorted[mid])
					low = mid + 1;
				else
					high = mid - 1;
			}
			if (vecToInsert[j] < vecSorted[mid])
				mid--;
			vecSorted.insert(vecSorted.begin() + mid + 1, vecToInsert[j]);
			vecToInsert.erase(vecToInsert.end() - 1);
			j--;
		}
	}

	// Stop timer
	std::clock_t end = std::clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000;

	// Print the sorted vector
	std::cout << BLUE << "After: " << RESET;
	for (size_t i = 0; i < vecSorted.size(); i++)
	{
		std::cout << vecSorted[i];
		if (i < vecSorted.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;

	// Print the time it took to sort the vector
	std::cout << "Time to process " << _size << " elements with std::vector : " << RED << elapsed << " ms" << RESET << std::endl;
}

// Insert the pair in the correct position
static void insertion_sort(std::deque<int> pair, std::deque<int> *dqePairs, int len)
{
	if (len < 0 || pair[0] >= dqePairs[len][0])
		dqePairs[len + 1] = pair;
	else
	{
		dqePairs[len + 1] = dqePairs[len];
		insertion_sort(pair, dqePairs, len - 1);
	}
}

// Recursively sort the pairs by comparing the first elements of each pair
static void sort_pairs(std::deque<int> *dqePairs, int len)
{
	if (len < 1)
		return ;
	else
	{
		sort_pairs(dqePairs, len - 1);
		insertion_sort(dqePairs[len], dqePairs, len - 1);
	}
}

// sortDeque
void PmergeMe::sortDeque()
{
	// Start timer
	std::clock_t start = std::clock();

	// To avoid segfault hihi
	if (_size == 1 || _size == 0)
	{
		std::clock_t end = std::clock();
		double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000;
		std::cout << "Time to process " << _size << " elements with std::vector : " << RED << elapsed << " ms" << RESET << std::endl;
		return ;
	}

	// If the number of elements is odd, store the last element and remove it from the deque
	int odd = -1;
	if (_size % 2 != 0)
	{
		size_t i = _args.find_last_of(' ') + 1;
		std::string tmp;
		while (isdigit(_args[i]))
		{
			tmp += _args[i];
			i++;
		}
		odd = atoi(tmp.c_str());
		_args = _args.substr(0, i - 1);
	}

	// Convert the string of numbers into a deque of integers
	std::deque<int> dqeArgs;
	for (size_t i = 0; i < _args.size(); i++)
	{
		std::string tmp;
		while (isdigit(_args[i]))
		{
			tmp += _args[i];
			i++;
		}
		dqeArgs.push_back(atoi(tmp.c_str()));
	}

	// Store each pair of elements in a deque of deques
	std::deque<int> dqePairs[_size / 2];
	for (size_t i = 0; i < _size / 2; i++)
	{
		dqePairs[i].push_back(dqeArgs[i * 2]);
		dqePairs[i].push_back(dqeArgs[i * 2 + 1]);
	}

	// Compare each pair of elements and swap them if they are in the wrong order (largest to smallest)
	for (size_t i = 0; i < _size / 2; i++)
	{
		if (dqePairs[i][0] < dqePairs[i][1])
		{
			int tmp = dqePairs[i][0];
			dqePairs[i][0] = dqePairs[i][1];
			dqePairs[i][1] = tmp;
		}
	}

	// Recursively sort the pairs by comparing the first elements of each pair
	int len = _size / 2;
	sort_pairs(dqePairs, len - 1);

	// Store the largest element of each pair in dqeSorted (also store the smallest element of the first pair)
	// Store the other smallest element of each pair in dqeUnsorted (add the odd element if it exists)
	std::deque<int> dqeSorted;
	std::deque<int> dqeUnsorted;
	for (size_t i = 0; i < _size / 2; i++)
	{
		if (i == 0)
			dqeSorted.push_back(dqePairs[i][1]);
		else
			dqeUnsorted.push_back(dqePairs[i][1]);
		dqeSorted.push_back(dqePairs[i][0]);
	}
	if (odd != -1)
		dqeUnsorted.push_back(odd);

	// Seperate the elements of dqeUnsorted with powers of 2 nonesense, flip the order
	// and insert them into dqeSorted using binary search
	int lastSize = 0;
	int i = 1;
	std::deque<int> dqeToInsert;
	while (!dqeUnsorted.empty())
	{
		unsigned long sizeLimit = pow(2, i) - lastSize;
		while (dqeToInsert.size() != sizeLimit && !dqeUnsorted.empty())
		{
			dqeToInsert.push_back(dqeUnsorted.front());
			dqeUnsorted.erase(dqeUnsorted.begin());
		}
		lastSize = dqeToInsert.size();
		i++;
		int j = dqeToInsert.size() - 1;
		while (!dqeToInsert.empty())
		{
			int low = 0;
			int high = dqeSorted.size() - 1;
			int mid = 0;
			while (low <= high)
			{
				mid = low + (high - low) / 2;
				if (dqeToInsert[j] == dqeSorted[mid])
					break ;
				if (dqeToInsert[j] > dqeSorted[mid])
					low = mid + 1;
				else
					high = mid - 1;
			}
			if (dqeToInsert[j] < dqeSorted[mid])
				mid--;
			dqeSorted.insert(dqeSorted.begin() + mid + 1, dqeToInsert[j]);
			dqeToInsert.erase(dqeToInsert.end() - 1);
			j--;
		}
	}

	// Stop timer
	std::clock_t end = std::clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000;

	// Print the time it took to sort the deque
	std::cout << "Time to process " << _size << " elements with std::deque : " << RED << elapsed << " ms" << RESET << std::endl;
}

// Exceptions
const char* PmergeMe::InvalidArgument::what() const throw() { return ("ERROR: Invalid argument (only positive integers)"); }
