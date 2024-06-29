/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scherty <scherty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:42:25 by sbelomet          #+#    #+#             */
/*   Updated: 2024/06/27 11:31:58 by scherty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	this->setTarget("DEFAULT");
	return ;
}

// Constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
	this->setTarget(target);
	return ;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
	AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute())
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	this->setTarget(other.getTarget());
	this->setSigned(other.getSigned());
	return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
	return ;
}

// << operator overload
std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &form)
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
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw PresidentialPardonForm::GradeTooLowException();
	if (!this->getSigned())
		throw PresidentialPardonForm::FormNotSignedException();

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox !" << std::endl;
	return ;
}
