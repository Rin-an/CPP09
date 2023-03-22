/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:58:30 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/22 16:25:52 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
//	std::cout << "BitcoinExchange: Default constructor called!" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string file)
{
	this->file.open(file);
	if (!this->file)
		throw ("Error: could not open file!");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &a)
{
//	std::cout << "BitcoinExchange: Copy constructor called!" << std::endl;
	*this = a;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &a)
{
	if (this != &a)
	{
		//std::cout << "BitcoinExchange: Copy assignment operator called!" << std::endl;
		this->data = a.data;
		this->f_data = a.f_data;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	//std::cout << "BitcoinExchange: Destructor called!" << std::endl;
}

void	BitcoinExchange::setData(void)
{
	std::ifstream	ifs("data.csv");
	std::string		date;

	if (!ifs)
		throw ("Error: could not open data file!");
	std::string	str;
	std::getline(ifs, str);
	while (std::getline(ifs, str))
	{
		float	value;
		std::stringstream	ss(str);
		std::getline(ss, date, ',');
		ss >> value;
		this->data.insert(std::make_pair(date, value));
		std::cout << date << ", " << value << std::endl;
	}
}
void	BitcoinExchange::setFdata(void)
{
	if (!file)
		throw("Error: no input file!");
}
