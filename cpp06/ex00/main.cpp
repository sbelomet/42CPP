/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:52:25 by scherty           #+#    #+#             */
/*   Updated: 2024/07/02 11:42:26 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 || !argv[1] || !argv[1][0])
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
