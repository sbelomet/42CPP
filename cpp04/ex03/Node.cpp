/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:44:47 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/11 14:16:39 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Node.hpp"

// Default constructor
Node::Node(void)
{
	//std::cout << "Node default constructor called" << std::endl;
	this->_materia = 0;
	this->_next = 0;
	return ;
}

// Copy constructor
Node::Node(const Node &other)
{
	//std::cout << "Node copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
Node &Node::operator=(const Node &other)
{
	//std::cout << "Node assignment operator called" << std::endl;
	this->_materia = other.getMateria();
	this->_next = other.getNext();
	return (*this);
}

// Destructor
Node::~Node(void)
{
	//std::cout << "Node destructor called" << std::endl;
	return ;
}

AMateria* Node::getMateria(void) const
{
	return (this->_materia);
}

Node* Node::getNext(void) const
{
	return (this->_next);
}

void Node::setMateria(AMateria* materia)
{
	this->_materia = materia;
	return ;
}

void Node::setNext(Node* next)
{
	this->_next = next;
	return ;
}
