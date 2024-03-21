/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:28:24 by sbelomet          #+#    #+#             */
/*   Updated: 2024/03/21 14:45:10 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	int count = 10;

	std::cout << "Creating a horde:\n";
	Zombie *horde = zombieHorde(count, "Julien Sorel");

	std::cout << "Making all zombies annouce themselves:\n";
	for (int i = 0; i < count; i++)
	{
		horde[i].announce();
	}

	std::cout << "Deleting all zombies:\n";
	delete [] horde;
}
