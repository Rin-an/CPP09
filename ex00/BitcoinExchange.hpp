/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:57:46 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/25 10:43:12 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <map>

class BitcoinExchange{
	std::map<std::string, float>			data;
	std::ifstream							file;
	public:
	BitcoinExchange();
		BitcoinExchange(std::string);
	    BitcoinExchange(const BitcoinExchange &a);
	    BitcoinExchange& operator=(const BitcoinExchange &a);
	    ~BitcoinExchange();
		void	setData(void);
		void	setFile(const std::string);
		void	exchangeRate(std::string&, float);
		void	parse(void);
};

#endif
