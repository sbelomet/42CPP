/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scherty <scherty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:59:11 by scherty           #+#    #+#             */
/*   Updated: 2024/06/28 10:31:25 by scherty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iomanip>

// Converter
void ScalarConverter::convert(const std::string &str)
{
	std::cout << std::fixed << std::setprecision(1);

	char c;
	int i;
	float f;
	double d;

	if (str.find_first_of("0123456789") == std::string::npos && str.size() == 1)
	{
		c = str[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else if (str.find_first_of("0123456789") == std::string::npos && str.size() != 1)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	else
	{
		f = atof(str.c_str());
		d = atof(str.c_str());
		i = static_cast<int>(f);
		if (f - static_cast<float>(i) == 0)
			c = static_cast<char>(i);
		else
			c = -1;
	}

	std::cout << "char: ";
	if (c < 0)
		std::cout << "impossible" << std::endl;
	else if (c < 32 || c > 126)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
