/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:17:47 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/09 11:20:47 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default constructor
Dog::Dog(void)
{
    std::cout << "Dog Default constructor called" << std::endl;
	this->_type = "Dog";
    return ;
}

// Copy constructor
Dog::Dog(const Dog &other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = other;
    return ;
}

// Assignment operator overload
Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog Assignment operator called" << std::endl;
    this->_type = other._type;
    return (*this);
}

// Destructor
Dog::~Dog(void)
{
    std::cout << "Dog Destructor called" << std::endl;
    return ;
}

void Dog::makeSound(void) const
{
	std::cout << "I AM DOG 🐶" << std::endl;
	return ;
}
