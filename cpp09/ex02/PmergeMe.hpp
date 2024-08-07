/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:05:07 by sbelomet          #+#    #+#             */
/*   Updated: 2024/08/07 13:04:38 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>
# include <deque>

class PmergeMe
{
	private:
		PmergeMe(void);
		void parseArgs();

		std::string _args;
		size_t _size;
	
	public:
		PmergeMe(const std::string &args);
		PmergeMe(const PmergeMe& other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void sort();
		void sortVector();
		void sortDeque();

		class InvalidArgument : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
