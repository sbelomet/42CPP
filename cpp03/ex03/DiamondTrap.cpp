/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:01:44 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/04 15:44:22 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->_name = "Default";
	return ;
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "DiamondTrap name constructor called" << std::endl;
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->FragTrap::_hitpoints = 100;
	this->ScavTrap::_energyPoints = 50;
	this->FragTrap::_attackDamage = 30;
	return ;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	(void) other;
	return ;
}

// Assignment operator overload
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	(void) other;
	return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
	return ;
}

std::string DiamondTrap::getName(void) const
{
	return (this->_name);
}

std::ostream &operator<<(std::ostream &o, const DiamondTrap &DT)
{
	o << "DiamondTrap name: " << DT.getName() << std::endl;
	o << "ClapTrap name: " << DT.ClapTrap::getName() << std::endl;
	o << "Hitpoints: " << DT.FragTrap::getHitpoints() << std::endl;
	o << "Energy points: " << DT.ScavTrap::getEnergyPoints() << std::endl;
	o << "Attack damage: " << DT.FragTrap::getAttackDamage() << std::endl;
	return (o);
}

void DiamondTrap::attack(std::string const & target)
{
	this->ScavTrap::attack(target);
	return ;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "Who am I? WHO AM I? What are you even saying?" << std::endl;
	std::cout << "My name is " << this->_name << " and my ClapTrap name is " << this->ClapTrap::_name << "!" << std::endl;
	return ;
}
