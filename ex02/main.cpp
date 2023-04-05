/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:19:21 by ssadiki           #+#    #+#             */
/*   Updated: 2023/04/02 23:19:22 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (std::cout << "Error" << std::endl, 1);
	try
	{
		{
			clock_t	t, t1;

			t = clock();
			PmergeMe	pm(argc, argv, 1);
			pm.startVector();
			t1 = clock() - t;
			std::cout << "Before:	";
			for (int i = 1; i < argc; i++)
				std::cout << argv[i] << " ";
			std::cout << std::endl;
			std::vector<int>	v = pm.getVector();
			std::cout << "After:	";
			for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
			std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " <<(((float) t1) / CLOCKS_PER_SEC) * 1000 << " us." << std::endl;
		}
		{
			clock_t	t, t1;

			t = clock();
			PmergeMe	pm(argc, argv, 2);
			pm.startDeque();
			t1 = clock() - t;
			std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " <<(((float) t1) / CLOCKS_PER_SEC) * 1000 << " us." << std::endl;
		}

	}
	catch (const char*  str)
	{
		std::cout << str << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
