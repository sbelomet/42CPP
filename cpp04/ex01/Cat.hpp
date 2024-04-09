/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:09:06 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/09 12:38:44 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal
{
    private:
		Brain *brain;
	
	public:
        Cat(void);
        Cat(const Cat& other);
        Cat &operator=(const Cat &other);
        virtual ~Cat();

		void makeSound(void) const;
};

#endif

