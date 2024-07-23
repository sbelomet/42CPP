/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:41:10 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/23 13:04:31 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <string>
# include <map>

class BitcoinExchange
{
	private:
		BitcoinExchange(void);
		void parse(const std::string dbFile);
		std::map<int, float> _database;
	
	public:
		BitcoinExchange(const std::string dbFile);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		std::map<int, float> getDatabase() const;

		void convert(std::string line);

		class InvalidFileExtentionException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class UnopenableFileException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InvalidHeaderException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InvalidDateException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class InvalidValueException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const BitcoinExchange &obj);

#endif
