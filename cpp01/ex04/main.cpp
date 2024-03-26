/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:44:59 by sbelomet          #+#    #+#             */
/*   Updated: 2024/03/26 14:32:20 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "INCORRECT USAGE: Try ./sed_is_for_losers <filename> <string to replace> <string to replace with>\n";
		return 0;
	}

	std::string fileName = av[1];
	std::string toReplace = av[2];
	std::string replaceBy = av[3];

	std::ifstream infile;
	std::ofstream outfile;

	infile.open(fileName, std::fstream::in);
	outfile.open(fileName + ".replace");
	if (!infile.is_open() || !outfile.is_open())
	{
		std::cerr << "INVALID FILE\n";
		return 0;
	}

	std::string line;
	while (std::getline(infile, line))
	{
		std::size_t found = line.find(toReplace, 0);
		while (found != std::string::npos)
		{
			line.erase(found, toReplace.size());
			line.insert(found, replaceBy);
			found = line.find(toReplace, found + replaceBy.size());
		}
		outfile << line << "\n";
	}

	infile.close();
	outfile.close();
}
