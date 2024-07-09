/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:48:32 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/09 14:30:40 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>

class Span
{
	private:
		std::vector<int> _container;
		unsigned int _size;

	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span& other);
		Span &operator=(const Span &other);
		~Span();

		unsigned int getSize(void) const;
		std::vector<int> getContainer(void) const;

		void addNumber(int number);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan(void) const;
		int longestSpan(void) const;

		class ContainerFullException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class NotEnoughNumbersException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Span &span);

#endif
