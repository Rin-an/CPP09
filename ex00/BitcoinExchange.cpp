/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:58:30 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/28 10:57:06 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	//	std::cout << "BitcoinExchange: Default constructor called!" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string file)
{
	setFile(file);
	setData();
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
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	//std::cout << "BitcoinExchange: Destructor called!" << std::endl;
}

void	BitcoinExchange::setFile(const std::string str)
{
	file.open(str);
	if (!file)
		throw("Error: could not open input file.");
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
		double	value;
		std::stringstream	ss(str);
		std::getline(ss, date, ',');
		ss >> value;
		this->data[date] = value;
	}
	ifs.close();
}

void	BitcoinExchange::parse(void)
{
	if (!file.is_open())
		throw("Error: no input file!");
	struct tm	tm;
	std::string	str;
	std::getline(file, str);
	if (str.compare("date | value") != 0)
		throw ("Error: wrong formatting.");
	while (std::getline(file, str))
	{
		if (str.empty()) {std::cout << "Error: empty line." << std::endl;}
		else if (str.find('|') == std::string::npos || str.find('|') != str.rfind('|'))
			std::cout << "Error: wrong content/delimiter!" << std::endl;
		else
		{
			std::string			date;
			double				value;
			std::stringstream	ss(str);
			std::getline(ss, date, '|');
			if (!strptime(date.c_str(), "%Y-%m-%d", &tm) || tm.tm_year <= -901)
				std::cout << "Error: date is not valid => " + date << std::endl;
			else if ((str.substr(str.find('|') + 1)).empty())
				std::cout << "Error : no value." << std::endl;
			else
			{
				ss >> value;
				if (value < 0)
					std::cout << "Error: negative value." << std::endl;
				else if (value > 1000)
					std::cout << "Error: value out of limit." << std::endl;
				else
					exchangeRate(date, value);
			}
			ss.clear();
		}
	}
	file.close();
}

void	BitcoinExchange::exchangeRate(std::string& date, double value)
{
	(void)value;
	std::map<std::string, double>::iterator	it = data.lower_bound(date);
	
	if (it != data.begin())
		--it;
	std::cout << std::setprecision(15) << date << "=> " << value << " = " << value * (*it).second << std::endl;
}
