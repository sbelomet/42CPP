/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:57:25 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/02 10:54:41 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Default constructor
Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
	this->forms[0] = new ShrubberyCreationForm();
	this->forms[1] = new RobotomyRequestForm();
	this->forms[2] = new PresidentialPardonForm();
	return ;
}

// Copy constructor
Intern::Intern(const Intern &other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern assignment operator called" << std::endl;
	(void) other;
	this->forms[0] = new ShrubberyCreationForm();
	this->forms[1] = new RobotomyRequestForm();
	this->forms[2] = new PresidentialPardonForm();
	return (*this);
}

// Destructor
Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
	for (size_t i = 0; i < 3; i++)
		delete this->forms[i];
	return ;
}

// FormNotFoundException
const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Intern couldn't find the form");
}

// Make form
AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string upperFormName = formName;
	for (size_t i = 0; i < upperFormName.length(); i++)
		upperFormName[i] = toupper(upperFormName[i]);

	std::string formNames[3] = {
		"SHRUBBERY CREATION",
		"ROBOTOMY REQUEST",
		"PRESIDENTIAL PARDON"};

	for (size_t i = 0; i < formNames->length(); i++)
	{
		if (formNames[i] == upperFormName)
		{
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return (forms[i]->clone(target));
		}
	}
	throw Intern::FormNotFoundException();
}
