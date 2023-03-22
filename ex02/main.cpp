/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:23:22 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/21 20:35:12 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (std::cout << "Error" << std::endl, 1);
	PmergeMe	pm;
	std::string	str;
	clock_t		t;
	{
		std::list<int>	l;
		std::list<int>	l_tmp;
		clock_t		t1;

		try {	
			t = clock();
			for (int i = 1; i < argc; i++)
			{
				str = argv[i];
				int x = pm.to_int(str);
				pm.setList(x);
				str.clear();
			}
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
		catch (const char* str)
		{
			std::cout << str << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::deque<int>	d;
		std::deque<int>	tmp;
		clock_t		t1;

		try {
			t = clock();
			for (int i = 1; i < argc; i++)
			{
				str = argv[i];
				int x = pm.to_int(str);
				pm.setDeque(x);
			}
			tmp = pm.getDeque();
			pm.insertQueusort();
			pm.mergeQueusort();
			t1 = clock() - t;
			d = pm.getDeque();
			std::cout << "Before: ";
			for (std::deque<int>::iterator it = tmp.begin(); it != tmp.end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
			std::cout << "After: ";
			for (std::deque<int>::iterator it = d.begin(); it != d.end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
			std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << (((float) t1) / CLOCKS_PER_SEC) * 1000 << " us." << std::endl;

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
}
