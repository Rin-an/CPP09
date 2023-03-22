/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:12:09 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/22 16:20:49 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*void	exchange_rate(BitcoinExchange& bc)
{
	std::vector<std::string>	v = bc.getValue();
	std::vector<std::string>	d = bc.getDate();
	std::ifstream	data;
	int		i;
	float	f;

	data.open("data.csv");
	if (!data)
		throw("Could not open data file!");
	for (std::string str; std::getline(data,str) ;)
		bc.setData(str);
	for (unsigned long x = 0; x < d.size(); x++)
	{
		try {
			if (v[x].find('.') != std::string::npos)
			{
				if (v[x].find('.') != v[x].rfind('.'))
					throw ("Error : value not valid!");
				f = bc.to_float(v[x]);
				std::cout << bc.calculateBitcoin(f) << std::endl;
			}
			else
			{
				i = bc.to_int(v[x]);
				std::cout << bc.calculateBitcoin(i) << std::endl;
			}
		}
		catch (const char *str)
		{
			std::cout << str << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}*/

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	BitcoinExchange		bc;
//	std::ifstream		ifs;
//	std::string 		date;
//	std::string 		value;
//	struct tm			tm;

	bc.setData();
//	ifs.open(argv[1]);
//	if (!ifs)
//		return (std::cout << "Error: could not open file!" << std::endl, 1);
//	for (std::string str ; std::getline(ifs, str); )
//	{
//		try {
//			if (str.find('|') == std::string::npos || str.find('|') != str.rfind('|'))
//				throw ("Error: wrong content/delimiter!");
//			date.assign(str, 0, str.find('|'));
//			if (!strptime(date.c_str(), "%Y-%m-%d", &tm) || tm.tm_year <= -901)
//				throw ("Error: date is not valid => " + date);
//			bc.setDate(date);
//			value.assign(str, str.find('|') + 1, str.size());
//			bc.setValue(value);
//	//		std::cout << date << "|" << value << std::endl;
//		}
//		catch (const char* str)
//		{
//			std::cout << str << std::endl;
//		}
//		catch (std::string& str)
//		{
//			std::cout << str << std::endl;
//		}
//		catch (std::exception& e)
//		{
//			std::cout << e.what() << std::endl;
//		}
//	}
//	if (date.empty() || value.empty())
//		return (std::cout << "Error: date and/or value empty!" << std::endl, 1);
//	try {
//		exchange_rate(bc);
//	}
//	catch (const char* str)
//	{
//		std::cout << str << std::endl;
//	}
	return (0);
}
