/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:44:50 by sbelomet          #+#    #+#             */
/*   Updated: 2024/04/11 14:00:08 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP
# include "AMateria.hpp"

class Node
{
	private:
		AMateria* _materia;
		Node* _next;
	
	public:
		Node(void);
		Node(const Node& other);
		Node &operator=(const Node &other);
		~Node();

		AMateria* getMateria(void) const;
		Node* getNext(void) const;
		void setMateria(AMateria* materia);
		void setNext(Node* next);
};

#endif

