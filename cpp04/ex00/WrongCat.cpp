/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:34:04 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/09 11:41:00 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat(void)
{
    std::cout << "WrongCat Default constructor called" << std::endl;
	this->_type = "WrongCat";
    return ;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &other)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = other;
    return ;
}

// Assignment operator overload
WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat Assignment operator called" << std::endl;
    this->_type = other._type;
    return (*this);
}

// Destructor
WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat Destructor called" << std::endl;
    return ;
}

void WrongCat::makeSound(void) const
{
	std::cout << "I AM WRONG CAT 😾" << std::endl;
	return ;
}
