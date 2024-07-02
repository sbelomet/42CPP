/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:54:42 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/02 15:28:04 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data data;
	data.s1 = "SEVEN MILLION";
	data.n = 7000000;
	data.s2 = "qwertyuiopasdfghjklzxcvbnm,./;[]{}-=_+!@#$%^&*()1234567890<>?|\\\"':<>?";

	std::cout << "Data before serialization:" << std::endl;
	std::cout << "s1: " << data.s1 << std::endl;
	std::cout << "n: " << data.n << std::endl;
	std::cout << "s2: " << data.s2 << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);
	std::cout << std::endl;

	std::cout << "Data after deserialization:" << std::endl;
	std::cout << "s1: " << ptr->s1 << std::endl;
	std::cout << "n: " << ptr->n << std::endl;
	std::cout << "s2: " << ptr->s2 << std::endl;
	return (0);
}
