/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:12:09 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/18 20:16:29 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*int	main(int argc, char **argv)
{
	(void)argc;
	std::ifstream		ifs;
	char date[20];
	std::string value;
	int		i;
	float	f;
	struct tm	tm;

	ifs.open(argv[1]);
	if (!ifs)
		return (std::cout << "Error: could not open file!" << std::endl, 1);
	for (std::string str ; std::getline(ifs, str); )
	{
		try
		{
			if (str.find('|') == std::string::npos || str.find('|') != str.rfind('|'))
				throw ("Error: wrong content/delimiter!");
			str.copy(date, str.find('|'), 0);
			value.assign(str, str.find('|') + 1, str.size());
			if (!strptime(date, "%Y-%m-%d", &tm) || tm.tm_year <= -901)
				throw ("Error: date is not valid!");
			if (value.find('.') != std::string::npos)
			{
				if (value.find('.') != value.rfind('.'))
					throw ("Error : value not valid!");
				f = stof(value);
				if (f < 0)
					throw ("Error: value is negative!");
				else if (f > 1000)
					throw ("Error: value out of range!");
			}
			else
			{
				i = stoi(value);
				if (i < 0)
					throw ("Error: value is negative!");
				else if (i > 1000)
					throw ("Error: value out of range!");
			}
			std::cout << date << "|" << value << std::endl;
		}
		catch (const char* str)
		{
			std::cout << str << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}*/

int	main(int argc, char **argv)
{
	(void)argc;
	BitcoinExchange		bc;
	std::ifstream		ifs;
	std::string 		date;
	std::string 		value;
	struct tm			tm;
	int		i;
	float	f;

	ifs.open(argv[1]);
	if (!ifs)
		return (std::cout << "Error: could not open file!" << std::endl, 1);
	for (std::string str ; std::getline(ifs, str); )
	{
		try
		{
			if (str.find('|') == std::string::npos || str.find('|') != str.rfind('|'))
				throw ("Error: wrong content/delimiter!");
			date.assign(str, 0, str.find('|'));
				if (!strptime(date.c_str(), "%Y-%m-%d", &tm) || tm.tm_year <= -901)
				throw ("Error: date is not valid!");
			bc.setDate(date);
			value.assign(str, str.find('|') + 1, str.size());
			bc.setValue(value);
		}
		catch (const char* str)
		{
			std::cout << str << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	if (value.find('.') != std::string::npos)
			{
				if (value.find('.') != value.rfind('.'))
					throw ("Error : value not valid!");
				f = bc.to_float(*value);
				if (f < 0)
					throw ("Error: value is negative!");
				else if (f > 1000)
					throw ("Error: value out of range!");
			}
			else
			{
				i = stoi(value);
				if (i < 0)
					throw ("Error: value is negative!");
				else if (i > 1000)
					throw ("Error: value out of range!");
			}

	if (date.empty() || value.empty())
		std::cout << "Error: file is empty!" << std::endl;
	(void)i;
	(void)f;
	return (0);
}
