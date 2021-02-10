/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bidirectional_iterator.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeoithd <aeoithd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:23:38 by thverney          #+#    #+#             */
/*   Updated: 2021/02/10 16:28:25 by aeoithd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 0

#ifndef REVERSE_BIDIRECTIONAL_ITERATOR_HPP
# define REVERSE_BIDIRECTIONAL_ITERATOR_HPP

# include "is_const_it.hpp"
# include "bidirectional_iterator.hpp"

namespace ft
{
	template<typename T, bool B>
	class reverse_bidirectional_iterator
	{
		public:

			typedef long int		difference_type;
			typedef T				value_type;
			typedef size_t			size_type;

			typedef typename choose_if_const<B, T&, const T&>::_type	reference;
			typedef typename choose_if_const<B, T*, const T*>::_type	pointer;
			typedef T*													non_const_pointer;
			typedef std::input_iterator_tag 							iterator_category;


			reverse_bidirectional_iterator(non_const_pointer val = 0) : _ptr(val) {}
            reverse_bidirectional_iterator(const reverse_bidirectional_iterator<T, false>& cpy) { _ptr = cpy.getNConstPtr(); }
			reverse_bidirectional_iterator(const bidirectional_iterator<T, false>& cpy) { _ptr = cpy.getNConstPtr(); }
			reverse_bidirectional_iterator& operator=(const reverse_bidirectional_iterator& affect)
			{
				if (this != &affect)
					_ptr = affect._ptr;
				return (*this);
			}
			~reverse_bidirectional_iterator() {}
			
			non_const_pointer	getNConstPtr() const						{ return _ptr; }
			bool operator==(const reverse_bidirectional_iterator& it) const	{ return (it._ptr == _ptr); }
			bool operator!=(const reverse_bidirectional_iterator& it) const	{ return (it._ptr != _ptr); }
			reference operator*()									{ return (*_ptr); }
			pointer operator->() const								{ return (_ptr); }
			reverse_bidirectional_iterator& operator++()					{ --_ptr; return (*this); }
			reverse_bidirectional_iterator operator++(int)					{ reverse_bidirectional_iterator ret(*this); ++(*this); return (ret); }
			reverse_bidirectional_iterator& operator--()					{ ++_ptr; return (*this); }
			reverse_bidirectional_iterator operator--(int)					{ reverse_bidirectional_iterator ret(*this); --(*this); return (ret); }
			
		protected:
			non_const_pointer	_ptr;
	};
}

#endif