/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:36:20 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/04 14:40:12 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_hitpoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
	this->_hitpoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other._name)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	this->_name = other._name;
	this->_hitpoints = other._hitpoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

// Destructor
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &o, const ScavTrap &ST)
{
	o << "Name: " << ST.getName() << std::endl;
	o << "Hitpoints: " << ST.getHitpoints() << std::endl;
	o << "Energy Points: " << ST.getEnergyPoints() << std::endl;
	o << "Attack Damage: " << ST.getAttackDamage() << std::endl;
	return (o);
}


void ScavTrap::attack(std::string const & target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is out of energy and can't attack " << target << "!" << std::endl;
		return ;
	}
	else if (this->_hitpoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is dead and can't attack " << target << "!" << std::endl;
		return ;
	}
	
	std::cout << "ScavTrap " << this->_name << " lost 1 energy point and attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
	return ;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is in Shield mode!" << std::endl;
	return ;
}
