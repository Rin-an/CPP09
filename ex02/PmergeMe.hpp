/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:24:30 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/21 17:32:55 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H
#include <iostream>
#include <iomanip>
#include <list>
#include <deque>
#include <string>
#include <sstream>
#include <ctime>

class PmergeMe{
	std::list<int>	l;
	std::list<int>	a;
	std::list<int>	b;
	std::deque<int>	d;
	std::deque<int>	tmp_d1;
	std::deque<int>	tmp_d2;
	public:
		PmergeMe();
		 PmergeMe(const PmergeMe& a);
		 PmergeMe& operator=(const PmergeMe& a);
		 ~PmergeMe();
		 const std::list<int>&	getList(void) const;
		 const std::deque<int>&	getDeque(void) const;
		 void					setList(int);
		 void					setDeque(int);
		 int					to_int(const std::string&);
		 void					insertSort(void);
		 void					mergeSort(void);
		 void					insertQueusort(void);
		 void					mergeQueusort(void);
};

#endif

