/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:58:16 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/10 14:56:35 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "includes.h"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure& other);
		Cure &operator=(const Cure &other);
		~Cure();

		Cure *clone() const;
		void use(ICharacter& target);
};

#endif

