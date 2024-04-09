/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:08:41 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/09 11:17:10 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat(void)
{
    std::cout << "Cat Default constructor called" << std::endl;
	this->_type = "Cat";
    return ;
}

// Copy constructor
Cat::Cat(const Cat &other)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    *this = other;
    return ;
}

// Assignment operator overload
Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat Assignment operator called" << std::endl;
    this->_type = other._type;
    return (*this);
}

// Destructor
Cat::~Cat(void)
{
    std::cout << "Cat Destructor called" << std::endl;
    return ;
}

void Cat::makeSound(void) const
{
	std::cout << "I AM CAT 😺" << std::endl;
	return ;
}
