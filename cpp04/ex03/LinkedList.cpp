/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:44:53 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/11 15:55:47 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LinkedList.hpp"

// Default constructor
LinkedList::LinkedList(void)
{
	//std::cout << "LinkedList default constructor called" << std::endl;
	this->_head = 0;
	return ;
}

// Copy constructor
LinkedList::LinkedList(const LinkedList &other)
{
	//std::cout << "LinkedList copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
LinkedList &LinkedList::operator=(const LinkedList &other)
{
	//std::cout << "LinkedList assignment operator called" << std::endl;
	this->_head = other.getHead();
	return (*this);
}

// Destructor
LinkedList::~LinkedList(void)
{
	//std::cout << "LinkedList destructor called" << std::endl;
	return ;
}

Node* LinkedList::getHead(void) const
{
	return (this->_head);
}

void LinkedList::addNode(AMateria* materia)
{
	Node* newNode = new Node();
	newNode->setMateria(materia);
	newNode->setNext(this->_head);
	this->_head = newNode;
	return ;
}

int LinkedList::listSize(void) const
{
	int size = 0;
	Node* tmp = this->_head;
	while (tmp != 0)
	{
		size++;
		tmp = tmp->getNext();
	}
	return (size);
}

void LinkedList::clearList(void)
{
	Node* current = this->_head;
	Node* nextNode;
	Node* tmp;

	while (current != 0)
	{
		nextNode = current->getNext();
		tmp = nextNode;
		while (tmp != 0)
		{
			if (tmp == current)
			{
				tmp = 0;
			}
			else
			{
				tmp = tmp->getNext();
			}
		}
		delete current->getMateria();
		delete current;
		current = nextNode;
	}
}
