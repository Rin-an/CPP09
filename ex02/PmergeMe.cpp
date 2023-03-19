/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:25:21 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/19 18:25:48 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe ()
{
    std::cout << "PmergeMe: Default constructor called!" << std::endl;
}

PmergeMe::PmergeMe (const PmergeMe &a)
{
    std::cout << "PmergeMe: Copy constructor called!" << std::endl;
}

PmergeMe & PmergeMe::operator = (const PmergeMe &a)
{
    if (this != &a){
        std::cout << "PmergeMe: Copy assignment operator called!" << std::endl;
    }
}

PmergeMe::~PmergeMe ()
{
    std::cout << "PmergeMe: Destructor called!" << std::endl;
}

