/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:25:37 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/03 10:25:38 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"

// Default constructor
C::C(void)
{
	std::cout << "C default constructor called" << std::endl;
	return ;
}

// Copy constructor
C::C(const C &other)
{
	std::cout << "C copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
C &C::operator=(const C &other)
{
	std::cout << "C assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

// Destructor
C::~C(void)
{
	std::cout << "C destructor called" << std::endl;
	return ;
}
