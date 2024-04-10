/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:57:51 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/10 14:56:28 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "includes.h"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice& other);
		Ice &operator=(const Ice &other);
		~Ice();

		Ice *clone() const;
		void use(ICharacter& target);
};

#endif

