/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:40:02 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/10 15:53:41 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Default constructor
MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < MEMORY_SIZE; i++)
		this->_memory[i] = NULL;
	return ;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

// Destructor
MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called" << std::endl;
	return ;
}

void MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;
	
	while (this->_memory[i] == NULL)
		i++;
	if (i == MEMORY_SIZE)
		return ;
	std::cout << "learning a materia\n";
	this->_memory[i] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MEMORY_SIZE; i++)
	{
		//std::cout << "in a for loop\n";
		//std::cout << this->_memory[i]->getType() << std::endl;
		if (this->_memory[i] && this->_memory[i]->getType() == type)
		{
			//std::cout << "in an if staement\n";
			return this->_memory[i]->clone();
		}
	}
	return 0;
}
