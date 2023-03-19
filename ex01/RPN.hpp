/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssadiki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:30:17 by ssadiki           #+#    #+#             */
/*   Updated: 2023/03/19 17:44:41 by ssadiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H
#include <stack>
#include <iostream>
#include <string>

class RPN{
	std::stack<int>	s;
	int				r;
	public:
	    RPN ();
	    RPN (const RPN &a);
	    RPN& operator=(const RPN &a);
	    ~RPN ();
		void				setStack(const int&);
		const std::stack<int>&	getStack(void) const;
		int					getResult(void) const;
		bool				isOperator(char) const;
		bool				isNumber(char) const;
		void				execute(std::string&);
		void				executeOperation(char);
};

#endif

