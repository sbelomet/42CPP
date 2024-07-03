/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:39:21 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/03 13:00:06 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"

int main(void)
{
	{
		Array<int> a(5);
		Array<int> b(5);

		for (unsigned int i = 0; i < a.size(); i++)
		{
			a[i] = i;
			b[i] = i + 5;
		}

		std::cout << "Array a: " << a << std::endl;
		std::cout << "Array b: " << b << std::endl;

		Array<int> c(a);

		std::cout << "Array c: " << c << std::endl;

		Array<int> d;

		d = b;
		d[d.size() - 1] = 42;

		std::cout << "Array b: " << b << std::endl;
		std::cout << "Array d: " << d << std::endl;
	}

	std::cout << std::endl;

	{
		Array<char> a(5);
		Array<char> b(5);

		for (unsigned int i = 0; i < a.size(); i++)
		{
			a[i] = i + 65;
			b[i] = i + 70;
		}

		std::cout << "Array a: " << a << std::endl;
		std::cout << "Array b: " << b << std::endl;

		Array<char> c(a);

		std::cout << "Array c: " << c << std::endl;

		Array<char> d;

		d = b;
		d[d.size() - 1] = 42;

		std::cout << "Array b: " << b << std::endl;
		std::cout << "Array d: " << d << std::endl;
	}

	return 0;
}
