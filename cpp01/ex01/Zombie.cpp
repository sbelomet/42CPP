/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:31:09 by sbelomet          #+#    #+#             */
/*   Updated: 2024/03/21 14:44:34 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->_name = "UNDEFINED";
	std::cout << " Unnamed zombie has been created\n";
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << " " << this->_name << " has been created\n";
}

Zombie::~Zombie(void)
{
	std::cout << " " << this->_name << " has been destroyed\n";
}

void Zombie::announce(void)
{
	std::cout << " " << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::set_name(std::string name)
{
	this->_name = name;
}
