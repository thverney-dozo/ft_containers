/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:23:31 by thverney          #+#    #+#             */
/*   Updated: 2021/02/08 16:21:32 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include "is_const_it.hpp"

namespace ft
{
	template<typename T, bool B>
	class bidirectional_iterator
	{
		public:

			typedef long int		difference_type;
			typedef T				value_type;
			typedef size_t			size_type;

			typedef typename is_it_const<B, T&, const T&>::_type		reference;
			typedef typename is_it_const<B, T*, const T*>::_type		pointer;
			typedef T*													non_const_pointer;

			bidirectional_iterator(non_const_pointer val = 0) : _ptr(val) {}


		s default-constructible, copy-constructible, copy-assignable and destructible	X a;
		~bidirectional_iterator() {}

		X b(a);
		b = a;
		// bool operator==(const bidirectional_iterator& it) const	{ return (it._ptr == _ptr); }
		// bool operator!=(const bidirectional_iterator& it) const	{ return (it._ptr != _ptr); }
		*a
		a->m
		*a = t
		bidirectional_iterator& operator++()		{ ++_ptr; return (*this); }
		bidirectional_iterator operator++(int)		{ bidirectional_iterator ret(*this); ++(*this); return (ret); };
		bidirectional_iterator& operator--()		{ --_ptr; return (*this); }
		bidirectional_iterator operator--(int)		{ bidirectional_iterator ret(*this); --(*this); return (ret); };
		protected:
			nonConstPointer	_ptr;
	};
}

#endif