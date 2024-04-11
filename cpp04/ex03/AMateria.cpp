/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:50:31 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/11 10:24:58 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Default constructor
AMateria::AMateria(void)
{
	//std::cout << "AMateria default constructor called" << std::endl;
	return ;
}

// Copy constructor
AMateria::AMateria(const AMateria &other)
{
	//std::cout << "AMateria copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
AMateria &AMateria::operator=(const AMateria &other)
{
	//std::cout << "AMateria assignment operator called" << std::endl;
	this->_type = other._type;
	return (*this);
}

// Destructor
AMateria::~AMateria(void)
{
	//std::cout << "AMateria destructor called" << std::endl;
	return ;
}

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
	return ;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* AAAAAAAAAAAHAHARHAAHAAAAHHAHAHAAAA " << target.getName() << std::endl;
	return ;
}
