/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:09:21 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/23 11:45:54 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i + 10); // 10 11 12 13 14 15 16 17 18 19

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 15);
		std::cout << "Found element " << *it;
		std::cout << " at position " << std::distance(vec.begin(), it) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Element not found" << std::endl;
	}

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 6);
		std::cout << "Found element " << *it;
		std::cout << " at position " << std::distance(vec.begin(), it) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Element not found" << std::endl;
	}
	return 0;
}
