/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:00:28 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/09 11:21:28 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal(void)
{
    std::cout << "Animal Default constructor called" << std::endl;
	this->_type = "Animal";
    return ;
}

// Copy constructor
Animal::Animal(const Animal &other)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = other;
    return ;
}

// Assignment operator overload
Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal Assignment operator called" << std::endl;
    this->_type = other._type;
    return (*this);
}

// Destructor
Animal::~Animal(void)
{
    std::cout << "Animal Destructor called" << std::endl;
    return ;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::makeSound(void) const
{
	std::cout << "I AM NOTHING! HELP!" << std::endl;
	return ;
}
