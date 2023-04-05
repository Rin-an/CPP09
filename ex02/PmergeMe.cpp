/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:19:19 by ssadiki           #+#    #+#             */
/*   Updated: 2023/04/02 23:28:08 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe ()
{
//	std::cout << "PmergeMe: Default constructor called!" << std::endl;
}

PmergeMe::PmergeMe (const PmergeMe &a)
{
//	std::cout << "PmergeMe: Copy constructor called!" << std::endl;
	*this = a;
}

PmergeMe & PmergeMe::operator = (const PmergeMe &a)
{
	if (this != &a){
//		std::cout << "PmergeMe: Copy assignment operator called!" << std::endl;
		this->v = a.v;
		this->d = a.d;
	}
	return (*this);
}

PmergeMe::~PmergeMe ()
{
	//std::cout << "PmergeMe: Destructor called!" << std::endl;
}

PmergeMe::PmergeMe(int argc, char **argv, int choice)
{
	for (int i = 1; i < argc; i++)
	{
		int j = 0;
		if (strcmp(argv[i],"") == 0)
			throw ("Error");
		while (argv[i][j])
		{
			if (!isdigit(argv[i][j++]))
				throw ("Error");
		}
	}	
	for (int i = 1; i < argc; i++)
	{
		long n = std::strtol(argv[i], NULL, 10);
		if (n < 0 || n > INT_MAX)
			throw ("Error");
		if (choice == 1)
			v.push_back(n);
		else
			d.push_back(n);
	}
}

const std::vector<int>&	PmergeMe::getVector(void) const
{
	return (this->v);
}

const std::deque<int>&	PmergeMe::getDeque(void) const
{
	return (this->d);
}

void	PmergeMe::startVector(void)
{
	if (v.size() < 2)
		throw ("Nothing to sort");
	mergeinsertSort(v, 0, v.size() - 1);
}

void	PmergeMe::startDeque(void)
{
	if (d.size() < 2)
		throw ("Nothing to sort");
	mergeinsertSort(d, 0, d.size() - 1);
}
