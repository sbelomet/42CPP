/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:50:08 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/04 14:40:16 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	{
		ClapTrap Steven("Steven");

		std::cout << Steven << std::endl;
		Steven.attack("Jasper");
		std::cout << Steven << std::endl;
		Steven.takeDamage(5);
		std::cout << Steven << std::endl;
		Steven.beRepaired(3);
		std::cout << Steven << std::endl;
		Steven.attack("Jasper");
		Steven.attack("Jasper");
		Steven.attack("Jasper");
		Steven.attack("Jasper");
		Steven.attack("Jasper");
		Steven.attack("Jasper");
		Steven.attack("Jasper");
		Steven.attack("Jasper");
		std::cout << Steven << std::endl;
		Steven.beRepaired(3);
		Steven.attack("Aquamarine");
	}

	std::cout << std::endl << "---------------------" << std::endl << std::endl;

	{
		ClapTrap Amethyst("Amethyst");

		std::cout << Amethyst << std::endl;
		Amethyst.takeDamage(5);
		Amethyst.takeDamage(5);
		std::cout << Amethyst << std::endl;
		Amethyst.beRepaired(3);
		Amethyst.attack("Aquamarine");
	}

	std::cout << std::endl << "---------------------" << std::endl << std::endl;

	{
		ScavTrap Garnet("Garnet");

		std::cout << Garnet << std::endl;
		Garnet.attack("Jasper");
		Garnet.attack("Aquamarine");
		std::cout << Garnet << std::endl;
		Garnet.guardGate();
	}
	
}
