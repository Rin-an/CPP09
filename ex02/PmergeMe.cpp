/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:25:21 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/21 20:35:24 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	//std::cout << "PmergeMe: Default constructor called!" << std::endl;
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

void	PmergeMe::setList(int x)
{
	this->l.push_back(x);
}

void	PmergeMe::setDeque(int x)
{
	this->d.push_back(x);
}

int	PmergeMe::to_int(const std::string& str)
{ 
	unsigned long	i = 0;
	int	r = 0;

	if (str.empty())
		throw ("Error");
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		throw ("Error");
	if (str[i] == '+')
		i++;
	while (i < str.size())
	{
		if (str[i] < '0' || str[i] > '9')
			throw("Error");
		i++;
	}
	std::stringstream(str) >> r;
	return (r);
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
	//	s = l.size();
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
	for (unsigned long i = 0; i < tmp_d1.size() - 1; i++)
	{
		int	tmp = tmp_d1[i];
		if (tmp_d1[i] >= tmp_d1[i + 1])
		{
			tmp_d1[i] = tmp_d1[i + 1];
			tmp_d1[i + 1] = tmp;	
		}
	}
}

void	PmergeMe::mergeQueusort(void)
{
	unsigned long	s;

	while (!d.empty())
		d.pop_back();
/*	l.merge(a);
	for (std::list<int>::iterator it = b.begin(); it != b.end(); ++it)
	{
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
		s = l.size();
	}*/
	d.assign(tmp_d1.begin(), tmp_d1.end());
	for (std::deque<int>::iterator it = tmp_d2.begin(); it != tmp_d2.end(); ++it)
	{
		s = d.size();
		std::cout << "--------------------------" << std::endl;
		std::cout << "Insert: " << *it << std::endl;
		for (std::deque<int>::iterator it2 = d.begin(); it2 != d.end();)
		{
			if (*it >= *it2++ && *it <= *(it2))
			{
				d.insert(it2, *it);
				break;
			}
		}
		std::cout << "s = " << s << ", new size = " << d.size() << std::endl;
		if (s == d.size())
		{
			std::cout << "did it get here" << std::endl;
			if (*it >= d.back())
				d.insert(d.end(), *it);
			else if (*it <= d.front())
				d.insert(d.begin(), *it);
		}
	//	s = d.size();
		for (unsigned long i = 0; i < d.size(); i++)
		{
			std::cout << d[i] << " " << std::endl;
		}
	}
}
