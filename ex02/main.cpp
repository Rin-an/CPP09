/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:23:22 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/25 12:21:16 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (std::cout << "Error" << std::endl, 1);
	std::cout << CLOCKS_PER_SEC << std::endl;
	try
	{
		std::vector<std::string>	arr;
		arr.assign(argv + 1, argv + argc);
		PmergeMe	pm(arr);
		{
			clock_t		t, t1;
			std::list<int>	l, l_tmp;

			t = clock();
			pm.setList();
			l_tmp = pm.getList();
			pm.insertSort();
			pm.mergeSort();
			l = pm.getList();
			t1 = clock() - t;
			std::cout << "Before:	";
			for (std::list<int>::iterator it = l_tmp.begin(); it != l_tmp.end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
			std::cout << "After:	";
			for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
			std::cout << "Time to process a range of " << argc - 1 << " elements with std::list : " << (((float) t1) / CLOCKS_PER_SEC) * 1000 << " us." << std::endl;
		}
		{
			std::deque<int>	d;
			clock_t		t, t1;

			t = clock();
			pm.setDeque();
			pm.insertQueusort();
			pm.mergeQueusort();
			t1 = clock() - t;
			std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << (((float) t1) / CLOCKS_PER_SEC) * 1000 << " us." << std::endl;
		}
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
