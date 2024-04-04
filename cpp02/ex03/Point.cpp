#include "Point.hpp"

// Default constructor
Point::Point(void)
{
    //std::cout << "Default constructor called" << std::endl;
	this->_x = Fixed(0);
	this->_y = Fixed(0);
    return ;
}

Point::Point(const float x, const float y)
{
	this->_x = Fixed(x);
	this->_y = Fixed(y);
    return ;
}

// Copy constructor
Point::Point(const Point &other)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = other;
    return ;
}

// Assignment operator overload
Point &Point::operator=(const Point &other)
{
    //std::cout << "Assignment operator called" << std::endl;
    this->_x = other._x;
	this->_y = other._y;
    return (*this);
}

std::ostream &operator<<(std::ostream &o, const Point &P)
{
	o << "Point(" << P.getX() << ", " << P.getY() << ")";
	return o;
}

// Destructor
Point::~Point(void)
{
    //std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed Point::getX(void) const
{
	return this->_x;
}

Fixed Point::getY(void) const
{
	return this->_y;
}
