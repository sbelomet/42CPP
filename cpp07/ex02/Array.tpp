/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:40:09 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/03 12:53:45 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP
# include "Array.hpp"

// Default constructor
template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

// Constructor with size
template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

// Copy constructor
template <typename T>
Array<T>::Array(const Array &src) : _array(NULL), _size(0)
{
	*this = src;
}

// Assignment operator
template <typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
	if (this == &src)
		return *this;
	delete[] _array;
	_array = new T[src._size];
	_size = src._size;
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
	return *this;
}

// Destructor
template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

// Operator []
template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw Array<T>::OutOfBoundsException();
	return _array[i];
}

// Size
template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

// OutOfBoundsException
template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return ("ERROR: Out of bounds");
}

// Operator <<
template <typename T>
std::ostream &operator<<(std::ostream &out, Array<T> &src)
{
	out << "[";
	for (unsigned int i = 0; i < src.size(); i++)
	{
		out << src[i];
		if (i < src.size() - 1)
			out << ", ";
	}
	out << "]";
	return out;
}

#endif
