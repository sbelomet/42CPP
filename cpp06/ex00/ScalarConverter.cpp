/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:59:11 by scherty           #+#    #+#             */
/*   Updated: 2024/07/03 11:28:20 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this;}

static void printImpossible(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

// Converter
void ScalarConverter::convert(const std::string &str)
{
	std::cout << std::fixed << std::setprecision(1);

	// Define special cases
	std::string specials[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan", "inf", "inff"};

	// Check if the string is a single character
	if (str.size() == 1 && !isdigit(str[0]) && isprint(str[0]))
	{
		std::cout << "char: " << "'" << str[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(str[0]) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
		return;
	}

	// Check if the string is a special case
	for (size_t i = 0; i < 8; i++)
	{
		if (str == specials[i])
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << atof(str.c_str()) << "f" << std::endl;
			std::cout << "double: " << atof(str.c_str()) << std::endl;
			return;
		}
	}

	// Check if the string contains no forbidden characters
	std::size_t nonDigit = 0;
	std::string duplicates = "";
	while ((nonDigit = str.find_first_not_of("0123456789", nonDigit)) != std::string::npos)
	{
		// Check if the string contains only digits and allowed characters
		if (!(str[nonDigit] == '.' || str[nonDigit] == 'f'
			|| str[nonDigit] == '+' || str[nonDigit] == '-'))
		{ return printImpossible(); }

		// Check if allowed characters are in the right place
		if (((str[nonDigit] == '+' || str[nonDigit] == '-') && nonDigit != 0)
			|| (str[nonDigit] == 'f' && nonDigit != str.size() - 1))
		{ return printImpossible(); }

		// Check if the string contains no duplicate allowed characters
		if (duplicates.find(str[nonDigit]) != std::string::npos)
		{ return printImpossible(); }

		duplicates += str[nonDigit];
		nonDigit++;
	}

	char c = 0;
	int i = 0;
	float f = 0;
	double d = 0;

	i = atoi(str.c_str());
	f = atof(str.c_str());
	d = atof(str.c_str());
	c = static_cast<char>(i);

	std::cout << "char: ";
	if (c < 0) { std::cout << "impossible" << std::endl; }
	else if (!isprint(c)) { std::cout << "non displayable" << std::endl; }
	else { std::cout << "'" << c << "'" << std::endl; }
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
