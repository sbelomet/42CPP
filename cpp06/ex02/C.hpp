/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:25:10 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/03 10:25:33 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP
# include <iostream>
# include "Base.hpp"

class C : public Base
{
	public:
		C(void);
		C(const C& other);
		C &operator=(const C &other);
		virtual ~C();
};

#endif
