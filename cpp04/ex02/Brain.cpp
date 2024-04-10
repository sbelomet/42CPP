/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:52:59 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/09 15:21:13 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Default constructor
Brain::Brain(void)
{
    std::cout << "Brain Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Brain::Brain(const Brain &other)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = other;
    return ;
}

// Assignment operator overload
Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain Assignment operator called" << std::endl;
	std::copy(other.ideas, other.ideas + 100, this->ideas);
    return (*this);
}

// Destructor
Brain::~Brain(void)
{
    std::cout << "Brain Destructor called" << std::endl;
    return ;
}

std::string Brain::getIdea(int index) const
{
	return (this->ideas[index]);
}

void Brain::setIdea(int index, const std::string &idea)
{
	this->ideas[index] = idea;
	return ;
}
