/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:55:24 by sbelomet          #+#    #+#             */
/*   Updated: 2024/06/26 10:59:29 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Big Boss", 1);
		Bureaucrat b2("Kafka", 41);
		
		Form f1;
		Form f2("FREE MILK FORM", 1, 120);
		Form f3(f2);
		std::cout << std::endl;

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;
		
		std::cout << std::endl;

		b1.signForm(f1);
		b1.signForm(f2);
		b2.signForm(f3);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
