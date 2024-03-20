/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:01:15 by sbelomet          #+#    #+#             */
/*   Updated: 2024/03/20 13:27:46 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

#define MAX_CONTACTS 8
/* 
 _____ _               _____         _   
|  _  | |_ ___ ___ ___| __  |___ ___| |_ 
|   __|   | . |   | -_| __ -| . | . | '_|
|__|  |_|_|___|_|_|___|_____|___|___|_,_|
 */
void print_start_message(void)
{
	std::cout << " _____ _               _____         _   \n";
	std::cout << "|  _  | |_ ___ ___ ___| __  |___ ___| |_ \n";
	std::cout << "|   __|   | . |   | -_| __ -| . | . | '_|\n";
	std::cout << "|__|  |_|_|___|_|_|___|_____|___|___|_,_|\n\n";
	std::cout << "Available commands:\n";
	std::cout << " - ADD: Add a contact\n";
	std::cout << " - SEARCH: Display a saved contact\n";
	std::cout << " - EXIT: Close the PhoneBook (ALL DATA WILL BE LOST)\n";
}

void print_contact(Contact contact)
{
		std::cout << std::left << std::setw(20) << "First name: " << contact.first_name << "\n";
		std::cout << std::left << std::setw(20) << "Last name: " << contact.last_name << "\n";
		std::cout << std::left << std::setw(20) << "Nickname: " << contact.nickname << "\n";
		std::cout << std::left << std::setw(20) << "Phone number: " << contact.phone_num << "\n";
		std::cout << std::left << std::setw(20) << "Darkest secret: " << contact.darkest_secret << "\n";
}

void print_truncated(std::string str)
{
	if (str.size() <= 10)
		std::cout << "|" << std::setw(10) << str;
	else
		std::cout << "|" << str.substr(0, 9) << ".";
}

void print_table(PhoneBook phonebook)
{
	std::cout << " ------------------------------------------- \n";
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First name";
	std::cout << "|" << std::setw(10) << "Last name";
	std::cout << "|" << std::setw(10) << "Nickname";
	std::cout << "|\n";
	std::cout << "|----------|----------|----------|----------|\n";
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1;
		print_truncated(phonebook.contacts[i].first_name);
		print_truncated(phonebook.contacts[i].last_name);
		print_truncated(phonebook.contacts[i].nickname);
		std::cout << "|\n";
	}
	std::cout << " ------------------------------------------- \n";
}

bool is_digits(const std::string &str)
{
	return str.find_first_not_of("0123456789") == std::string::npos;
}

int	main()
{
	PhoneBook	phonebook;
	int			contact_index = 0;
	std::string	line;

	print_start_message();

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
			if (contact_index == MAX_CONTACTS - 1 && !phonebook.contacts[contact_index].first_name.empty())
			{
				phonebook.shift_contacts();
				phonebook.contacts[contact_index].clear_contact();
			}
			while (phonebook.contacts[contact_index].first_name.empty())
			{
				std::cout << "First name: ";
				std::getline(std::cin, phonebook.contacts[contact_index].first_name);
			}
			while (phonebook.contacts[contact_index].last_name.empty())
			{
				std::cout << "Last name: ";
				std::getline(std::cin, phonebook.contacts[contact_index].last_name);
			}
			while (phonebook.contacts[contact_index].nickname.empty())
			{
				std::cout << "Nickname: ";
				std::getline(std::cin, phonebook.contacts[contact_index].nickname);
			}
			while (phonebook.contacts[contact_index].phone_num.empty())
			{
				std::cout << "Phone number: ";
				std::getline(std::cin, phonebook.contacts[contact_index].phone_num);
			}
			while (phonebook.contacts[contact_index].darkest_secret.empty())
			{
				std::cout << "Darkest secret: ";
				std::getline(std::cin, phonebook.contacts[contact_index].darkest_secret);
			}
			if (contact_index < MAX_CONTACTS - 1)
				contact_index++;
		}
		else if (line == "SEARCH")
		{
			print_table(phonebook);
			
			std::string given_index;
			if (!phonebook.contacts[0].first_name.empty())
			{
				while (given_index.empty() || !is_digits(given_index))
				{
					std::cout << "Enter a contact index: ";
					std::getline(std::cin, given_index);
					if (is_digits(given_index) && atoi(given_index.c_str()) > 0 && atoi(given_index.c_str()) <= 8 && !phonebook.contacts[atoi(given_index.c_str()) - 1].first_name.empty())
					{
						print_contact(phonebook.contacts[atoi(given_index.c_str()) - 1]);
					}
					else
					{
						std::cout << "Not a valid index\n";
						given_index.clear();
					}
				}
			}
			else
				std::cout << "No contacts, add a new contact with ADD\n";
		}
		else if (line == "EXIT")
		{
			return (0);
		}
	}
}
