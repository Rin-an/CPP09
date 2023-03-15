/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:58:30 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/15 12:00:35 by ssadiki          ###   ########.fr       */
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
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &a)
{
    if (this != &a)
	{
        std::cout << "BitcoinExchange: Copy assignment operator called!" << std::endl;
    }
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "BitcoinExchange: Destructor called!" << std::endl;
}

