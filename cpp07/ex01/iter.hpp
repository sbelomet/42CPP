/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:15:03 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/09 15:09:51 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void iter(T *array, size_t size, void (*func)(T const &))
{
	for (size_t i = 0; i < size; i++)
		func(array[i]);
}

template <typename T>
void print(T &i)
{
	std::cout << i << std::endl;
}

template <typename T>
void print(T const &i)
{
	std::cout << i << std::endl;
}

#endif
