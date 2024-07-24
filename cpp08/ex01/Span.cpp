/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:48:27 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/23 11:50:00 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

// Default constructor
Span::Span(void) : _size(0) {}

// Constructor
Span::Span(unsigned int N) : _size(N) { _container.reserve(_size); }

// Copy constructor
Span::Span(const Span &other) { *this = other; }

// Assignment operator overload
Span &Span::operator=(const Span &other)
{
	_container = other._container;
	_size = other._size;
	return (*this);
}

// Destructor
Span::~Span(void) {}

// << operator overload
std::ostream &operator<<(std::ostream &out, const Span &span)
{
	out << "Size: " << span.getSize() << " | ";
	out << "Container: [";
	for (unsigned int i = 0; i < span.getSize(); i++)
	{
		out << span.getContainer()[i];
		if (i < span.getSize() - 1)
			out << ", ";
	}
	out << "]";
	return (out);
}

// Getters
unsigned int Span::getSize(void) const { return (_size); }
std::vector<int> Span::getContainer(void) const { return (_container); }

// Add number to the container
void Span::addNumber(int number)
{
	if (_container.size() < _size)
		_container.push_back(number);
	else
		throw Span::ContainerFullException();
}

// Add numbers to the container
void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_container.size() + std::distance(begin, end) <= _size)
		_container.insert(_container.end(), begin, end);
	else
		throw Span::ContainerFullException();
}

// Find the shortest span
int Span::shortestSpan(void) const
{
	int shortest = 0;
	if (_container.size() < 2)
		throw Span::NotEnoughNumbersException();

	std::vector<int> sorted = _container;
	std::sort(sorted.begin(), sorted.end());
	shortest = sorted[1] - sorted[0];
	for (unsigned int i = 1; i < _container.size(); i++)
	{
		if (sorted[i] - sorted[i - 1] < shortest)
			shortest = sorted[i] - sorted[i - 1];
	}
	return (shortest);
}

// Find the longest span
int Span::longestSpan(void) const
{
	int longest = 0;
	if (_container.size() < 2)
		throw Span::NotEnoughNumbersException();

	std::vector<int> sorted = _container;
	std::sort(sorted.begin(), sorted.end());
	longest = sorted[sorted.size() - 1] - sorted[0];
	return (longest);
}

// ContainerFullException class
const char *Span::ContainerFullException::what() const throw()
{
	return ("ERROR: Container is full");
}

// NotEnoughNumbersException class
const char *Span::NotEnoughNumbersException::what() const throw()
{
	return ("ERROR: Not enough numbers in the container");
}
