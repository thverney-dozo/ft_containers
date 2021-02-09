/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:23:34 by thverney          #+#    #+#             */
/*   Updated: 2021/02/09 01:33:13 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "bidirectional_iterator.hpp"

# define PLUS 1
# define MINUS 0

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

            random_access_iterator& operator+=(int nb)
			{ cursor(this->_ptr, nb, PLUS); return (*this); }

			random_access_iterator operator+(int nb) const
			{ random_access_iterator it(*this); cursor(it._ptr, nb, PLUS); return (it); }
            
			random_access_iterator& operator-=(int nb)
			{ cursor(this->_ptr, nb, MINUS); return (*this); }
            
			random_access_iterator operator-(int nb) const
			{ random_access_iterator it(*this); cursor(it._ptr, nb, MINUS); return (it); }
            
            reference operator[](int nb) const
            { value_type* tmp(this->_ptr); cursor(tmp, nb, PLUS); return (*tmp); }


            // maybe this proto friend random_access_iterator operator+(int nb, const random_access_iterator& it)
            friend random_access_iterator operator+(int nb, const random_access_iterator& it)
			{ random_access_iterator newIt(it); return (newIt += nb); }

			// maybe this protorandom_access_iterator operator-(int nb, const random_access_iterator& it)
			friend random_access_iterator operator-(int nb, const random_access_iterator& it)
			{ random_access_iterator newIt(it); return (newIt -= nb); }

        private:

            void cursor(non_const_pointer& val, long nb, bool sign) const
            {
                int shift;

                if (sign == PLUS)
                    shift = nb > 0 ? shift = 1: shift = -1;
                else
                    shift = nb > 0 ? shift = -1: shift = 1;
                if (nb < 0)
                    nb *= -1;
                for (; nb > 0; --nb)
                    val += shift;
            }

    };
}

#endif