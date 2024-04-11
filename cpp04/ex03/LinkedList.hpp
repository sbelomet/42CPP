/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:44:56 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/11 13:54:19 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_HPP
# define LINKEDLIST_HPP
# include "Node.hpp"

class LinkedList
{
	private:
		Node* _head;
	
	public:
		LinkedList(void);
		LinkedList(const LinkedList& other);
		LinkedList &operator=(const LinkedList &other);
		~LinkedList();

		Node* getHead(void) const;
		void addNode(AMateria* materia);
		int listSize(void) const;
		void clearList(void);
};

#endif

