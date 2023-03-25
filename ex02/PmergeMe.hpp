/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:24:30 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/25 14:12:53 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H
#include <iostream>
#include <iomanip>
#include <list>
#include <deque>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>

class PmergeMe{
	std::vector<int>	arr;
	std::list<int>		l;
	std::list<int>		a;
	std::list<int>		b;
	std::deque<int>		d;
	std::deque<int>		tmp_d1;
	std::deque<int>		tmp_d2;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& a);
		PmergeMe(std::vector<std::string>&);
		PmergeMe& operator=(const PmergeMe& a);
		~PmergeMe();
		const std::list<int>&	getList(void) const;
		const std::deque<int>&	getDeque(void) const;
		void					setList(void);
		void					setDeque(void);
		void					insertSort(void);
		void					mergeSort(void);
		void					insertQueusort(void);
		void					mergeQueusort(void);
};

#endif

