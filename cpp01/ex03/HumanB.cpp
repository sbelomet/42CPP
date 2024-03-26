/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:13:05 by sbelomet          #+#    #+#             */
/*   Updated: 2024/03/26 11:33:47 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
}

HumanB::~HumanB(void)
{
}

void HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their " << (*this->_weapon).getType() << "\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
