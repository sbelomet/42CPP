/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:27:13 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/10 15:57:41 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Default constructor
Character::Character(void)
{
	std::cout << "Character default constructor called" << std::endl;
	this->_name = "UNNAMED";
	for (int i = 0; i < INVENTORY_SIZE; i++)
		this->_inventory[i] = NULL;
	return ;
}

Character::Character(std::string name)
{
	std::cout << "Character named constructor called" << std::endl;
	this->_name = name;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		this->_inventory[i] = NULL;
	return ;
}

// Copy constructor
Character::Character(const Character &other)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
Character &Character::operator=(const Character &other)
{
	std::cout << "Character assignment operator called" << std::endl;
	this->_name = other._name;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return (*this);
}

// Destructor
Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	return ;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	int i = 0;
	
	std::cout << "equipping...\n";
	while (i < INVENTORY_SIZE && this->_inventory[i] != NULL)
		i++;
	std::cout << i << std::endl;
	if (i == INVENTORY_SIZE)
		return ;
	std::cout << "materia equipped\n";
	this->_inventory[i] = m;
}

void Character::unequip(int idx)
{
	if (idx <= INVENTORY_SIZE || this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx <= INVENTORY_SIZE || this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx]->use(target);
}
