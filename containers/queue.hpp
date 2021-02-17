/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 12:47:12 by thverney          #+#    #+#             */
/*   Updated: 2021/02/17 04:07:11 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class queue
	{
        public:
            typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;
        protected:
			container_type c;
        public:
            // default constructor
            explicit queue (const container_type& cont = container_type()) :
					c(cont) {}
            // Copy constructor
            queue(const queue &cpy) { *this = cpy; };
            // Affectation
            queue &operator=(const queue &affect)
			{
				this->c = affect.c;
				return (*this);
			};
            // Destructor
			~queue() {};

            bool empty()                    const { return (c.empty()); };
			size_type size()                const { return (c.size()); };
			value_type &front()                   { return (c.front()); };
			const value_type &front()       const { return (c.front()); };
			value_type &back()                    { return (c.back()); };
			const value_type &back()        const { return (c.back()); };
			void push(const value_type &val)      { return (c.push_back(val)); };
			void pop()                            { c.pop_front(); };

            friend bool operator==(const queue& a, const queue& b)	{ return a.c == b.c; }
			friend bool operator!=(const queue& a, const queue& b)	{ return a.c != b.c; }
			friend bool operator<(const queue& a, const queue& b)	{ return a.c < b.c; }
			friend bool operator<=(const queue& a, const queue& b)	{ return a.c <= b.c; }
			friend bool operator>(const queue& a, const queue& b)	{ return a.c > b.c; }
			friend bool operator>=(const queue& a, const queue& b)	{ return a.c >= b.c; }
    };
};

#endif
