/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:12:09 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/25 10:42:21 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}	
	try {
		BitcoinExchange		bc(argv[1]);
		bc.setData();
		bc.parse();
	}
	catch (const char* str)
	{
		std::cout << str << std::endl;
	}
	catch (std::string& str)
	{
		std::cout << str << std::endl;
	}
	return (0);
}
