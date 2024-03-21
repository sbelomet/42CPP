/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:28:24 by sbelomet          #+#    #+#             */
/*   Updated: 2024/03/21 14:15:33 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	std::cout << "Creating a zombie on the stack\n";
	randomChump("finn");

	std::cout << "Creating a zombie on the heap\n";
	Zombie *jake = newZombie("jake");
	jake->announce();
	delete(jake);
}
