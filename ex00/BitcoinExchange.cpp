/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:58:30 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/19 13:07:46 by ssadiki          ###   ########.fr       */
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

void	BitcoinExchange::setDate(const std::string& date)
{
	this->date.push_back(date);
}

const std::vector<std::string>&	BitcoinExchange::getDate(void) const
{
	return (this->date);
}

void	BitcoinExchange::setValue(const std::string& value)
{
	this->value.push_back(value);
}

void	BitcoinExchange::setData(const std::string& data)
{
	this->data.push_back(data);
}

const std::vector<std::string>&	BitcoinExchange::getValue(void) const
{
	return (this->value);
}

int	BitcoinExchange::to_int(const std::string& str)
{
	unsigned long	i = 0;
	int	r = 0;

	if (str.empty())
		throw ("Error: value not valid!");
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		throw ("Error: value is negative!");
	if (str[i] == '+')
		i++;
	while (i < str.size())
	{
		if (str[i] < '0' || str[i] > '9')
			throw ("Error: value not valid!");
		i++;
	}
	std::istringstream(str) >> r;
	if (r > 1000)
		throw ("Error: value out of range!");
	return (r);
}

float	BitcoinExchange::to_float(const std::string& str)
{
	unsigned long		i = 0;
	float	r = 0;

	if (str.empty())
		throw ("Error: value not valid!");
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		throw ("Error: value is negative!");
	if (str[i] == '+')
		i++;
	while (i < str.size())
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
			throw ("Error: value not valid!");
		i++;
	}
	std::stringstream(str) >> r;
	if (r > 1000)
		throw ("Error: value out of range!");
	return (r);
}
