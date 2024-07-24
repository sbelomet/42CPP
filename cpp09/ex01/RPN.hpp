/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:26:46 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/24 15:38:21 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>

class RPN
{
	private:
		RPN(void);
		RPN(const RPN& other);
		RPN &operator=(const RPN &other);
		~RPN();

	public:
		static void calculate(std::string &str);

		class InvalidExpressionException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class ForbiddenCharacterException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
