/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:08:21 by sbelomet          #+#    #+#             */
/*   Updated: 2024/06/26 15:48:55 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat(void): _name("UNNAMED"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return ;
}

// Constructor
Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	setGrade(grade);
	return ;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	_grade = other._grade;
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
	return ;
}

// Setter
void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

// Getters
std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

// Grade increment and decrement
void Bureaucrat::incrementGrade(void)
{
	try
	{
		setGrade(_grade - 1);
	}
	catch (std::exception &e)
	{
		std::cerr << _name << " grade incrementation failed: " << e.what() << std::endl;
	}
	return ;
}

void Bureaucrat::decrementGrade(void)
{
	try
	{
		setGrade(_grade + 1);
	}
	catch (std::exception &e)
	{
		std::cerr << _name << " grade incrementation failed: " << e.what() << std::endl;
	}
	return ;
}

// Sign form
void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (form.getSigned())
		std::cout << _name << " signed " << form.getName() << std::endl;
	else
		std::cout << _name << " couldn't sign " << form.getName() << " because grade is too low" << std::endl;
}

// Execute form
void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << form.getName() << " execution failed: " << e.what() << std::endl;
	}
}

// GradeTooHighException class
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

// GradeTooLowException class
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

// << operator overload
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}