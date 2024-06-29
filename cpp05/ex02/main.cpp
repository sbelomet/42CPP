/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scherty <scherty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:55:24 by sbelomet          #+#    #+#             */
/*   Updated: 2024/06/27 11:37:36 by scherty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Big Boss", 1);
		Bureaucrat b2("Kafka", 41);
		Bureaucrat b3("Julien", 141);
		ShrubberyCreationForm scf("home");
		RobotomyRequestForm rrf("Bill");
		PresidentialPardonForm ppf("Heedgharr");

		std::cout << std::endl;

		b1.incrementGrade();
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		std::cout << scf << std::endl;
		std::cout << rrf << std::endl;
		std::cout << ppf << std::endl;

		std::cout << std::endl;

		b1.executeForm(scf);
		b1.signForm(scf);
		b3.executeForm(scf);
		b2.executeForm(scf);

		std::cout << std::endl;

		b1.executeForm(rrf);
		b1.signForm(rrf);
		b3.executeForm(rrf);
		b2.executeForm(rrf);
		b2.executeForm(rrf);
		b2.executeForm(rrf);
		b2.executeForm(rrf);

		std::cout << std::endl;

		b1.executeForm(ppf);
		b1.signForm(ppf);
		b3.executeForm(ppf);
		b2.executeForm(ppf);
		b1.executeForm(ppf);

		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	return (0);
}
