/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:25:21 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/25 14:14:12 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	//std::cout << "PmergeMe: Default constructor called!" << std::endl;
}

PmergeMe::PmergeMe(std::vector<std::string>& ar)
{
	for (std::vector<std::string>::iterator it = ar.begin(); it != ar.end(); ++it)
	{
		long n = std::strtol((*it).c_str(), NULL, 10);
		if (n < 0)
			throw ("Error");
		arr.push_back(n);
	}
}

PmergeMe::PmergeMe(const PmergeMe& a)
{
	//std::cout << "PmergeMe: Copy constructor called!" << std::endl;i
	*this = a;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& a)
{
	if (this != &a)
	{
		//	std::cout << "PmergeMe: Copy assignment operator called!" << std::endl;
		this->arr = a.arr;
		this->l = a.l;
		this->a = a.a;
		this->b = a.b;
		this->d = a.d;
		this->tmp_d1 = a.tmp_d1;
		this->tmp_d2 = a.tmp_d2;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	//	std::cout << "PmergeMe: Destructor called!" << std::endl;
}

const std::list<int>&	PmergeMe::getList(void) const
{
	return (this->l);
}

const std::deque<int>&	PmergeMe::getDeque(void) const
{
	return (this->d);
}

void	PmergeMe::setList(void)
{
	for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)	
		this->l.push_back(*it);
}

void	PmergeMe::setDeque(void)
{
	for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)	
		this->d.push_back(*it);
}

void	PmergeMe::insertSort(void)
{
	std::list<int>::iterator	tmp;

	if (l.size() % 2 != 0)
	{
		b.push_back(l.back());
		l.pop_back();
	}
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		tmp = it;
		if (*tmp < *(++it))
		{
			a.push_back(*tmp);
			b.push_back(*it);
		}
		else
		{
			b.push_back(*tmp);
			a.push_back(*it);
		}
	}
	if (b.size() != a.size())
	{
		b.push_back(b.front());
		b.pop_front();
	}
	a.sort();
}

void	PmergeMe::mergeSort(void)
{
	unsigned long	s;

	while (!l.empty())
		l.pop_back();
	l.merge(a);
	for (std::list<int>::iterator it = b.begin(); it != b.end(); ++it)
	{
		s = l.size();
		for (std::list<int>::iterator it2 = l.begin(); it2 != l.end();)
		{
			if (*it >= *it2++ && *it <= *(it2))
			{
				l.insert(it2, *it);
				break;
			}
		}
		if (s == l.size())
		{
			if (*it >= l.back())
				l.insert(l.end(), *it);
			else if (*it <= l.front())
				l.insert(l.begin(), *it);
		}
	}
}

void	PmergeMe::insertQueusort(void)
{
	if (d.size() % 2 != 0)
	{
		tmp_d2.push_back(d.back());
		d.pop_back();
	}
	for (unsigned long i = 0; i < d.size(); i += 2)
	{
		if (d[i] < d[i + 1])
		{
			tmp_d1.push_back(d[i]);
			tmp_d2.push_back(d[i + 1]);
		}
		else
		{
			tmp_d1.push_back(d[i + 1]);
			tmp_d2.push_back(d[i]);
		}
	}
	if (tmp_d2.size() != tmp_d1.size())
	{
		tmp_d2.push_back(tmp_d2.front());
		tmp_d2.pop_front();	
	}
	std::sort(tmp_d1.begin(), tmp_d1.end());
}

void	PmergeMe::mergeQueusort(void)
{
	unsigned long	s;

	while (!d.empty())
		d.pop_back();
	d.assign(tmp_d1.begin(), tmp_d1.end());
	for (std::deque<int>::iterator it = tmp_d2.begin(); it != tmp_d2.end(); ++it)
	{
		s = d.size();
		for (std::deque<int>::iterator it2 = d.begin(); it2 != d.end();)
		{
			if (*it >= *it2++ && *it <= *(it2))
			{
				d.insert(it2, *it);
				break;
			}
		}
		if (s == d.size())
		{
			if (*it >= d.back())
				d.insert(d.end(), *it);
			else if (*it <= d.front())
				d.insert(d.begin(), *it);
		}
	}
}
