/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:31:06 by sbelomet          #+#    #+#             */
/*   Updated: 2024/03/20 11:36:40 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void Contact::clear_contact(void)
{
	first_name.clear();
	last_name.clear();
	nickname.clear();
	phone_num.clear();
	darkest_secret.clear();
}
