/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:42:03 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/02 10:45:56 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	this->setTarget("DEFAULT");
	return ;
}

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
	this->setTarget(target);
	return ;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
	AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute())
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	this->setTarget(other.getTarget());
	this->setSigned(other.getSigned());
	return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	return ;
}

// << operator overload
std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form)
{
	out << form.getName() << " is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
	return (out);
}

// Execute
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (!this->getSigned())
		throw AForm::FormNotSignedException();

	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream fileOut(filename.c_str());

	if (fileOut.is_open())
	{
		fileOut << "               ,@@@@@@@," << std::endl;
		fileOut << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
		fileOut << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
		fileOut << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
		fileOut << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
		fileOut << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
		fileOut << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
		fileOut << "       |o|        | |         | |" << std::endl;
		fileOut << "       |.|        | |         | |" << std::endl;
		fileOut << "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;

		fileOut.close();
	}
	else
		throw std::runtime_error("Could not open file for writing.");
	return ;
}

// Clone
AForm *ShrubberyCreationForm::clone(const std::string target) const
{
	return (new ShrubberyCreationForm(target));
}