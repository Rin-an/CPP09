/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:57:46 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/17 13:28:31 by ssadiki          ###   ########.fr       */
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
	std::vector<char *>	date;
	std::vector<std::string>	value;
	//std::vector<
	public:
	    BitcoinExchange();
	    BitcoinExchange(const BitcoinExchange &a);
	    BitcoinExchange& operator=(const BitcoinExchange &a);
	    ~BitcoinExchange();
		void	setDate(char *);
};

#endif
