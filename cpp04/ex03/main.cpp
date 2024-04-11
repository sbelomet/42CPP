/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:25:18 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/11 15:56:03 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int main()
{
	std::cout << std::endl;

	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << std::endl << "---------------------" << std::endl << std::endl;

	{
		IMateriaSource* src = new MateriaSource();
		AMateria* ice = new Ice();
		src->learnMateria(ice);
		src->learnMateria(new Cure());
		src->learnMateria(ice);

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character(*(Character*)me);

		me->unequip(1);
		me->unequip(1);
		me->unequip(-34567);
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(-3, *bob);

		bob->use(0, *me);
		bob->use(1, *me);
		bob->use(2, *me);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << std::endl << "---------------------" << std::endl << std::endl;
	return 0;
}