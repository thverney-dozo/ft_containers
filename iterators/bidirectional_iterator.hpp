/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thverney <thverney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:23:31 by thverney          #+#    #+#             */
/*   Updated: 2021/02/05 15:52:49 by thverney         ###   ########.fr       */
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

			bidirec_iterator(non_const_pointer val = 0) : _ptr(val) {}


		s default-constructible, copy-constructible, copy-assignable and destructible	X a;
		X b(a);
		b = a;
		a == b
		a != b
		*a
		a->m
		*a = t
		++a
		a++
		*a++
		--a
		a--
		*a--
		protected:
			nonConstPointer	_ptr;
	};
}

#endif