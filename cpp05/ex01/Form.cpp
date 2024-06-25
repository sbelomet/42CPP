/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:44:57 by sbelomet          #+#    #+#             */
/*   Updated: 2024/06/25 15:29:53 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Default constructor
Form::Form(void):
	_name("UNNAMED"),_signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
	return ;
}

// Constructor
Form::Form(std::string name, int gradeToSign, int gradeToExecute):
	_name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form constructor called" << std::endl;
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
	return ;
}

// Copy constructor
Form::Form(const Form &other):
	_name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
Form &Form::operator=(const Form &other)
{
	std::cout << "Form assignment operator called" << std::endl;
	_signed = other._signed;
	return (*this);
}

// << operator overload
std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute";
	return (out);
}

// Destructor
Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
	return ;
}

// Getters
std::string Form::getName(void) const
{
	return (_name);
}

bool Form::getSigned(void) const
{
	return (_signed);
}

int Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute(void) const
{
	return (_gradeToExecute);
}

// GradeTooHighException class
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

// GradeTooLowException class
const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}