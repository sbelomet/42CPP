/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:27:10 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/10 14:56:59 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "includes.h"

# define INVENTORY_SIZE 4

class Character : public ICharacter
{
	private:
		std::string _name;
		//const AMateria** _inventory = new const AMateria*[INVENTORY_SIZE];
		AMateria* _inventory[INVENTORY_SIZE];
	
	public:
		Character(void);
		Character(std::string name);
		Character(const Character& other);
		Character &operator=(const Character &other);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif

