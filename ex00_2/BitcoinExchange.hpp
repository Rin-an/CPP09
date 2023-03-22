/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:57:46 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/22 16:21:03 by ssadiki          ###   ########.fr       */
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
#include <map>
#include <utility>

class BitcoinExchange{
	std::multimap<std::string, float>			data;
	std::vector<std::pair<std::string, float> >	f_data;
	std::ifstream								file;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string);
	    BitcoinExchange(const BitcoinExchange &a);
	    BitcoinExchange& operator=(const BitcoinExchange &a);
	    ~BitcoinExchange();
		void	setData(void);
		void	setFdata(void);
		void	echangeRate();
		void	parse();
};

#endif
