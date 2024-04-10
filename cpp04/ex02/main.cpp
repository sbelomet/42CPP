/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:01:51 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/10 10:32:21 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
int main(void)
{
	std::cout << std::endl;
	
	{
		//const Animal* meta = new Animal();
		const Animal* jake = new Dog();
		const Animal* gumball = new Cat();

		std::cout << std::endl;
		//std::cout << meta->getType() << " " << std::endl;
		std::cout << jake->getType() << " " << std::endl;
		std::cout << gumball->getType() << " " << std::endl;
		//meta->makeSound();
		jake->makeSound();
		gumball->makeSound();
		std::cout << std::endl;

		//delete meta;
		delete jake;
		delete gumball;
	}

	std::cout << std::endl;

	return 0;
}
