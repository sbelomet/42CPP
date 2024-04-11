/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:58:19 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/11 10:24:10 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Default constructor
Ice::Ice(void)
{
	//std::cout << "Ice default constructor called" << std::endl;
	this->_type = "ice";
	return ;
}

// Copy constructor
Ice::Ice(const Ice &other)
{
	//std::cout << "Ice copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
Ice &Ice::operator=(const Ice &other)
{
	//std::cout << "Ice assignment operator called" << std::endl;
	this->_type = other._type;
	return (*this);
}

// Destructor
Ice::~Ice(void)
{
	//std::cout << "Ice destructor called" << std::endl;
	return ;
}

Ice *Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
	return ;
}
