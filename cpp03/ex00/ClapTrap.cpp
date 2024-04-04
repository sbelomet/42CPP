/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:58:38 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/04 12:55:42 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_name = "Default";
	this->_hitpoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	return ;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Name constructor called" << std::endl;
	this->_name = name;
	this->_hitpoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	return ;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_name = other._name;
	this->_hitpoints = other._hitpoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

// Destructor
ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

int ClapTrap::getHitpoints(void) const
{
	return (this->_hitpoints);
}

int ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

int ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

std::ostream &operator<<(std::ostream &o, const ClapTrap &CT)
{
	o << "Name: " << CT.getName() << std::endl;
	o << "Hitpoints: " << CT.getHitpoints() << std::endl;
	o << "Energy Points: " << CT.getEnergyPoints() << std::endl;
	o << "Attack Damage: " << CT.getAttackDamage() << std::endl;
	return (o);
}

void ClapTrap::attack(std::string const & target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy and can't attack " << target << "!" << std::endl;
		return ;
	}
	else if (this->_hitpoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and can't attack " << target << "!" << std::endl;
		return ;
	}
	
	std::cout << "ClapTrap " << this->_name << " lost 1 energy point and attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
	this->_hitpoints -= amount;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{	
		std::cout << "ClapTrap " << this->_name << " is out of energy and can't repair themself!" << std::endl;
		return ;
	}
	else if (this->_hitpoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and can't repair themself!" << std::endl;
		return ;
	}
	
	std::cout << "ClapTrap " << this->_name << " lost 1 energy point and repaired themself for " << amount << " points!" << std::endl;
	this->_hitpoints += amount;
	this->_energyPoints -= 1;
	return ;
}
