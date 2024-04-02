/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:35:15 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/02 10:16:30 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
    return ;
}

Fixed::Fixed(int const inputInt)
{
    std::cout << "Int constructor called" << std::endl;
	this->_value = inputInt << this->_fractBits;
    return ;
}

Fixed::Fixed(float const inputFloat)
{
    std::cout << "Float constructor called" << std::endl;
	float input = inputFloat;
	for (int i = 0; i < this->_fractBits; i++)
	{
		input *= 2;
	}
	this->_value = roundf(input);
    return ;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
	*this = other;
    return ;
}

// Assignment operator overload
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = other._value;
    return (*this);
}

std::ostream &operator<<(std::ostream &o, const Fixed &F)
{
	o << F.toFloat();
	return o;
}

// Destructor
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	float res = this->_value;
	for (int i = 0; i < this->_fractBits; i++)
	{
		res /= 2;
	}
    return res;
}

int Fixed::toInt(void) const
{
	return this->_value >> this->_fractBits;
}
