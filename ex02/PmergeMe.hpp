/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:20:21 by ssadiki           #+#    #+#             */
/*   Updated: 2023/04/03 00:38:44 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#define PMERGEME_H
# include <iostream>
# include <vector>
# include <deque>
# include <ctime>
# include <string>

class PmergeMe{
	std::vector<int>	v;
	std::deque<int>		d;
	PmergeMe ();
public:
	PmergeMe (const PmergeMe &a);
	PmergeMe& operator=(const PmergeMe &a);
	~PmergeMe ();
	PmergeMe(int, char**, int);
	const std::vector<int>&	getVector(void) const;
	const std::deque<int>&	getDeque(void) const;
	void	startVector();
	void	startDeque();
	template<typename C>
		void	insertSort(C& arr, int s, int e)
		{
			for (int i = s; i < e; i++)
			{
				for (int j = i + 1; j > s && arr[j] < arr[j - 1]; j--)
				{
					int	tmp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = tmp;
				}
			}
		}
	template<typename C>
		void	mergeSort(C& arr, int s, int m, int e)
		{
			int	ri = 0;
			int	li = 0;
			while (ri < e - m)
			{
				if (arr[ri + m] > arr[li + s])
					li++;
				else
				{
					int	first = li + s;
					int	middle = ri + m;
					int	last = middle + 1;
					int	next = middle;
					while (first != next)
					{
						int	tmp = arr[first];
						arr[first++] = arr[next];
						arr[next++] = tmp;
						if (next == last)
							next = middle;
						else if (first == middle)
							middle = next;
					}
					ri++;
				}
			}
		}
	template<typename C>
		void	mergeinsertSort(C& arr, int s, int e)
		{
			if (e - s <= 13)
				insertSort(arr, s, e);
			else
			{
				int	m = s + (e - s) / 2;
				mergeinsertSort(arr, s, m);
				mergeinsertSort(arr, m, e);
				mergeSort(arr, s, m, e);
			}
		}
};

#endif
