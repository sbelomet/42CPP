/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:40:32 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/23 13:59:18 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "USAGE: ./btc <file>" << std::endl;
		return (1);
	}
	std::ifstream file(av[1]);
	if (!file.is_open())
	{
		std::cerr << "ERROR: could not open file" << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange btc("data.csv");
	
		std::string line;
		if (std::getline(file, line) && line != "date | value")
		{
			std::cerr << "ERROR: invalid file header" << std::endl;
			return (1);
		}
		while (std::getline(file, line))
		{
			btc.convert(line);
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	//std::cout << btc << std::endl;

	
	file.close();
	return (0);
}
