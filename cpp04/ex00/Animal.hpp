/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:00:33 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/09 11:38:14 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
    protected:
		std::string _type;
	
	public:
        Animal(void);
        Animal(const Animal& other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();

		std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif

