/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:17:51 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/03 11:29:17 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int array1[] = {1, 2, 3, 4, 5};
	iter(array1, 5, print);

	std::cout << std::endl;

	char array2[] = "Hello";
	iter(array2, 5, print);

	return (0);
}
