/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:25:18 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/10 10:58:47 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1;
		Bureaucrat b2("Kafka", 10);
		Bureaucrat b3(b2);
		std::cout << std::endl;

		b3.setGrade(15);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;

		//b1.decrementGrade();
		//std::cout << b1 << std::endl;

		b2.incrementGrade();
		std::cout << b2 << std::endl;

		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
