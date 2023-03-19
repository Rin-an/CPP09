/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:57:46 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/19 14:33:22 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>

class BitcoinExchange{
	std::vector<std::string>	date;
	std::vector<std::string>	value;
	std::vector<std::string>	data;
	public:
	    BitcoinExchange();
	    BitcoinExchange(const BitcoinExchange &a);
	    BitcoinExchange& operator=(const BitcoinExchange &a);
	    ~BitcoinExchange();
		void	setDate(const std::string&);
		void	setValue(const std::string&);
		void	setData(const std::string&);
		const std::vector<std::string>& getDate(void) const;
		const std::vector<std::string>&	getValue(void) const;
		int		to_int(const std::string&);
		float	to_float(const std::string&);
		int		calculateBitcoin(int);
		float	calculateBitcoin(float);
};

#endif
