/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:44:37 by sbelomet          #+#    #+#             */
/*   Updated: 2024/03/20 12:50:15 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

void PhoneBook::shift_contacts(void)
{
	for (int i = 1; i < 8; i++)
	{
		contacts[i - 1] = contacts[i];
	}
	
}
