/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_random_access_iterator.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:23:36 by thverney          #+#    #+#             */
/*   Updated: 2021/02/09 01:32:49 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1

#ifndef REV_RANDOM_ACCESS_ITERATOR_HPP
# define REV_RANDOM_ACCESS_ITERATOR_HPP

# include "reverse_bidirectional_iterator.hpp"
# include "random_access_iterator.hpp"

namespace ft
{
    template<typename T, bool B>
	class rev_random_access_iterator : public reverse_bidirectional_iterator<T, B>
	{
		public:
            typedef typename ft::reverse_bidirectional_iterator<T, B>::difference_type	    difference_type;
			typedef typename ft::reverse_bidirectional_iterator<T, B>::value_type			value_type;
			typedef typename ft::reverse_bidirectional_iterator<T, B>::size_type			size_type;
			
			typedef typename ft::reverse_bidirectional_iterator<T, B>::reference			reference;
			typedef typename ft::reverse_bidirectional_iterator<T, B>::pointer			    pointer;
			typedef typename ft::reverse_bidirectional_iterator<T, B>::non_const_pointer	non_const_pointer;
        	typedef typename ft::reverse_bidirectional_iterator<T, B>						reverse_bidirectional_iterator;

            rev_random_access_iterator(non_const_pointer val = 0) : reverse_bidirectional_iterator(val) {}
            rev_random_access_iterator(const rev_random_access_iterator<T, false>& cpy) : 
                                reverse_bidirectional_iterator(cpy.getNConstPtr()) {};
            rev_random_access_iterator& operator=(const rev_random_access_iterator& affect)
            {
                if (this != &affect)
                    reverse_bidirectional_iterator::_ptr = affect._ptr;
                return (*this);
            }
            ~rev_random_access_iterator() {}
            
            bool operator<(const rev_random_access_iterator& it) const  { return (it._ptr > this->_ptr);  }
            bool operator>(const rev_random_access_iterator& it) const	{ return (it._ptr < this->_ptr);  }
            bool operator<=(const rev_random_access_iterator& it) const	{ return (it._ptr >= this->_ptr); }
            bool operator>=(const rev_random_access_iterator& it) const	{ return (it._ptr <= this->_ptr); }

            rev_random_access_iterator& operator+=(int nb)
			{ cursor(this->_ptr, nb, PLUS); return (*this); }

			rev_random_access_iterator operator+(int nb) const
			{ rev_random_access_iterator it(*this); cursor(it._ptr, nb, PLUS); return (it); }
            
			rev_random_access_iterator& operator-=(int nb)
			{ cursor(this->_ptr, nb, MINUS); return (*this); }
            
			rev_random_access_iterator operator-(int nb) const
			{ rev_random_access_iterator it(*this); cursor(it._ptr, nb, MINUS); return (it); }
            
            reference operator[](int nb) const
            { value_type* tmp(this->_ptr); cursor(tmp, nb, PLUS); return (*tmp); }


            // maybe this proto friend rev_random_access_iterator operator+(int nb, const rev_random_access_iterator& it)
            friend rev_random_access_iterator operator+(int nb, const rev_random_access_iterator& it)
			{ rev_random_access_iterator newIt(it); return (newIt += nb); }

			// maybe this protorev_random_access_iterator operator-(int nb, const rev_random_access_iterator& it)
			friend rev_random_access_iterator operator-(int nb, const rev_random_access_iterator& it)
			{ rev_random_access_iterator newIt(it); return (newIt -= nb); }

        private:

            void cursor(non_const_pointer& val, long nb, bool sign) const
            {
                int shift;

                if (sign == PLUS)
                    shift = nb > 0 ? shift = -1: shift = 1;
                else
                    shift = nb > 0 ? shift = 1: shift = -1;
                if (nb < 0)
                    nb *= -1;
                for (; nb > 0; --nb)
                    val += shift;
            }

    };
}

#endif