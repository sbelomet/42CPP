/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:24:20 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/03 10:24:44 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP
# include <iostream>
# include "Base.hpp"

class B : public Base
{
	public:
		B(void);
		B(const B& other);
		B &operator=(const B &other);
		virtual ~B();
};

#endif
