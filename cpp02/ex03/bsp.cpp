/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:50:04 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/02 15:34:12 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed ft_abs(Fixed num)
{
	if (num < 0)
		return num * -1;
	return num;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed totalArea;
	Fixed areaA;
	Fixed areaB;
	Fixed areaC;

	totalArea = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2;
	areaA = (a.getX() * (b.getY() - point.getY()) + b.getX() * (point.getY() - a.getY()) + point.getX() * (a.getY() - b.getY())) / 2;
	areaB = (a.getX() * (point.getY() - c.getY()) + point.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - point.getY())) / 2;
	areaC = (point.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - point.getY()) + c.getX() * (point.getY() - b.getY())) / 2;

	std::cout << totalArea << "\n";
	std::cout << areaA << "\n";
	std::cout << areaB << "\n";
	std::cout << areaC << "\n";
	std::cout << areaA + areaB + areaC << "\n";

	return ft_abs(totalArea) == ft_abs(areaA) + ft_abs(areaA) + ft_abs(areaA);
}
