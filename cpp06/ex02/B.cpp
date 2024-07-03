/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:25:04 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/03 10:25:05 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"

// Default constructor
B::B(void)
{
	std::cout << "B default constructor called" << std::endl;
	return ;
}

// Copy constructor
B::B(const B &other)
{
	std::cout << "B copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
B &B::operator=(const B &other)
{
	std::cout << "B assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

// Destructor
B::~B(void)
{
	std::cout << "B destructor called" << std::endl;
	return ;
}
