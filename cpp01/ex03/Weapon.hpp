/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:54:16 by sbelomet          #+#    #+#             */
/*   Updated: 2024/03/26 11:39:40 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon
{
	private:
		std::string _type;

		

	public:
		Weapon(std::string type);
		~Weapon(void);
		Weapon(void);

		const std::string &getType(void);
		void setType(std::string new_type);
		
		void operator=(const Weapon& W)
		{
			_type = W._type;
		}
};

#endif
