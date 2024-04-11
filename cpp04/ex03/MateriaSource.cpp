/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:40:02 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/11 10:36:53 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Default constructor
MateriaSource::MateriaSource(void)
{
	//std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < MEMORY_SIZE; i++)
		this->_memory[i] = 0;
	return ;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &other)
{
	//std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	//std::cout << "MateriaSource assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

// Destructor
MateriaSource::~MateriaSource(void)
{
	//std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < MEMORY_SIZE; i++)
	{
		if (this->_memory[i] != 0)
		{
			for (int j = i + 1; j < MEMORY_SIZE; j++)
			{
				if (this->_memory[j] == this->_memory[i])
					this->_memory[j] = 0;
			}
			delete this->_memory[i];
		}
	}
	return ;
}

void MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;
	
	while (i < MEMORY_SIZE && this->_memory[i] != 0)
		i++;
	if (i == MEMORY_SIZE)
		return ;
	this->_memory[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MEMORY_SIZE; i++)
	{
		if (this->_memory[i] && this->_memory[i]->getType() == type)
		{
			return this->_memory[i]->clone();
		}
	}
	return 0;
}
