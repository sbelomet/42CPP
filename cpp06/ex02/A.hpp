/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:21:35 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/03 10:22:22 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP
# include <iostream>
# include "Base.hpp"

class A : public Base
{
	public:
		A(void);
		A(const A& other);
		A &operator=(const A &other);
		virtual ~A();
};

#endif
