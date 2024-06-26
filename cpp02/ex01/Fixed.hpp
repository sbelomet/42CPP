/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:35:10 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/02 09:49:51 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
    private:
		int _value;
		const static int _fractBits = 8;
	
	public:
        Fixed(void);
		Fixed(int const inputInt);
		Fixed(float const inputFloat);
        Fixed(const Fixed& other);
        Fixed &operator=(const Fixed &other);
        ~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, const Fixed &F);

#endif
