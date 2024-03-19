/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:01:15 by sbelomet          #+#    #+#             */
/*   Updated: 2024/03/19 15:55:01 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	print_contact(Contact contact)
{
		std::cout << "First name: " << contact.first_name << "\n";
		std::cout << "Last name: " << contact.last_name << "\n";
		std::cout << "Nickname: " << contact.nickname << "\n";
		std::cout << "Phone number: " << contact.phone_num << "\n";
		std::cout << "Darkest secret: " << contact.darkest_secret << "\n";
		return (0);
}

int	main()
{
	PhoneBook	phonebook;
	int			contact_index = 0;
	std::string	line;

	while (1)
	{
		std::cout << ">> ";
		std::getline(std::cin, line);

		for (size_t i = 0; i < line.size(); i++)
		{
			line[i] = toupper(line[i]);
		}

		if (line == "ADD")
		{
			if (contact_index < 8)
			{
				while (phonebook.contacts[contact_index].first_name == "")
				{
					std::cout << "First name: ";
					std::getline(std::cin, phonebook.contacts[contact_index].first_name);
				}
				while (phonebook.contacts[contact_index].last_name == "")
				{
					std::cout << "Last name: ";
					std::getline(std::cin, phonebook.contacts[contact_index].last_name);
				}
				while (phonebook.contacts[contact_index].nickname == "")
				{
					std::cout << "Nickname: ";
					std::getline(std::cin, phonebook.contacts[contact_index].nickname);
				}
				while (phonebook.contacts[contact_index].phone_num == "")
				{
					std::cout << "Phone number: ";
					std::getline(std::cin, phonebook.contacts[contact_index].phone_num);
				}
				while (phonebook.contacts[contact_index].darkest_secret == "")
				{
					std::cout << "Darkest secret: ";
					std::getline(std::cin, phonebook.contacts[contact_index].darkest_secret);
				}
				contact_index++;
			}
		}
		else if (line == "SEARCH")
		{
			std::cout << "---------------------------------------------\n|";
			std::cout << std::setw(10) << "Index" << "|";
			std::cout << std::setw(10) << "First name" << "|";
			std::cout << std::setw(10) << "Last name" << "|";
			std::cout << std::setw(10) << "Nickname" << "|";
			std::cout << "\n";
			std::cout << "|----------|----------|----------|----------|\n";
			for (int i = 0; i < 8; i++)
			{
				if (phonebook.contacts[i].first_name != "")
				{
					std::cout << "|" << std::setw(10) << i;
					std::cout << "|" << std::setw(10) << phonebook.contacts[i].first_name;
					std::cout << "|" << std::setw(10) << phonebook.contacts[i].last_name;
					std::cout << "|" << std::setw(10) << phonebook.contacts[i].nickname;
					std::cout << "|\n";
				}
			}
			
			
		}
		else if (line == "EXIT")
		{
			return (0);
		}
	}
}
