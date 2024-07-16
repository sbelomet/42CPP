/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:41:15 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/16 15:45:16 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <algorithm>

// Default constructor
BitcoinExchange::BitcoinExchange(void) {}

// Constructor
BitcoinExchange::BitcoinExchange(std::string dictFile)
{
	std::cout << "BitcoinExchange constructor called" << std::endl;
	parse(dictFile);
	return ;
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
	*this = other;
	return ;
}

// Assignment operator overload
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	std::cout << "BitcoinExchange assignment operator called" << std::endl;
	_dict = other._dict;
	return (*this);
}

// Destructor
BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
	return ;
}

// Getters
std::map<int, float> BitcoinExchange::getDict() const
{
	return (_dict);
}

// Parse date
static int parseDate(std::string &date)
{
	if (date.size() != 10)
	{
		std::cerr << "ERROR: invalid date format" << std::endl;
		exit(1);
	}
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
			{
				std::cerr << "ERROR: invalid date format" << std::endl;
				exit(1);
			}
		}
		else if (!std::isdigit(date[i]))
		{
			std::cerr << "ERROR: invalid date format" << std::endl;
			exit(1);
		}
	}
	
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	bool leapYear = false;

	

}

// Parse dictionary
void BitcoinExchange::parse(const std::string dictFile)
{
	std::string reversed(dictFile.rbegin(), dictFile.rend());
	if (reversed.find("vsc.") != 0)
	{
		std::cerr << "ERROR: invalid file extension" << std::endl;
		exit(1);
	}
	std::ifstream file(dictFile);
	if (!file.is_open())
	{
		std::cerr << "ERROR: could not open file" << std::endl;
		exit(1);
	}
	std::string line;
	if (std::getline(file, line) && line != "date,exchange_rate")
	{
		std::cerr << "ERROR: invalid file header" << std::endl;
		exit(1);
	}
	while (std::getline(file, line))
	{
		std::string dateString = line.substr(0, line.find(","));
		int date = parseDate(dateString);
		std::string value = line.substr(line.find(",") + 1);
		_dict[date] = std::stof(value);
	}
	file.close();
}

// << operator overload
std::ostream &operator<<(std::ostream &out, const BitcoinExchange &obj)
{
	std::map<int, float> dict = obj.getDict();
	
	out << "BitcoinExchange Dictionary: {";
	for (std::map<int, float>::const_iterator it = dict.begin(); it != dict.end(); ++it)
	{
		out << "[" << it->first << ":" << it->second << "]";
		if (std::next(it) != dict.end())
			out << ",";
	}
	out << "}";
	return (out);
}
