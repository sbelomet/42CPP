/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:42:17 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/02 09:48:21 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdlib.h>
#include <time.h>

// Default constructor
RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("RobotomyRequestFrom", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	this->setTarget("DEFAULT");
	srand(time(NULL));
	return ;
}

// Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	AForm("RobotomyRequestFrom", 72, 45)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
	this->setTarget(target);
	srand(time(NULL));
	return ;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
	AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = other;
	srand(time(NULL));
	return ;
}

// Assignment operator overload
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	this->setTarget(other.getTarget());
	this->setSigned(other.getSigned());
	return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
	return ;
}

// << operator overload
std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &form)
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
void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (!this->getSigned())
		throw AForm::FormNotSignedException();

	std::cout << "*bRRRRRZZZZZZZKakAAKAKAAAVRRRrrRRRRRR* ";
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getTarget() << " robotomization failed" << std::endl;
	return ;
}