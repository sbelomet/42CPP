/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:58:13 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/11 10:24:20 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Default constructor
Cure::Cure(void)
{
	//std::cout << "Cure default constructor called" << std::endl;
	this->_type = "cure";
	return ;
}

// Copy constructor
Cure::Cure(const Cure &other)
{
	//std::cout << "Cure copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
Cure &Cure::operator=(const Cure &other)
{
	//std::cout << "Cure assignment operator called" << std::endl;
	this->_type = other._type;
	return (*this);
}

// Destructor
Cure::~Cure(void)
{
	//std::cout << "Cure destructor called" << std::endl;
	return ;
}

Cure *Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
	return ;
}
