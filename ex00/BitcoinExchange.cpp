/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:58:30 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/17 13:28:39 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange: Default constructor called!" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &a)
{
	std::cout << "BitcoinExchange: Copy constructor called!" << std::endl;
	*this = a;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &a)
{
	if (this != &a)
	{
		std::cout << "BitcoinExchange: Copy assignment operator called!" << std::endl;
		this->date = a.date;
		this->value = a.value;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange: Destructor called!" << std::endl;
}

void	BitcoinExchange::setDate(char* date)
{
	/*str.copy(this->date, str.find('|'), 0);
	if (!strptime(date, "%Y-%m-%d", &tm) || tm.tm_year <= -901)
		std::cout << "Error: date is not valid!" << std::endl;*/
	this->date.push_back(date);
}
