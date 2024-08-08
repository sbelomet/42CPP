/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:26:43 by sbelomet          #+#    #+#             */
/*   Updated: 2024/08/08 10:15:33 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}
RPN::RPN(const RPN &other) { (void)other; }
RPN &RPN::operator=(const RPN &other) { (void)other; return (*this); }
RPN::~RPN(void) {}

// Calculate the result of the RPN expression
void RPN::calculate(std::string &str)
{
	for (size_t i = 0; i < str.size(); i++) // Check if the expression is valid
	{
		if (str[i] == ' ')
			continue;
		if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')
			throw ForbiddenCharacterException();
		if (str[i + 1] != '\0' && str[i + 1] != ' ')
			throw InvalidExpressionException();
	}

	std::stack<int> stack;

	for (size_t i = 0; i < str.size(); i++) // Calculate the result
	{
		if (isdigit(str[i]))
		{
			stack.push(str[i] - '0');
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (stack.size() < 2)
				throw InvalidExpressionException();
	
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			if (str[i] == '+')
				stack.push(b + a);
			else if (str[i] == '-')
				stack.push(b - a);
			else if (str[i] == '*')
				stack.push(b * a);
			else if (str[i] == '/')
			{
				if (a == 0)
					throw InvalidExpressionException();
				stack.push(b / a);
			}
		}
	}
	if (stack.size() != 1)
		throw InvalidExpressionException();

	std::cout << "Result: " << stack.top() << std::endl;
}

// Exceptions
const char *RPN::InvalidExpressionException::what() const throw()
{
	return ("ERROR: Invalid expression");
}
const char *RPN::ForbiddenCharacterException::what() const throw()
{
	return ("ERROR: Forbidden character");
}