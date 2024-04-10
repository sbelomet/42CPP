/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:01:51 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/10 10:11:23 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << std::endl;
	
	{
		int animalsNum = 6;
		const Animal** animals = new const Animal*[animalsNum];

		for (int i = 0; i < animalsNum; i++)
		{
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		std::cout << std::endl;
		for (int i = 0; i < animalsNum; i++)
		{
			std::cout << i + 1 << ". ";
			std::cout << animals[i]->getType() << " " << std::endl;
			animals[i]->makeSound();
			std::cout << std::endl;
		}
		
		for (int i = 0; i < animalsNum; i++)
			delete animals[i];
		delete[] animals;
	}

	std::cout << std::endl << "---------------------" << std::endl << std::endl;

	{
		Dog jake;

		std::cout << std::endl;
		jake.setIdea(0, "I am a dog");
		std::cout << "Jake's idea: " << jake.getIdea(0) << std::endl;
		std::cout << std::endl;

		Dog atticus(jake);

		std::cout << std::endl;
		std::cout << "Atticus's idea: " << atticus.getIdea(0) << std::endl;
		std::cout << std::endl;

		jake.setIdea(0, "I am a god");
		if (atticus.getIdea(0) != "I am a god" && atticus.getIdea(0) == "I am a dog")
			std::cout << "Deep copy confirmed" << std::endl;
		else
			std::cout << "Deep copy failed" << std::endl;
		std::cout << std::endl;
	}

	std::cout << std::endl;

	return 0;
}
