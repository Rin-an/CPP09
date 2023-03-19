/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:29:03 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/19 17:47:34 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Error." << std::endl, 1);
	RPN	rpn;
	try {
		std::string	exp = argv[1];
		rpn.execute(exp);
		std::cout << rpn.getResult() << std::endl;
	}
	catch (const char* str)
	{
		std::cout << str << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
