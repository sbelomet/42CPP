/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:13:28 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/03 16:07:52 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	bool triangle1 = bsp(Point(2, 2), Point(-4, 3), Point(-4, 0), Point(-1, 2));
	bool triangle2 = bsp(Point(2, 2), Point(-4, 3), Point(-4, 0), Point(0, 4));
	bool triangle3 = bsp(Point(2, 2), Point(-4, 3), Point(-4, 0), Point(-4, 2.4263f));
	bool triangle4 = bsp(Point(1.58961f, -2.48899f), Point(-3.6658f, -5.1167f), Point(2, -10), Point(0.70083f, -6.31462f));
	bool triangle5 = bsp(Point(1.58961f, -2.48899f), Point(-3.6658f, -5.1167f), Point(2, -10), Point(3.36718f, -5.81227f));
	bool triangle6 = bsp(Point(1.58961f, -2.48899f), Point(-3.6658f, -5.1167f), Point(2, -10), Point(1.58961f, -2.48899f));
	
	std::cout << "True: " << true << "\n";
	std::cout << "False: " << false << "\n";
	std::cout << "Triangle1: " << triangle1 << "\n";
	std::cout << "Triangle2: " << triangle2 << "\n";
	std::cout << "Triangle3: " << triangle3 << "\n";
	std::cout << "Triangle4: " << triangle4 << "\n";
	std::cout << "Triangle5: " << triangle5 << "\n";
	std::cout << "Triangle6: " << triangle6 << "\n";
}
