/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:24:30 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/19 18:27:16 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H
#include <iostream>
#include <list>
#include <deque>
#include <string>

class PmergeMe{
	
	public:
		PmergeMe ();
		 PmergeMe (const PmergeMe &a);
		 PmergeMe & operator = (const PmergeMe &a);
		 ~PmergeMe ();
};

#endif

