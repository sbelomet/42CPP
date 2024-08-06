/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:05:15 by sbelomet          #+#    #+#             */
/*   Updated: 2024/08/06 13:07:23 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
	std::cout << "Before: " << _args << std::endl;
	sortVector();
	sortList();
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
static void sort_pairs_vec(std::vector<int> *vecPairs, int len)
{
	if (len < 1)
		return ;
	else
	{
		sort_pairs_vec(vecPairs, len - 1);
		insertion_sort(vecPairs[len], vecPairs, len - 1);
	}
}

// sortVector
void PmergeMe::sortVector()
{
	std::vector<int> vecArgs;
	std::vector<int> vecPairs[_size / 2];

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
		odd = std::stoi(tmp);
		_args = _args.substr(0, i - 1);
	}

	// Convert the string of numbers into a vector of integers
	for (size_t i = 0; i < _args.size(); i++)
	{
		std::string tmp;
		while (isdigit(_args[i]))
		{
			tmp += _args[i];
			i++;
		}
		vecArgs.push_back(std::stoi(tmp));
	}

	// Store each pair of elements in a vector of vectors
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
	sort_pairs_vec(vecPairs, len - 1);

	std::vector<int> vecSorted;
	// Store the largest element of each pair in a new vector (also store the smallest element of the first pair)
	for (size_t i = 0; i < _size / 2; i++)
	{
		if (i == 0)
			vecSorted.push_back(vecPairs[i][1]);
		vecSorted.push_back(vecPairs[i][0]);
	}


	for (size_t i = 0; i < vecSorted.size(); i++)
	{
		std::cout << vecSorted[i];
		if (i < vecSorted.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	for (size_t i = 0; i < _size / 2; i++)
	{
		std::cout << vecPairs[i][0] << " " << vecPairs[i][1] << " ";
	}
	if (odd != -1)
		std::cout << odd << std::endl;
	else
		std::cout << std::endl;
}

// sortList
void PmergeMe::sortList()
{
	std::list<int> lst;
}

// Exceptions
const char* PmergeMe::InvalidArgument::what() const throw() { return ("ERROR: Invalid argument (only positive integers)"); }
