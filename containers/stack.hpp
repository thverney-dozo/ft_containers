/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:47:16 by thverney          #+#    #+#             */
/*   Updated: 2021/02/17 04:07:42 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{

		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		protected:
			container_type c;
		
		public:

		    // CAPACITY
            size_type size(void)        const   { return (c.size()); };
			bool empty() 				const	{ return c.empty(); };
            value_type& top()					{ return c.back(); }
			const value_type& top()     const	{ return c.back(); }
			void push (const value_type& val)	{ c.push_back(val); }
			void pop()							{ c.pop_back(); }

		/*		 ██████╗ ██████╗ ██████╗ ██╗     ██╗███████╗███╗   ██╗    ███████╗ ██████╗ ██████╗ ███╗   ███╗
				██╔════╝██╔═══██╗██╔══██╗██║     ██║██╔════╝████╗  ██║    ██╔════╝██╔═══██╗██╔══██╗████╗ ████║
				██║     ██║   ██║██████╔╝██║     ██║█████╗  ██╔██╗ ██║    █████╗  ██║   ██║██████╔╝██╔████╔██║
				██║     ██║   ██║██╔═══╝ ██║     ██║██╔══╝  ██║╚██╗██║    ██╔══╝  ██║   ██║██╔══██╗██║╚██╔╝██║
				╚██████╗╚██████╔╝██║     ███████╗██║███████╗██║ ╚████║    ██║     ╚██████╔╝██║  ██║██║ ╚═╝ ██║
				 ╚═════╝ ╚═════╝ ╚═╝     ╚══════╝╚═╝╚══════╝╚═╝  ╚═══╝    ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝                                                                  
        */
		public:
			// Default constructor
			explicit stack(const container_type &cont = container_type())
			: c(cont)
			{};
			// Copy constructor
			stack(const stack &cpy) { *this = cpy; };
			// Affectation overload
			stack &operator=(const stack &affect)
			{
				this->c = affect.c;
				return (*this);
			};
			// destructor
			~stack() {};
        
	        friend bool operator==(const stack& a, const stack& b)	{ return a.c == b.c; }
			friend bool operator!=(const stack& a, const stack& b)	{ return a.c != b.c; }
			friend bool operator<(const stack& a, const stack& b)	{ return a.c < b.c; }
			friend bool operator<=(const stack& a, const stack& b)	{ return a.c <= b.c; }
			friend bool operator>(const stack& a, const stack& b)	{ return a.c > b.c; }
			friend bool operator>=(const stack& a, const stack& b)	{ return a.c >= b.c; }
	};
}

#endif