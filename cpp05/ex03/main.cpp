/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:55:24 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/02 10:55:24 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Big Boss", 1);
		Bureaucrat b2("Kafka", 41);
		Bureaucrat b3("Julien", 141);
		Intern intern;

		std::cout << std::endl;

		AForm *scf = NULL;
		scf = intern.makeForm("shrubbery creation", "home");
		b1.executeForm(*scf);
		b1.signForm(*scf);
		b3.executeForm(*scf);
		b2.executeForm(*scf);

		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	return (0);
}