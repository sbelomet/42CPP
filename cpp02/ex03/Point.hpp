/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:19:09 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/03 15:25:28 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
    private:
		Fixed _x;
		Fixed _y;
	
	public:
        Point(void);
		Point(const float x, const float y);
        Point(const Point& other);
        Point &operator=(const Point &other);
        ~Point();

		Fixed getX(void) const;
		Fixed getY(void) const;
};

std::ostream &operator<<(std::ostream &o, const Point &F);

bool bsp(Point const &a, Point const &b, Point const &c, Point const &point);

#endif
