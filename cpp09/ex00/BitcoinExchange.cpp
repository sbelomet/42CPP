/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:41:15 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/23 14:01:36 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <algorithm>

// Default constructor
BitcoinExchange::BitcoinExchange(void) {}

// Constructor
BitcoinExchange::BitcoinExchange(std::string dbFile)
{
	std::cout << "BitcoinExchange constructor called" << std::endl;
	parse(dbFile);
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
	_database = other._database;
	return (*this);
}

// Destructor
BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
	return ;
}

// Getters
std::map<int, float> BitcoinExchange::getDatabase() const
{
	return (_database);
}

// Parse date
static int parseDate(std::string &date)
{
	if (date.size() != 10) // Check for correct length
		throw BitcoinExchange::InvalidDateException();

	for (size_t i = 0; i < date.size(); i++) // Check for correct format
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				throw BitcoinExchange::InvalidDateException();
		}
		else if (!std::isdigit(date[i]))
			throw BitcoinExchange::InvalidDateException();
	}
	
	std::string year = date.substr(0, 4);
	int yearInt = std::stoi(year);
	std::string month = date.substr(5, 2);
	int monthInt = std::stoi(month);
	std::string day = date.substr(8, 2);
	int dayInt = std::stoi(day);
	bool leapYear = (yearInt % 4 == 0 && yearInt % 100 != 0) || yearInt % 400 == 0;

	if (monthInt > 12) // Check if month is valid
	{
		throw BitcoinExchange::InvalidDateException();
	}
	if ((leapYear && monthInt == 2 && dayInt > 29)
		|| (!leapYear && monthInt == 2 && dayInt > 28)) // Check if day is valid for february
	{
		throw BitcoinExchange::InvalidDateException();
	}
	if ((monthInt < 8 && monthInt % 2 == 1 && dayInt > 31)
		|| (monthInt > 7 && monthInt % 2 == 0 && dayInt > 31)) // Check if day is valid for months with 31 days
	{
		throw BitcoinExchange::InvalidDateException();
	}
	if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11)
		&& dayInt > 30) // Check if day is valid for months with 30 days
	{
		throw BitcoinExchange::InvalidDateException();
	}
	return (yearInt * 10000 + monthInt * 100 + dayInt);
}

// Parse value
static float parseValue(std::string &value)
{
	for (size_t i = 0; i < value.size(); i++)
	{
		if (!std::isdigit(value[i]) && value[i] != '.')
			throw BitcoinExchange::InvalidValueException();
	}
	float valueFloat = std::stof(value);
	if (valueFloat < 0 || valueFloat > 1000)
		throw BitcoinExchange::InvalidValueException();
	return (valueFloat);
}

// Parse dictionary
void BitcoinExchange::parse(const std::string dbFile)
{
	std::string reversed(dbFile.rbegin(), dbFile.rend());
	if (reversed.find("vsc.") != 0)
	{
		throw BitcoinExchange::InvalidFileExtentionException();
	}
	std::ifstream file(dbFile);
	if (!file.is_open())
	{
		throw BitcoinExchange::UnopenableFileException();
	}
	std::string line;
	if (std::getline(file, line) && line != "date,exchange_rate")
	{
		throw BitcoinExchange::InvalidHeaderException();
	}
	while (std::getline(file, line))
	{
		std::string dateString = line.substr(0, line.find(","));
		std::string value = line.substr(line.find(",") + 1);
		try
		{
			_database[parseDate(dateString)] = parseValue(value);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			break;
		}
	}
	file.close();
}

// Convert
void BitcoinExchange::convert(std::string line)
{
	std::cout << line << std::endl;
}

// << operator overload
std::ostream &operator<<(std::ostream &out, const BitcoinExchange &obj)
{
	std::map<int, float> dict = obj.getDatabase();
	
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

// Exceptions
const char* BitcoinExchange::InvalidFileExtentionException::what() const throw()
{
	return ("ERROR: invalid file extension");
}
const char* BitcoinExchange::UnopenableFileException::what() const throw()
{
	return ("ERROR: could not open file");
}
const char* BitcoinExchange::InvalidHeaderException::what() const throw()
{
	return ("ERROR: invalid file header");
}
const char* BitcoinExchange::InvalidDateException::what() const throw()
{
	return ("ERROR: invalid date format");
}
const char* BitcoinExchange::InvalidValueException::what() const throw()
{
	return ("ERROR: invalid value format");
}
