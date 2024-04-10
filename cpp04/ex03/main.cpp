/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:25:18 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/10 15:58:31 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	std::cout << "Character createdd!\n";

	AMateria* tmp;
	std::cout << "here we are\n";
	tmp = src->createMateria("ice");
	std::cout << "Ice materia createdd!\n";
	me->equip(tmp);
	std::cout << "Ice materia equipped!\n";
	tmp = src->createMateria("cure");
	std::cout << "Cure materia createdd!\n";
	me->equip(tmp);
	std::cout << "cure materia equipped!\n";

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}