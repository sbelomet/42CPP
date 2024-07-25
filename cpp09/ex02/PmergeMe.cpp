/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:05:15 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/25 13:16:07 by sbelomet         ###   ########.fr       */
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
	for (size_t i = 0; i < _args.size(); i++)
	{
		if (!isdigit(_args[i]) && _args[i] != ' ')
			throw InvalidArgument();
	}
}

// sort
void PmergeMe::sort()
{
	std::cout << "Before: " << _args << std::endl;
	sortVector();
	sortList();
}

// sortVector
void PmergeMe::sortVector()
{
	std::vector<int> vec;
}

// sortList
void PmergeMe::sortList()
{
	std::list<int> lst;
}

// Exceptions
const char* PmergeMe::InvalidArgument::what() const throw() { return ("ERROR: Invalid argument (only positive integers)"); }
