/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:55:24 by sbelomet          #+#    #+#             */
/*   Updated: 2024/06/26 15:51:34 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Big Boss", 1);
		Bureaucrat b2("Kafka", 41);
		Bureaucrat b3("Julien", 141);
		ShrubberyCreationForm scf("home");

		std::cout << std::endl;

		b1.incrementGrade();
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		std::cout << scf << std::endl;

		std::cout << std::endl;

		b1.executeForm(scf);
		b1.signForm(scf);
		b3.executeForm(scf);
		b2.executeForm(scf);

		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	return (0);
}
