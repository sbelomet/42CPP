/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:24:05 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/03 10:24:05 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

// Default constructor
A::A(void)
{
	std::cout << "A default constructor called" << std::endl;
	return ;
}

// Copy constructor
A::A(const A &other)
{
	std::cout << "A copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
A &A::operator=(const A &other)
{
	std::cout << "A assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

// Destructor
A::~A(void)
{
	std::cout << "A destructor called" << std::endl;
	return ;
}
