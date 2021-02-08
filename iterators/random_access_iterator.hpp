/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:23:34 by thverney          #+#    #+#             */
/*   Updated: 2021/02/08 22:14:11 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "bidirectional_iterator.hpp"


namespace ft
{
	template<typename T, bool B>
	class random_access_iterator : public bidirectional_iterator<T, B>
	{
		public:
            typedef typename ft::bidirectional_iterator<T, B>::difference_type	    difference_type;
			typedef typename ft::bidirectional_iterator<T, B>::value_type			value_type;
			typedef typename ft::bidirectional_iterator<T, B>::size_type			size_type;
			
			typedef typename ft::bidirectional_iterator<T, B>::reference			reference;
			typedef typename ft::bidirectional_iterator<T, B>::pointer			    pointer;
			typedef typename ft::bidirectional_iterator<T, B>::non_const_pointer	non_const_pointer;
        	typedef typename ft::bidirectional_iterator<T, B>						bidirectional_iterator;

        random_access_iterator(non_const_pointer val = 0) : bidirectional_iterator(val) {}
        random_access_iterator(const random_access_iterator<T, false>& cpy) : 
                            bidirectional_iterator(cpy.getNConstPtr()) {};
        random_access_iterator& operator=(const random_access_iterator& affect)
		{
			if (this != &affect)
				bidirectional_iterator::_ptr = affect._ptr;
			return (*this);
		}
        ~random_access_iterator() {}
        
        bool operator<(const random_access_iterator& it) const  { return (it._ptr > this->_ptr);  }
		bool operator>(const random_access_iterator& it) const	{ return (it._ptr < this->_ptr);  }
		bool operator<=(const random_access_iterator& it) const	{ return (it._ptr >= this->_ptr); }
        bool operator>=(const random_access_iterator& it) const	{ return (it._ptr <= this->_ptr); }


        
    };
}

#endif