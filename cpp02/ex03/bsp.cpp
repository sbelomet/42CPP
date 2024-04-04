/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:50:04 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/03 16:03:12 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed ft_abs(Fixed num)
{
	if (num < 0)
		return num * -1;
	return num;
}

Fixed pow(Fixed base, int exp)
{
	Fixed result(1.0f);

	for(int i = 0; i < exp; i++)
		result = result * base;
	return result;
}

Fixed sqrt(Fixed x)
{
    Fixed guess(1.0f);
    Fixed epsilon(0.00001f); // precision
	int maxIterations = 100; // maximum number of iterations

    int i = 0;
    while (ft_abs(guess * guess - x) >= epsilon && i < maxIterations) {
        guess = (guess + x / guess) / 2;
        i++;
    }
    return guess;
}

Fixed ft_area(Point const &a, Point const &b, Point const &c)
{
	Fixed bminusc = b.getY() - c.getY();
	Fixed cminusa = c.getY() - a.getY();
	Fixed aminusb = a.getY() - b.getY();
	Fixed area = (a.getX() * bminusc + b.getX() * cminusa + c.getX() * aminusb) / 2;
/* 	
	std::cout << "b.getY(): " << b.getY() << "\n";
	std::cout << "c.getY(): " << c.getY() << "\n";
	std::cout << "bminusc: " << bminusc << "\n";
	std::cout << "cminusa: " << cminusa << "\n";
	std::cout << "aminusb: " << aminusb << "\n";
	std::cout << "area: " << area << "\n"; */

	return ft_abs(area);
}

Fixed distanceFromLine(Point a, Point b, Point p)
{
	Fixed numerator = ft_abs((b.getY() - a.getY()) * p.getX() - (b.getX() - a.getX()) * p.getY() + b.getX() * a.getY() - b.getY() * a.getX());
	Fixed denominator(sqrt(pow(b.getY() - a.getY(), 2) + pow(b.getX() - a.getX(), 2)));
	return numerator / denominator;
}

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point)
{
	Fixed totalArea;
	Fixed areaA;
	Fixed areaB;
	Fixed areaC;

	if (distanceFromLine(a, b, point) == 0 || distanceFromLine(b, c, point) == 0 || distanceFromLine(c, a, point) == 0) {
        // The point is on the edge of the triangle
        return false;
    }

	/* std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << c << "\n";	
	std::cout << point << "\n"; */

	totalArea = ft_area(a, b, c);
	areaA = ft_area(point, a, b);
	areaB = ft_area(point, b, c);
	areaC = ft_area(point, c, a);

	//int test = totalArea.getRawBits();

/* 	std::cout << "total area: " << totalArea << "\n";
	std::cout << "areaA: " << areaA << "\n";
	std::cout << "areaB: " << areaB << "\n";
	std::cout << "areaC: " << areaC << "\n";
	std::cout << "total area: " << areaA + areaB + areaC << "\n"; */

	return totalArea == areaA + areaB + areaC;
}
