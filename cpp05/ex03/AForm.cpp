/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:48:13 by sbelomet          #+#    #+#             */
/*   Updated: 2024/06/26 14:29:12 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Default constructor
AForm::AForm(void):
	_name("UNNAMED"),_signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "AForm default constructor called" << std::endl;
	return ;
}

// Constructor
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute):
	_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "AForm constructor called" << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	return ;
}

// Copy constructor
AForm::AForm(const AForm &other):
	_name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm assignment operator called" << std::endl;
	_signed = other._signed;
	return (*this);
}

// << operator overload
std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "AForm " << form.getName() << " is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
	return (out);
}

// Destructor
AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
	return ;
}

// Getters
std::string AForm::getName(void) const
{
	return (_name);
}

bool AForm::getSigned(void) const
{
	return (_signed);
}

int AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

std::string AForm::getTarget(void) const
{
	return (_target);
}

// Setters
void AForm::setTarget(std::string target)
{
	_target = target;
}

void AForm::setSigned(bool is_signed)
{
	_signed = is_signed;
}

// beSigned member function
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

// GradeTooHighException class
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

// GradeTooLowException class
const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

// FormNotSignedException class
const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form hasn't been signed");
}