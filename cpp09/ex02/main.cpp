/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:56:44 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/25 11:04:24 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "USAGE: ./PmergeMe <positive numbers>" << std::endl;
		return 1;
	}

	std::string str;
	int i = 1;
	while(av[i])
	{
		str += av[i];
		str += " ";
		i++;
	}

	try
	{
		PmergeMe pmergeMe(str);
		pmergeMe.sort();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}

	return 0;
}