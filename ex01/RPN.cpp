/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:30:44 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/25 13:55:29 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN ()
{
    //std::cout << "RPN: Default constructor called!" << std::endl;
}

RPN::RPN (const RPN& a)
{
    //std::cout << "RPN: Copy constructor called!" << std::endl;
	*this = a;
}

RPN& RPN::operator=(const RPN& a)
{
    if (this != &a){
     //   std::cout << "RPN: Copy assignment operator called!" << std::endl;
		this->s = a.s;
    }
	return (*this);
}

RPN::~RPN ()
{
   // std::cout << "RPN: Destructor called!" << std::endl;
}

void	RPN::setStack(const int& x)
{
	this->s.push(x);
}

const std::stack<int>&	RPN::getStack(void) const
{
	return (this->s);
}

int	RPN::getResult(void) const
{
	return (this->r);
}

bool	RPN::isOperator(char c) const
{
	if (c == '/' || c== '+' || c == '-' || c == '*')
		return (true);
	else
		return (false);
}

bool	RPN::isNumber(char c) const
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

void	RPN::executeOperation(char op)
{
	int	nb;

	if (s.empty())
		throw ("Error");
	nb = s.top();
	s.pop();
	if (op == '+')
		r = s.top() + nb;
	else if (op == '-')
		r = s.top() - nb;
	else if (op == '*')
		r = s.top() * nb;
	else
		r = s.top() / nb;
	s.pop();
	s.push(r);
}

void	RPN::execute(std::string& str)
{
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
		if (*it == ' ') {}
		else if (isNumber(*it) && (*(it + 1) == ' ' || *(it + 1) == 0))
			s.push(*it - '0');
		else if (isOperator(*it) && (*(it + 1) == ' ' || *(it + 1) == 0))
			executeOperation(*it);
		else
			throw("Error");
	}
}
