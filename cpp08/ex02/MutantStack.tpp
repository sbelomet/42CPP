/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:54:57 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/10 10:21:37 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_CPP
# define MUTANTSTACK_CPP
# include "MutantStack.hpp"

// Default constructor
template <typename T>
MutantStack<T>::MutantStack(void) {}

// Copy constructor
template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) { *this = other; }

// Assignment operator overload
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
	*this = other;
	return (*this);
}

// Destructor
template <typename T>
MutantStack<T>::~MutantStack(void) {}

// Iterator begin
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

// Iterator end
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}

// Operator <<
template <typename T>
std::ostream &operator<<(std::ostream &out, MutantStack<T> &src)
{
	typename MutantStack<T>::iterator it = src.begin();
	typename MutantStack<T>::iterator ite = src.end();

	out << "MutantStack: [";
	while (it != ite)
	{
		out << *it;
		if (++it != ite)
			out << ", ";
	}
	out << "]";
	return (out);
}

#endif
