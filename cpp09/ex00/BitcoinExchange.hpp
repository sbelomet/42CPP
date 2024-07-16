/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:41:10 by sbelomet          #+#    #+#             */
/*   Updated: 2024/07/16 12:51:22 by sbelomet         ###   ########.fr       */
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
		void parse(const std::string dictFile);
		std::map<int, float> _dict;
	
	public:
		BitcoinExchange(const std::string dictFile);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		std::map<int, float> getDict() const;
		std::string convert(std::string line);
};

std::ostream &operator<<(std::ostream &out, const BitcoinExchange &obj);

#endif
