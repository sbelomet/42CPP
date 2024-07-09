/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:53:01 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/09 15:12:46 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL));
	{
		Span sp = Span(5);

		try
		{
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		try
		{
			sp.addNumber(11);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << sp << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "--------------------------------" << std::endl;

	{
		int size = 10;
		int range = 1000;

		Span sp = Span(size);

		for (int i = 0; i < size; i++)
			sp.addNumber(rand() % range * 2 - range);

		std::cout << sp << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "--------------------------------" << std::endl;

	{
		Span sp = Span(10000);

		for (int i = 0; i < 10000; i++)
			sp.addNumber(rand() % 100000);

		//std::cout << sp << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "--------------------------------" << std::endl;

	{
		Span sp = Span(15);
		std::vector<int> vec;

		for (size_t i = 0; i < 10; i++)
		{
			vec.push_back(rand() % 100);
		}
		sp.addNumber(-3);
		sp.addNumber(0);
		sp.addNumber(3);
		sp.addNumber(vec.begin(), vec.end());
		sp.addNumber(-5);
		sp.addNumber(10);

		std::cout << sp << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

}
